#!/usr/bin/env python3
"""Check the repository's Markdown problem-list conventions."""

from __future__ import annotations

import argparse
import re
import sys
from collections import Counter
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, List, Optional


PROBLEM_LABEL = re.compile(r"^(?:\d+|LCR|面试题|剑指 Offer|DQUERY)\b")
MARKDOWN_LINK = re.compile(r"\[[^\]]*\]\(([^)]+)\)")
PROBLEM_LINK = re.compile(r"^- \[([^\]]+)\]\(([^)]+)\)")
INDEX_PROBLEM = re.compile(r"^\| (?:\[(\d+)\.|LeetCode (\d+)\b|(\d+)\.)")
LOCAL_PROBLEM = re.compile(r"^(\d+)_.*\.(?:cc|go|lua|py|sql)$")
SOURCE_SUFFIXES = {".cc", ".go", ".hpp", ".lua", ".py", ".sql"}
PUBLIC_PROBLEM_INDEXES = (
    "problems-by-topic.md",
    "problems-by-pattern.md",
    "problems-by-difficulty.md",
    "problems-by-source.md",
)
CANONICAL_CATEGORIES = (
    "基础算法",
    "数据结构",
    "数学",
    "搜索",
    "动态规划",
    "图论",
)
CANONICAL_TEMPLATES = tuple(
    f"{index}-{name}.md"
    for index, name in enumerate(CANONICAL_CATEGORIES, 1)
)
CROSS_TOPIC_TEMPLATES = (
    "专题-区间查询与统计.md",
    "专题-路径问题.md",
)


def markdown_files(root: Path) -> Iterable[Path]:
    for path in root.rglob("*.md"):
        if ".git" not in path.parts and ".agents" not in path.parts:
            yield path


def lines_without_code(path: Path) -> Iterable[tuple[int, str]]:
    in_code = False
    for line_number, line in enumerate(
        path.read_text(encoding="utf-8").splitlines(), 1
    ):
        if line.strip().startswith("```"):
            in_code = not in_code
            continue
        if not in_code:
            yield line_number, line


def problem_id(label: str) -> Optional[int]:
    match = re.match(r"^(\d+)", label)
    return int(match.group(1)) if match else None


def extract_problem_counts(path: Path) -> dict[int, int]:
    counts: Counter[int] = Counter()
    for _, line in lines_without_code(path):
        match = PROBLEM_LINK.match(line)
        if match and problem_id(match.group(1)) is not None:
            counts[problem_id(match.group(1))] += 1
    return dict(counts)


def extract_index_problem_ids(path: Path) -> set[int]:
    identifiers: set[int] = set()
    for _, line in lines_without_code(path):
        match = INDEX_PROBLEM.match(line)
        if match:
            identifiers.add(int(next(group for group in match.groups() if group)))
    return identifiers


def extract_local_problem_ids(root: Path) -> set[int]:
    identifiers: set[int] = set()
    source_root = root / "leetcode"
    if not source_root.exists():
        return identifiers
    for path in source_root.rglob("*"):
        if not path.is_file():
            continue
        match = LOCAL_PROBLEM.match(path.name)
        if match:
            identifiers.add(int(match.group(1)))
    return identifiers


def validate_problem_index_coverage(
    root: Path, readme: Path, index: Path
) -> List[str]:
    expected = set(extract_problem_counts(readme)) | extract_local_problem_ids(root)
    actual = extract_index_problem_ids(index)
    errors: List[str] = []
    missing = sorted(expected - actual)
    if missing:
        errors.append(f"{index}:完整索引缺少题号：{missing}")
    return errors


