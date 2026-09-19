# 题目笔记模板

同一道题可能出现在多个索引中，但公共题目元数据只有一个本地事实来源：当前仓库中的源码文件和分类索引。个人复习进度单独保存在 `.local/reviews/`。

## 规范表格

| Problem | Difficulty | Pattern | Key idea | Source |
| --- | --- | --- | --- | --- |
| [1. 两数之和](https://leetcode.cn/problems/two-sum) | Easy | 哈希查找 | 保存已见过的值，并在插入当前值前检查它的补数。 | [1_two_sum.cc](../leetcode/数据结构/1_two_sum.cc) |

## 使用规则

- 按照这个精确顺序保留表格列。
- 在 `Problem` 中填写题目标题，并链接到公开题面。
- 在 `Source` 中填写本地实现文件。
- 仓库尚无本地实现时，优先由 `guides/indexes/leetcode-problems.md` 承载 LeetCode 原题链接。
- 不在公共题目表格中添加 `Review`、下次复习日期或错题原因；这些字段写入个人复习记录。
- 不要为同一道题在多个本地文件中重复维护事实来源。
