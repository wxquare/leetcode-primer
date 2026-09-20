import tempfile
import unittest
from pathlib import Path

from tools.check_markdown_consistency import (
    extract_problem_counts,
    repository_statistics,
    validate_documented_statistics,
    validate_index_source_identity,
    validate_local_links,
    validate_problem_index_coverage,
    validate_public_indexes_have_no_review_state,
    validate_readme,
    validate_taxonomy_structure,
    validate_template_titles,
    validate_url_style,
)


class MarkdownConsistencyTest(unittest.TestCase):
    def write(self, root: Path, name: str, content: str) -> Path:
        path = root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(content, encoding="utf-8")
        return path

    def test_problem_rows_require_one_link_and_key_point(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            readme = self.write(
                root,
                "leetcode/README.md",
                """## 题单
### 1. 数组
- [1. 两数之和](https://leetcode.cn/problems/two-sum)【哈希】
> 知识点：哈希表【按值查找】
- [2. 两数相加](https://leetcode.cn/problems/add-two-numbers)
- [3. 错误题目](https://leetcode.cn/problems/a) 与 [4. 另一个](https://leetcode.cn/problems/b)【错误】
""",
            )
            errors = validate_readme(readme)
            self.assertTrue(any("缺少【关键点】" in error for error in errors))
            self.assertTrue(any("多个链接" in error for error in errors))
            self.assertEqual(extract_problem_counts(readme), {1: 1, 2: 1, 3: 1})

    def test_heading_numbers_must_be_continuous(self):
        with tempfile.TemporaryDirectory() as directory:
            readme = self.write(
                Path(directory),
                "README.md",
                "## 主题\n### 1. 一\n### 3. 三\n",
            )
            errors = validate_readme(readme)
            self.assertTrue(any("编号不连续" in error for error in errors))

    def test_problem_rows_must_not_combine_multiple_numeric_ids(self):
        with tempfile.TemporaryDirectory() as directory:
            readme = self.write(
                Path(directory),
                "README.md",
                "- [112/113. 路径总和](https://leetcode.cn/problems/path-sum)【DFS】\n",
            )
            errors = validate_readme(readme)
            self.assertTrue(any("一行包含多个题号" in error for error in errors))

    def test_baseline_detects_removed_problem_ids(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            baseline = self.write(root, "baseline.md", "- [1. A](x)【a】\n- [2. B](x)【b】\n")
            current = self.write(root, "README.md", "- [1. A](x)【a】\n")
            errors = validate_readme(current, baseline=baseline)
            self.assertTrue(any("题号集合减少" in error for error in errors))

    def test_local_links_and_url_style(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            self.write(root, "target.md", "# target\n")
            readme = self.write(
                root,
                "README.md",
                "- [1. A](target.md)【a】\n"
                "- [2. B](missing.md)【b】\n"
                "- [3. C](https://leetcode-cn.com/problems/c)【c】\n"
                "- [4. D](https://leetcode.cn/problems/d/description/)【d】\n",
            )
            self.assertTrue(any("不存在" in error for error in validate_local_links(root)))
            self.assertTrue(any("旧域名" in error for error in validate_url_style(root)))
            self.assertTrue(any("异常路径" in error for error in validate_url_style(root)))

    def test_problem_index_must_match_readme_and_local_source_union(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            readme = self.write(
                root, "leetcode/README.md", "- [1. A](https://leetcode.cn/problems/a)【a】\n"
            )
            self.write(root, "leetcode/数组/3_c.cc", "// source\n")
            index = self.write(
                root,
                "guides/indexes/leetcode-problems.md",
                "| [2. B](https://leetcode.cn/problems/b) | - |\n",
            )
            errors = validate_problem_index_coverage(root, readme, index)
            self.assertTrue(any("缺少题号：[1, 3]" in error for error in errors))
            self.assertFalse(any("非预期题号" in error for error in errors))

    def test_index_source_link_must_match_row_problem_id(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            self.write(root, "leetcode/数组/2_wrong.cc", "// source\n")
            index = self.write(
                root,
                "guides/indexes/leetcode-problems.md",
                "| [1. A](https://leetcode.cn/problems/a) | "
                "[2_wrong.cc](../../leetcode/数组/2_wrong.cc) |\n",
            )
            errors = validate_index_source_identity(root, index)
            self.assertTrue(any("题号与源码文件名不一致" in error for error in errors))

    def test_repository_statistics_are_computed_from_files_and_sets(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            readme = self.write(
                root, "leetcode/README.md", "- [1. A](https://leetcode.cn/problems/a)【a】\n"
            )
            self.write(root, "leetcode/数组/1_a.cc", "// source\n")
            self.write(root, "leetcode/数组/2_b.sql", "-- source\n")
            self.write(root, "剑指offer/src/offer1_a.cc", "// source\n")
            self.write(root, "其它常见的题目/src/example.go", "package main\n")
            statistics = repository_statistics(root, readme)
            self.assertEqual(statistics.leetcode_sources, 2)
            self.assertEqual(statistics.readme_problems, 1)
            self.assertEqual(statistics.local_only_problems, 1)
            self.assertEqual(statistics.all_problems, 2)

    def test_homepage_statistics_are_optional_but_index_statistics_are_checked(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            readme = self.write(
                root, "leetcode/README.md", "- [1. A](https://leetcode.cn/problems/a)【a】\n"
            )
            self.write(root, "leetcode/数组/1_a.cc", "// source\n")
            self.write(root, "README.md", "- LeetCode：99 个源码文件，覆盖 C++。\n")
            self.write(
                root,
                "guides/indexes/leetcode-problems.md",
                "README 题单共 99 个唯一题目；仓库另有 99 个本地源码题，合计 198 条。\n",
            )
            errors = validate_documented_statistics(root, readme)
            self.assertFalse(any("首页" in error for error in errors))
            self.assertTrue(any("完整索引统计不一致" in error for error in errors))

    def test_public_indexes_must_not_store_personal_review_state(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            self.write(
                root,
                "guides/indexes/problems-by-topic.md",
                "| Problem | Difficulty | Pattern | Key idea | Source | Review |\n"
                "| --- | --- | --- | --- | --- | --- |\n"
                "| 1. 两数之和 | Easy | 哈希 | 记录补数 | source.cc | `new` |\n",
            )
            errors = validate_public_indexes_have_no_review_state(root)
            self.assertTrue(any("个人复习状态" in error for error in errors))

    def test_public_indexes_may_link_to_review_documentation(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            self.write(
                root,
                "guides/indexes/problems-by-topic.md",
                "个人记录可以在本地使用 `review` 状态。\n",
            )
            self.assertEqual(
                validate_public_indexes_have_no_review_state(root), []
            )

    def test_taxonomy_rejects_legacy_directories_and_template_names(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for name in (
                "基础算法",
                "数据结构运用",
                "数学",
                "搜索（非图）",
                "动态规划",
                "图论",
                "模拟",
            ):
                (root / "leetcode" / name).mkdir(parents=True)
            self.write(root, "template/6-基本算法.md", "# 基本算法\n")
            errors = validate_taxonomy_structure(root)
            self.assertTrue(any("一级分类目录" in error for error in errors))
            self.assertTrue(any("模板文件" in error for error in errors))

    def test_taxonomy_rejects_readme_heading_order(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            self.write(
                root,
                "leetcode/README.md",
                "## 1. 数据结构\n## 2. 基础算法\n## 3. 数学\n"
                "## 4. 搜索\n## 5. 动态规划\n## 6. 图论\n",
            )
            errors = validate_taxonomy_structure(root)
            self.assertTrue(any("README 主分类" in error for error in errors))

    def test_numbered_template_title_must_match_filename(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            self.write(root, "template/1-基础算法.md", "# 基本算法专题复习手册\n")
            errors = validate_template_titles(root)
            self.assertTrue(any("一级标题" in error for error in errors))


if __name__ == "__main__":
    unittest.main()