def validate_index_source_identity(root: Path, index: Path) -> List[str]:
    errors: List[str] = []
    leetcode_root = (root / "leetcode").resolve()
    for line_number, line in lines_without_code(index):
        label = INDEX_PROBLEM.match(line)
        if not label:
            continue
        label_id = int(next(group for group in label.groups() if group))
        for target in MARKDOWN_LINK.findall(line):
            if target.startswith(("http://", "https://", "mailto:")):
                continue
            target = target.split("#", 1)[0].split("?", 1)[0].strip("<>")
            resolved = (index.parent / target).resolve()
            try:
                relative = resolved.relative_to(leetcode_root)
            except ValueError:
                continue
            source = LOCAL_PROBLEM.match(relative.name)
            if source and int(source.group(1)) != label_id:
                errors.append(
                    f"{index}:{line_number}:题号与源码文件名不一致：{target}"
                )
    return errors


@dataclass(frozen=True)
class RepositoryStatistics:
    leetcode_sources: int
    leetcode_languages: tuple[str, ...]
    offer_sources: int
    other_sources: int
    readme_problems: int
    local_only_problems: int
    index_only_problems: int
    all_problems: int


def _source_files(directory: Path) -> List[Path]:
    if not directory.exists():
        return []
    return [
        path
        for path in directory.rglob("*")
        if path.is_file() and path.suffix in SOURCE_SUFFIXES
    ]


def repository_statistics(root: Path, readme: Path) -> RepositoryStatistics:
    leetcode_sources = _source_files(root / "leetcode")
    language_names = {
        ".cc": "C++",
        ".go": "Go",
        ".lua": "Lua",
        ".py": "Python",
        ".sql": "SQL",
    }
    languages = tuple(
        language_names[suffix]
        for suffix in (".cc", ".sql", ".go", ".py", ".lua")
        if any(path.suffix == suffix for path in leetcode_sources)
    )
    readme_ids = set(extract_problem_counts(readme))
    local_ids = extract_local_problem_ids(root)
    index_path = root / "guides/indexes/leetcode-problems.md"
    index_ids = extract_index_problem_ids(index_path) if index_path.exists() else set()
    expected_ids = readme_ids | local_ids
    return RepositoryStatistics(
        leetcode_sources=len(leetcode_sources),
        leetcode_languages=languages,
        offer_sources=len(_source_files(root / "剑指offer")),
        other_sources=len(_source_files(root / "其它常见的题目")),
        readme_problems=len(readme_ids),
        local_only_problems=len(local_ids - readme_ids),
        index_only_problems=len(index_ids - expected_ids),
        all_problems=len(expected_ids | index_ids),
    )


def _language_phrase(languages: tuple[str, ...]) -> str:
    if not languages:
        return "无"
    if len(languages) == 1:
        return languages[0]
    return "、".join(languages[:-1]) + " 与 " + languages[-1]


def validate_documented_statistics(root: Path, readme: Path) -> List[str]:
    statistics = repository_statistics(root, readme)
    errors: List[str] = []
    home = root / "README.md"
    index = root / "guides/indexes/leetcode-problems.md"
    home_text = home.read_text(encoding="utf-8") if home.exists() else ""
    index_text = index.read_text(encoding="utf-8") if index.exists() else ""
    expected_home = (
        f"- LeetCode：{statistics.leetcode_sources} 个源码文件，覆盖 "
        f"{_language_phrase(statistics.leetcode_languages)}。"
    )
    if expected_home not in home_text:
        errors.append(f"{home}:首页 LeetCode 源码统计不一致，期望：{expected_home}")
    expected_offer = f"- 剑指 Offer：{statistics.offer_sources} 个 C++ 题解文件。"
    if expected_offer not in home_text:
        errors.append(f"{home}:首页剑指 Offer 源码统计不一致，期望：{expected_offer}")
    expected_other = (
        f"- 其它常见题目：{statistics.other_sources} 个多语言源码/头文件，"
        "覆盖图论、字符串、区间查询、动态规划、数据结构、设计模式与并发。"
    )
    if expected_other not in home_text:
        errors.append(f"{home}:首页其它题目源码统计不一致，期望：{expected_other}")
    expected_problem_total = (
        f"- 完整 LeetCode 题单：{statistics.all_problems} 道去重题目，其中包含 "
        f"{statistics.local_only_problems} 道未进入 README 题单的本地源码题和 "
        f"{statistics.index_only_problems} 道扩展题目。"
    )
    if expected_problem_total not in home_text:
        errors.append(f"{home}:首页完整题单统计不一致，期望：{expected_problem_total}")
    expected_index = (
        f"README 题单共 {statistics.readme_problems} 个唯一题目；仓库另有 "
        f"{statistics.local_only_problems} 个未进入 README 的本地源码题；"
        f"索引另收录 {statistics.index_only_problems} 个扩展题目，合计 "
        f"{statistics.all_problems} 条。"
    )
    if expected_index not in index_text:
        errors.append(f"{index}:完整索引统计不一致，期望：{expected_index}")
    return errors


