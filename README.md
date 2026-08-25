# leetcode-primer

算法与面试题学习仓库，收录 LeetCode、剑指 Offer、常用算法模板和工程练习。源码以 C++ 为主，统一使用 `.cc` 后缀；部分并发和工具示例使用 Go、Python 或 Lua。

## 内容导航

| 目录 | 内容 | 入口 |
| --- | --- | --- |
| [`leetcode/`](leetcode/) | LeetCode 题解、按专题归档的笔记与源码。 | [题目索引](leetcode/README.md) |
| [`剑指offer/`](剑指offer/) | 《剑指 Offer》66 题实现，源码位于 `src/`，文件名为 `offerN.cc`。 | [题目说明](剑指offer/README.md) |
| [`其它常见的题目/`](其它常见的题目/) | 面试高频题、算法模板、数据结构设计与并发练习；源码位于平铺的 `src/`。 | [目录索引](其它常见的题目/README.md) |
| [`template/`](template/) | 数学、区间查询、动态规划和图论学习笔记；相关源码链接至“其它常见的题目”。 | [模板导航](template/README.md) |

## 快速开始

这是一个题解与模板仓库，而非统一构建的应用。多数 C++ 文件可以独立编译；根据题目所需补充输入、测试代码或在线评测的 `Solution` 包装即可。

```bash
# 编译单个 C++ 示例
c++ -std=c++17 -Wall -Wextra 其它常见的题目/src/graph_zero_one_bfs.cc -c
```

## 目录约定

- LeetCode 源码位于 `leetcode/src/`，大部分文件对应 `leetcode<题号>.cc`。
- 剑指 Offer 源码位于 `剑指offer/src/`，不再保留中间 `cpp/` 层级。
- “其它常见的题目”的源码位于平铺的 `src/`；文件使用小写英文 `snake_case`，例如 `graph_dijkstra.cc`、`string_kmp.cc`、`concurrency_h2o.go`。
- `template/` 只保留 Markdown 学习模板；对应的可编译源码统一放在“其它常见的题目”。

## 当前规模

- LeetCode：`leetcode/src/` 中 275 个 C++ 源码文件。
- 剑指 Offer：66 个 C++ 题解文件。
- 其它常见题目：79 个多语言源码/头文件，覆盖图论、字符串、区间查询、动态规划、数据结构、设计模式与并发。

## 使用提示

- 部分文件是可复用模板，部分是单题实现或学习草稿；编译前请查看文件内的依赖与入口。
- 同一主题可能保留多种实现，用于比较不同思路；优先以各目录 README 的说明为准。
- 提交新的非 LeetCode 题目时，请遵循“主题前缀 + `snake_case`”命名，并同步更新对应目录的 README。
