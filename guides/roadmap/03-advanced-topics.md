# 03 高级专题

[路线入口](00-start-here.md) / [核心模式](02-core-patterns.md) / [模板导航](../../template/README.md) / [复习方法](../review-method.md)

高级阶段以模板理解和建模能力为主。每个主题先读模板，手写一次核心结构，再做题验证。遇到写法依赖边界条件的题，必须在笔记中记录失败输入和修正点。

<a id="graphs"></a>

## 图论

学习重点：建图方式、遍历状态、拓扑依赖、连通性、最短路、生成树、强连通分量与流网络。

模板与题目：

- [最短路模板合集](../../其它常见的题目/src/graph_shortest_path_algorithms.cc)
- [拓扑排序模板](../../其它常见的题目/src/graph_topological_sort.cc)
- [并查集模板](../../其它常见的题目/src/union_find.cc)
- [Tarjan 强连通分量](../../其它常见的题目/src/tarjan.cc)
- [210. 课程表 II](../../leetcode/src/leetcode210.cc)
- [684. 冗余连接](../../leetcode/数据结构运用/并查集/684.%20冗余连接.cc)

<a id="trees"></a>

## 树

学习重点：树上深度优先搜索信息合并、二叉搜索树性质、最近公共祖先、换根动态规划、树链剖分，以及树题中的递归边界。

模板与题目：

- [最近公共祖先模板](../../其它常见的题目/src/tree_lowest_common_ancestor.cc)
- [树链剖分模板](../../其它常见的题目/src/heavy_light_decomposition.cc)
- [换根动态规划模板](../../其它常见的题目/src/tree_rerooting_dp.cc)
- [236. 二叉树的最近公共祖先](../../leetcode/src/leetcode236.cc)
- [337. 打家劫舍 III](../../leetcode/src/leetcode337.cc)
- [450. 删除二叉搜索树中的节点](../../leetcode/src/leetcode450.cc)

<a id="advanced-dp"></a>

## 高级动态规划

学习重点：背包、状态压缩、区间动态规划、树形动态规划、数位动态规划、矩阵快速幂优化，以及从暴力搜索压缩状态。

模板与题目：

- [背包动态规划模板](../../其它常见的题目/src/dp_knapsack.cc)
- [旅行商问题状态压缩动态规划](../../其它常见的题目/src/traveling_salesman.cc)
- [数位动态规划模板](../../其它常见的题目/src/dp_digit.cc)
- [矩阵快速幂模板](../../其它常见的题目/src/matrix_exponentiation.cc)
- [600. 不含连续 1 的非负整数](../../leetcode/src/leetcode600.cc)
- [2407. 最长递增子序列 II](../../leetcode/src/leetcode2407.cc)

<a id="interval-data-structures"></a>

## 区间数据结构

学习重点：前缀和、差分、树状数组、线段树、主席树、ST 表的适用边界，以及离散化后的索引语义。

模板与题目：

- [区间查询教学文档](../../template/2-区间查询与统计.md)
- [树状数组模板](../../其它常见的题目/src/fenwick_tree.cc)
- [线段树模板](../../其它常见的题目/src/segment_tree.cc)
- [主席树模板](../../其它常见的题目/src/persistent_segment_tree.cc)
- [307. 区域和检索 - 数组可修改](../../leetcode/src/leetcode307.cc)
- [218. 天际线问题](../../leetcode/数据结构运用/线段树/218.%20天际线问题.cc)

<a id="string-algorithms"></a>

## 字符串算法

学习重点：KMP、Trie、AC 自动机、Manacher、Z 函数，以及字符串算法与动态规划、图搜索的组合。

模板与题目：

- [字符串算法合集](../../其它常见的题目/src/string_algorithms.cc)
- [KMP 模板](../../其它常见的题目/src/string_kmp_template.cc)
- [Trie 模板](../../其它常见的题目/src/trie.cc)
- [Manacher 模板](../../其它常见的题目/src/manacher.cc)
- [Z 函数模板](../../其它常见的题目/src/z_function.cc)
- [2851. 字符串 K 次转换等于目标串的方案数量](../../leetcode/动态规划/2851.%20字符串K次转换等于目标串的方案数量.cc)

<a id="mathematical-methods"></a>

## 数学方法

学习重点：快速幂、组合数、取模、质数筛、最大公约数、随机采样、位运算和线性递推。

模板与题目：

- [数学算法合集](../../其它常见的题目/src/math_algorithms.cc)
- [组合数学与取模](../../leetcode/数学/组合数学与取模.md)
- [线性基模板](../../其它常见的题目/src/linear_basis.cc)
- [矩阵快速幂模板](../../其它常见的题目/src/matrix_exponentiation.cc)
- [50. 幂函数 Pow(x, n)](../../leetcode/src/leetcode50.cc)
- [233. 数字 1 的个数](../../leetcode/src/leetcode233.cc)