def validate_readme(path: Path, baseline: Optional[Path] = None) -> List[str]:
    errors: List[str] = []
    headings: dict[str, List[int]] = {}
    current_section = "(before first section)"

    for line_number, line in lines_without_code(path):
        if line.startswith("## "):
            current_section = line[3:].strip()
            headings.setdefault(current_section, [])
            continue

        heading = re.match(r"^### (\d+)\.", line)
        if heading:
            headings.setdefault(current_section, []).append(int(heading.group(1)))

        match = PROBLEM_LINK.match(line)
        if not match or not PROBLEM_LABEL.match(match.group(1)):
            continue

        if re.match(r"^\d+\s*[/、,]\s*\d+", match.group(1)):
            errors.append(f"{path}:{line_number}:题目行一行包含多个题号")
        links = MARKDOWN_LINK.findall(line)
        if len(links) != 1:
            errors.append(f"{path}:{line_number}:题目行包含多个链接")
        if "【" not in line or "】" not in line:
            errors.append(f"{path}:{line_number}:题目行缺少【关键点】")

    for section, numbers in headings.items():
        if not numbers:
            continue
        expected = list(range(1, max(numbers) + 1))
        if numbers != expected:
            errors.append(
                f"{path}:{section}:标题编号不连续，实际 {numbers}，期望 {expected}"
            )

    if baseline is not None:
        old = extract_problem_counts(baseline)
        new = extract_problem_counts(path)
        removed = sorted(set(old) - set(new))
        decreased = sorted(
            problem for problem in set(old) & set(new) if new[problem] < old[problem]
        )
        if removed:
            errors.append(f"{path}:题号集合减少：{removed}")
        if decreased:
            errors.append(f"{path}:题号出现次数减少：{decreased}")

    return errors


def validate_local_links(root: Path) -> List[str]:
    errors: List[str] = []
    for path in markdown_files(root):
        for line_number, line in lines_without_code(path):
            for target in MARKDOWN_LINK.findall(line):
                target = target.split("#", 1)[0].split("?", 1)[0].strip("<>")
                if not target or target.startswith(("http://", "https://", "mailto:")):
                    continue
                if any(character.isspace() for character in target):
                    continue
                if not (path.parent / target).resolve().exists():
                    errors.append(f"{path}:{line_number}:本地链接不存在：{target}")
    return errors


def validate_url_style(root: Path) -> List[str]:
    errors: List[str] = []
    for path in markdown_files(root):
        for line_number, line in lines_without_code(path):
            if "leetcode-cn.com" in line:
                errors.append(f"{path}:{line_number}:使用旧域名 leetcode-cn.com")
            if re.search(r"https://leetcode\.cn(?![/?#\s)])", line):
                errors.append(f"{path}:{line_number}:LeetCode 链接路径异常")
            if re.search(
                r"https://leetcode\.cn/problems/[^)\s]+/(?:description|submissions)",
                line,
            ):
                errors.append(f"{path}:{line_number}:LeetCode 链接包含异常路径")
            if re.search(r"https://leetcode\.cn/problems/[^)\s/]+/\)?", line):
                errors.append(f"{path}:{line_number}:LeetCode 题目链接不应以 / 结尾")
    return errors


