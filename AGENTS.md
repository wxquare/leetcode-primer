# Agent Workspace Rules

## Scope

This file is the authoritative instruction entry point for agents working in
this repository. The `.agents/` directory is reserved for agent-only temporary
state, local configuration, isolated Git worktrees, SDD ledgers, review
packages, and migrated historical temporary artifacts. It must not contain
reviewable work products.

## Temporary Work Products

All agent-created temporary artifacts, local Git worktrees, ledgers, review
packages, and migrated historical temporary artifacts belong under `.agents/`.
Do not create new agent temporary content under `work/`, `docs/`, source
directories, or the repository root. `work/` is ignored by Git and is not a
reviewable work-product location.

## Worktree Location

All agent-created Git worktrees must be placed under `.agents/worktrees/`.
This directory is local-only and must remain ignored by Git. The
`.agents/worktrees/` exception does not change the temporary-artifact rule:
these worktrees are local-only and ignored by Git.

## Historical Temporary Artifacts

Migrated historical `docs/superpowers/` temporary artifacts belong under
`.agents/docs/superpowers/`. Do not create new agent temporary content under
`docs/` or any retired legacy path.

## Language Requirements

Repository-facing documentation should match the surrounding content language.
If no language is specified, use Chinese for reader-facing documentation and
English for technical execution details.

## File Conventions

- Use ISO dates in file names: `YYYY-MM-DD-topic-name.md`.
- Keep one document as the canonical source for each deliverable; link to it
  instead of creating copies.
- Use Markdown for text work products unless another format is explicitly
  required.

## 学习专题文档分层

- `leetcode/README.md` 负责导航、粗粒度分类和完整题单；不在这里堆放完整推导、长表格或重复模板。
- `template/*.md` 负责专题的系统学习：问题识别、核心思想、可复用 C++ 模板、复杂度、易错点和复习安排，不替代 README 的完整题单职责。
- 每个主要专题以 7 天为一个复习闭环：先建立模型，再覆盖模板和变体，最后进行混合练习、盲写和错题回收。子分类可以跨天安排，但不重复创建另一套周期。
- 一个专题只保留一个详细模板作为学习内容的权威来源；README 是完整题单的权威入口，索引文件通过链接引用，避免知识说明在多个文件中漂移。
- 题单整理时每行只放一个题目，并在题目右侧使用 `【关键点/解题思路】` 标识该题的主要考点或解法。
- 题单整理遵循保守原则：不得删除、遗漏或减少原有题目；允许补充题目、调整分类、拆分同一行中的多个题目和统一格式，但整理前后必须核对原有条目仍全部保留。
- 专题一级分类使用连续数字编号，二级分类使用 `1.1`、`1.2` 等数字编号；解释性文字、模板说明和复习表不强制添加 `【】`。
- README 与 template 的职责调整不得导致 README 题号集合减少；题目移动或重新归类后，必须核对整理前后的题号集合和数量。
