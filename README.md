# leetcode-primer

算法与面试题学习仓库，收录 LeetCode、剑指 Offer、常用算法模板和工程练习，并通过学习路线、完整索引和复习规则把题解组织成可持续复盘的学习路径。源码以 C++ 为主，统一使用 `.cc` 后缀；部分并发和工具示例使用 Go、Python 或 Lua。

## 快速导航

- [学习路线](guides/roadmap/00-start-here.md)：从基础、核心模式、进阶专题到面试冲刺。
- [完整 LeetCode 题单](guides/indexes/leetcode-problems.md)：覆盖 `leetcode/README.md` 中的题目，并补录仓库中未进入题单的本地源码题；无本地源码时直接链接 LeetCode 原题。
- [按主题](guides/indexes/problems-by-topic.md) / [按模式](guides/indexes/problems-by-pattern.md) / [按难度](guides/indexes/problems-by-difficulty.md) / [按来源](guides/indexes/problems-by-source.md) / [模板索引](guides/indexes/templates-by-topic.md)
- [待整理源码](guides/indexes/experimental-and-unfiled-sources.md)：已保留但尚未完成学习分类的源码、示例与工具。

## 学习与复盘

- [复习方法](guides/review-method.md)：使用 `new`、`review`、`mastered`、`mistake` 和 `1 -> 3 -> 7 -> 14` 天复习节奏。
- [题目笔记模板](guides/problem-note-template.md)：统一题目笔记与索引字段。
- [命名规范](guides/naming-conventions.md)：统一新增源码文件命名。
- [贡献指南](guides/contribution-guide.md)：新增题目时同步本地 README 与索引。

## 内容目录

| 目录 | 内容 | 入口 |
| --- | --- | --- |
| [`leetcode/`](leetcode/) | LeetCode 题解、按专题归档的笔记与源码。 | [题目索引](leetcode/README.md) |
| [`剑指offer/`](剑指offer/) | 《剑指 Offer》66 题实现，源码位于 `src/`，文件名为 `offerN.cc`。 | [题目说明](剑指offer/README.md) |
| [`其它常见的题目/`](其它常见的题目/) | 面试高频题、算法模板、数据结构设计与并发练习；源码位于平铺的 `src/`。 | [目录索引](其它常见的题目/README.md) |
| [`template/`](template/) | 基本算法、数据结构、数学、区间查询、动态规划、图论和搜索学习笔记；相关源码链接至“其它常见的题目”。 | [模板导航](template/README.md) |

## 目录约定

- `guides/` 存放学习路线、完整索引、主题/模式/难度索引、模板索引和协作规范。
- LeetCode 源码按主要解法归档在 `leetcode/` 下的七个主题目录中，文件使用 `<题号>_<英文简称>.<扩展名>` 命名。
- 剑指 Offer 源码位于 `剑指offer/src/`，不再保留中间 `cpp/` 层级。
- “其它常见的题目”的源码位于平铺的 `src/`；文件使用小写英文 `snake_case`，例如 `graph_dijkstra.cc`、`string_kmp.cc`、`concurrency_h2o.go`。
- `template/` 只保留 Markdown 学习模板；对应的可编译源码统一放在“其它常见的题目”。

## LeetCode 源码归类规则

LeetCode 题解按题号和英文简称命名为 `<题号>_<english_slug>.<扩展名>`，并归入一个主要主题目录。涉及多个主题时，按代码中占主导地位的解法归类：

1. 二分答案、排序、双指针、滑动窗口 → `基础算法`
2. DFS、BFS、回溯 → `搜索（非图）`
3. 并查集、最短路、拓扑排序 → `图论`
4. 线段树、树状数组、堆、栈、队列 → `数据结构运用`
5. 数学、数位、组合、取模 → `数学`
6. 字符串模拟、矩阵模拟、设计题 → `模拟`
7. 动态规划、状态转移、记忆化搜索 → `动态规划`

## 当前规模

- LeetCode：304 个源码文件，覆盖 C++ 与 SQL。
- 剑指 Offer：66 个 C++ 题解文件。
- 其它常见题目：79 个多语言源码/头文件，覆盖图论、字符串、区间查询、动态规划、数据结构、设计模式与并发。
- 完整 LeetCode 题单：653 道去重题目，其中包含 158 道未进入 README 题单的本地源码题和 17 道扩展题目。

## 使用建议

- 从 [学习路线](guides/roadmap/00-start-here.md) 开始，再通过 [完整 LeetCode 题单](guides/indexes/leetcode-problems.md) 或主题/模式/难度索引做针对性练习。
- 每个目录的 README 是该目录的事实入口；编译或修改源码前，先阅读对应 README。
- 同一主题可能保留多种实现，用于比较不同思路；优先以各目录 README 的说明为准。
- 新增题目时，同步更新源码、所属目录 README 和对应的索引。
