# 04 面试冲刺

[路线入口](00-start-here.md) / [核心模式](02-core-patterns.md) / [高级专题](03-advanced-topics.md) / [复习方法](../review-method.md)

两周冲刺只做四件事：限时练习、错题复盘、模板召回、重做 `mistake` 项。每晚按 [复习方法](../review-method.md) 更新本地个人记录；`mistake` 题重新从 1 天复习节奏开始，不能直接回到 `review` 或 `mastered`。

## 冲刺规则

- 每天至少一组 45 分钟限时题，结束后立即写错误原因。
- 每天 20 分钟模板召回：不看源码写出接口、循环边界和复杂度。
- 每天重做前一天或本周标记为 `mistake` 的题，直到能独立讲清思路。
- 每三天做一次混合题组，避免只按专题记忆答案。

## 第一周

| 天数 | 限时练习 | 错题复盘 | 模板召回 | 重做 `mistake` 项 |
| --- | --- | --- | --- | --- |
| 1 | [数组](01-foundations.md#arrays) + [双指针](02-core-patterns.md#two-pointers) | 记录审题遗漏、边界漏判和变量不变量。 | 原地数组、快慢指针、对撞指针。 | 重做数组与双指针错题。 |
| 2 | [字符串](01-foundations.md#strings) + [滑动窗口](02-core-patterns.md#sliding-windows) | 区分固定窗口、可变窗口和频次哈希。 | 字符频次数组、窗口收缩条件。 | 重做字符串窗口 `mistake`。 |
| 3 | [栈](02-core-patterns.md#stacks) + [队列](02-core-patterns.md#queues) | 检查栈顶含义、队列层数和单调结构出队条件。 | 单调栈、单调队列、广度优先搜索层序。 | 重做栈、队列、广度优先搜索错题。 |
| 4 | [链表](01-foundations.md#linked-lists) + [树](01-foundations.md#trees) | 记录空指针、递归返回值和父子关系错误。 | 链表反转、树遍历、最近公共祖先基础。 | 重做链表和树 `mistake`。 |
| 5 | [深度优先搜索 / 回溯](02-core-patterns.md#dfs--backtracking) + [广度优先搜索](02-core-patterns.md#bfs) | 比较搜索状态、visited 语义和剪枝条件。 | 回溯框架、网格搜索、队列扩散。 | 重做搜索错题。 |
| 6 | [贪心方法](02-core-patterns.md#greedy-methods) + [前缀和](02-core-patterns.md#prefix-sums) | 写出贪心证明或前缀状态定义。 | 排序贪心、区间合并、前缀和哈希。 | 重做贪心与前缀和错题。 |
| 7 | 基础与模式混合练习 | 汇总一周所有 `mistake` 的共同原因。 | 口述本周所有模板。 | 重做仍未通过的 `mistake`，重新排入 1 -> 3 -> 7 -> 14 天节奏。 |

## 第二周

| 天数 | 限时练习 | 错题复盘 | 模板召回 | 重做 `mistake` 项 |
| --- | --- | --- | --- | --- |
| 8 | [基础动态规划](02-core-patterns.md#basic-dynamic-programming) | 检查状态定义、初始化和转移方向。 | 线性动态规划、选择/不选择、最长递增子序列。 | 重做动态规划基础错题。 |
| 9 | [图论](03-advanced-topics.md#graphs) | 检查建图、入度、连通性和最短路边权假设。 | 广度优先搜索、Dijkstra、拓扑排序、并查集。 | 重做图论 `mistake`。 |
| 10 | [区间数据结构](03-advanced-topics.md#interval-data-structures) | 检查下标、闭区间/半开区间和离散化映射。 | 树状数组、线段树、差分数组。 | 重做区间结构错题。 |
| 11 | [字符串算法](03-advanced-topics.md#string-algorithms) | 检查前缀函数、回文半径和 Trie 节点含义。 | KMP、Trie、Manacher、Z 函数。 | 重做字符串算法 `mistake`。 |
| 12 | [高级动态规划](03-advanced-topics.md#advanced-dp) | 检查状态维度、压缩顺序和重复计算。 | 背包、状态压缩、数位动态规划、矩阵快速幂。 | 重做高级动态规划错题。 |
| 13 | [数学方法](03-advanced-topics.md#mathematical-methods) + 混合复盘 | 检查取模、溢出、组合边界和位运算。 | 快速幂、组合数、最大公约数、线性基。 | 重做数学和混合题错题。 |
| 14 | 完整模拟面试题组 | 复盘所有未稳定题，保留下一轮 `review` 队列。 | 白板默写核心模板清单。 | 最后重做全部剩余 `mistake`，没有独立通过的题不得标为 `mastered`。 |

## 出口检查清单

- 限时练习题能写出复杂度、边界和失败样例。
- 所有 `mistake` 都有明确原因：概念缺口、模板不熟、审题错误或实现边界。
- 高频模板能在 10 分钟内从空文件写出可用骨架。
- 面试前一天只做轻量 `review` 和模板召回，不再新增大量 `new` 题。
