# 题目笔记模板

同一道题可能出现在多个索引中，但它只有一个本地事实来源：当前仓库中的源码文件。

## 规范表格

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| [1. 两数之和](https://leetcode.cn/problems/two-sum) | Easy | 哈希查找 | 保存已见过的值，并在插入当前值前检查它的补数。 | [1_two_sum.cc](../leetcode/数据结构运用/1_two_sum.cc) | `new` |

## 使用规则

- 按照这个精确顺序保留表格列。
- 在 `Problem` 中填写题目标题，并链接到公开题面。
- 在 `Source` 中填写本地实现文件。
- 仓库尚无本地实现时，优先由 `guides/indexes/leetcode-problems.md` 承载 LeetCode 原题链接。
- 使用 `Review` 作为所有索引和 README 更新共同读取的状态字段。
- 不要为同一道题在多个本地文件中重复维护事实来源。