def validate_public_indexes_have_no_review_state(root: Path) -> List[str]:
    """Reject user-specific review progress in committed classification indexes."""
    errors: List[str] = []
    index_root = root / "guides/indexes"
    review_state = re.compile(r"`(?:new|review|mastered|mistake)`")
    for name in PUBLIC_PROBLEM_INDEXES:
        path = index_root / name
        if not path.exists():
            continue
        for line_number, line in lines_without_code(path):
            if line.startswith("|") and (
                "| Review |" in line or review_state.search(line)
            ):
                errors.append(
                    f"{path}:{line_number}:公共索引不应包含个人复习状态"
                )
    return errors


def validate_taxonomy_structure(root: Path) -> List[str]:
    errors: List[str] = []
    leetcode_root = root / "leetcode"
    if leetcode_root.exists():
        actual = {
            path.name for path in leetcode_root.iterdir() if path.is_dir()
        }
        expected = set(CANONICAL_CATEGORIES)
        if actual != expected:
            errors.append(
                f"{leetcode_root}:一级分类目录不一致：实际 {sorted(actual)}，"
                f"期望 {sorted(expected)}"
            )
        simulation = leetcode_root / "基础算法" / "模拟"
        if actual == expected and not simulation.is_dir():
            errors.append(f"{simulation}:基础算法缺少模拟二级目录")

    template_root = root / "template"
    if template_root.exists():
        expected_templates = set(CANONICAL_TEMPLATES + CROSS_TOPIC_TEMPLATES)
        actual_templates = {
            path.name
            for path in template_root.glob("*.md")
            if path.name != "README.md"
        }
        if actual_templates != expected_templates:
            errors.append(
                f"{template_root}:模板文件不一致：实际 {sorted(actual_templates)}，"
                f"期望 {sorted(expected_templates)}"
            )

    readme = leetcode_root / "README.md"
    if readme.exists():
        headings = []
        for _, line in lines_without_code(readme):
            match = re.match(r"^## (\d+)\. (.+)$", line)
            if match:
                headings.append((int(match.group(1)), match.group(2)))
        expected_headings = list(enumerate(CANONICAL_CATEGORIES, 1))
        if headings != expected_headings:
            errors.append(
                f"{readme}:README 主分类不一致：实际 {headings}，"
                f"期望 {expected_headings}"
            )
    return errors


def validate_template_titles(root: Path) -> List[str]:
    errors: List[str] = []
    for filename, category in zip(CANONICAL_TEMPLATES, CANONICAL_CATEGORIES):
        path = root / "template" / filename
        if not path.exists():
            continue
        headings = [
            line[2:].strip()
            for _, line in lines_without_code(path)
            if line.startswith("# ")
        ]
        expected = f"{category}专题复习手册"
        if headings != [expected]:
            errors.append(
                f"{path}:一级标题不一致：实际 {headings}，期望 [{expected}]"
            )
    return errors


def main(argv: Optional[List[str]] = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path("."))
    parser.add_argument("--readme", type=Path, default=None)
    parser.add_argument("--baseline", type=Path, default=None)
    args = parser.parse_args(argv)

    root = args.root.resolve()
    readme = (args.readme or root / "leetcode/README.md").resolve()
    index = root / "guides/indexes/leetcode-problems.md"
    baseline = args.baseline.resolve() if args.baseline else None
    errors = []
    errors.extend(validate_readme(readme, baseline))
    errors.extend(validate_local_links(root))
    errors.extend(validate_url_style(root))
    errors.extend(validate_public_indexes_have_no_review_state(root))
    errors.extend(validate_taxonomy_structure(root))
    errors.extend(validate_template_titles(root))
    errors.extend(validate_problem_index_coverage(root, readme, index))
    errors.extend(validate_index_source_identity(root, index))
    errors.extend(validate_documented_statistics(root, readme))

    if errors:
        for error in errors:
            print(f"ERROR: {error}")
        print(f"检查失败：{len(errors)} 个问题")
        return 1

    print("Markdown consistency check passed.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
