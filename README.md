# leetcode-primer

一个以 C++ 算法题解为主的学习与复盘仓库，收录 LeetCode、剑指 Offer、算法模板、数据结构实现和少量工程练习。仓库用学习路线、专题模板、题单索引和复习规则组织内容，方便按主题学习、按模式练习，并在本地记录复习进度。LeetCode 目录还包含少量 SQL 题目；通用模板和并发、工具示例另有 Go、Python、Lua 及头文件实现。

## 快速导航

- [学习路线](guides/roadmap/00-start-here.md)：按基础阶段、核心模式、高级专题和面试冲刺组织学习顺序。
- [完整 LeetCode 题单](guides/indexes/leetcode-problems.md)：聚合 `leetcode/README.md` 的题单，并补录仓库中尚未进入题单的本地源码题；没有本地源码时链接 LeetCode 原题。
- [面试高频 Top 100](leetcode/top100.md) / [面试高频 Top 300](leetcode/top300.md)：按常见面试频率整理的重点题单，附主要考点与解题思路。
- [按主题](guides/indexes/problems-by-topic.md) / [按模式](guides/indexes/problems-by-pattern.md) / [按难度](guides/indexes/problems-by-difficulty.md) / [按来源](guides/indexes/problems-by-source.md) / [模板索引](guides/indexes/templates-by-topic.md)：从不同维度查找题解和模板。
- [待整理源码](guides/indexes/experimental-and-unfiled-sources.md)：已保留但尚未完成学习分类的源码、示例与工具。

## 学习与复盘

- [复习方法](guides/review-method.md)：使用 `new`、`review`、`mastered`、`mistake` 和 `1 -> 3 -> 7 -> 14` 天复习节奏；个人进度保存在本地 `.local/reviews/`，不提交到仓库。
- [题目笔记模板](guides/problem-note-template.md)：统一题目笔记与索引字段。
- [命名规范](guides/naming-conventions.md)：统一新增源码文件命名。
- [贡献指南](guides/contribution-guide.md)：新增题目时同步本地 README 与索引。

## 内容目录

| 目录 | 内容 | 入口 |
| --- | --- | --- |
| [`leetcode/`](leetcode/) | LeetCode 题解、按专题归档的题单与源码；这里是本地题解目录的主要入口。 | [题目索引](leetcode/README.md) / [Top 100](leetcode/top100.md) / [Top 300](leetcode/top300.md) |
| [`剑指offer/`](剑指offer/) | 《剑指 Offer》66 题实现，源码位于 `src/`，文件名为 `offerN.cc`。 | [题目说明](剑指offer/README.md) |
| [`其它常见的题目/`](其它常见的题目/) | 面试高频题、算法模板、数据结构实现、设计模式与并发练习；源码位于平铺的 `src/`。 | [目录索引](其它常见的题目/README.md) |
| [`template/`](template/) | 六大分类学习文档，以及区间查询与统计、路径问题两个跨分类专题；可编译源码统一链接至“其它常见的题目”。 | [模板导航](template/README.md) |

## 目录约定

- `guides/` 存放学习路线、完整索引、主题/模式/难度索引、模板索引以及复习和协作规范。
- LeetCode 源码按主要解法归档在 `leetcode/` 下的六个主题目录中；大多数文件使用 `<题号>_<英文简称>.<扩展名>` 命名，LCR 等特殊编号沿用对应命名；模拟题统一位于 `leetcode/基础算法/模拟/`。
- 剑指 Offer 源码位于 `剑指offer/src/`，不再保留中间 `cpp/` 层级。
- “其它常见的题目”的源码位于平铺的 `src/`；文件使用小写英文 `snake_case`，例如 `graph_dijkstra.cc`、`string_kmp.cc`、`concurrency_h2o.go`。
- `template/` 只保留 Markdown 学习模板；对应的可编译源码统一放在“其它常见的题目”。

## LeetCode 源码归类规则

LeetCode 题解按题号和英文简称命名为 `<题号>_<english_slug>.<扩展名>`（特殊编号按对应格式命名），并归入一个主要主题目录。一个题目可能同时涉及多个主题；目录归类按代码中占主导地位的解法决定，索引再提供主题和模式维度的交叉查找：

1. 二分、排序、双指针、滑动窗口、贪心、分治、模拟 → `基础算法`
2. 栈、队列、堆、哈希、链表、树、Trie、区间结构 → `数据结构`
3. 数论、数位、组合、取模、位运算、随机化、几何 → `数学`
4. 非图状态空间的 DFS、BFS、回溯、剪枝、启发式搜索 → `搜索`
5. 状态转移、背包、区间、树形、状态压缩、数位 DP → `动态规划`
6. 图遍历、并查集、拓扑排序、最短路、生成树、匹配、网络流 → `图论`

跨分类内容通过[区间查询与统计](template/专题-区间查询与统计.md)和[路径问题](template/专题-路径问题.md)两个专题串联复习，不新增一级源码目录。

## 当前规模

- LeetCode：677 个源码文件，覆盖 C++ 与 SQL。
- 剑指 Offer：66 个 C++ 题解文件。
- 其它常见题目：79 个多语言源码/头文件，覆盖图论、字符串、区间查询、动态规划、数据结构、设计模式与并发。
- 完整 LeetCode 题单：666 道去重题目，其中包含 141 道未进入 README 题单的本地源码题和 0 道扩展题目。

## 使用建议

- 从 [学习路线](guides/roadmap/00-start-here.md) 开始，再通过 [完整 LeetCode 题单](guides/indexes/leetcode-problems.md) 或主题/模式/难度索引做针对性练习。
- 每个目录的 README 是该目录的事实入口；编译或修改源码前，先阅读对应 README。
- 同一主题可能保留多种实现，用于比较不同思路；优先以各目录 README 的说明为准。
- 新增题目时，同步更新源码、所属目录 README 和对应的索引。
