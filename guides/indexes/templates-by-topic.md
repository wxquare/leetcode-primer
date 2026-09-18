# 按主题分类的模板

[完整 LeetCode 题单](leetcode-problems.md) / [模板目录](../../template/README.md) / [高级主题](../roadmap/03-advanced-topics.md)

## 图与树

| Template | Trigger | Note | Code | Related practice |
| --- | --- | --- | --- | --- |
| 图遍历与最短路 | 无权步数、带权路径或全源可达性。 | [图与树指南](../../template/4-图论.md) | [graph_shortest_path_algorithms.cc](../../其它常见的题目/src/graph_shortest_path_algorithms.cc) | [743. 网络延迟时间](../../leetcode/数据结构运用/743_network_delay_time.cc) |
| 并查集 | 动态连通性、冗余边或连通块计数。 | [图与树指南](../../template/4-图论.md) | [union_find.cc](../../其它常见的题目/src/union_find.cc) | [684. 冗余连接](../../leetcode/图论/684_redundant_connection.cc) |
| 拓扑排序 | 有向依赖排序或环检测。 | [图与树指南](../../template/4-图论.md) | [graph_topological_sort.cc](../../其它常见的题目/src/graph_topological_sort.cc) | [210. 课程表 II](../../leetcode/图论/210_course_schedule_ii.cc) |
| 最近公共祖先 | 根化遍历预处理后的树祖先查询。 | [高级树](../roadmap/03-advanced-topics.md#trees) | [tree_lowest_common_ancestor.cc](../../其它常见的题目/src/tree_lowest_common_ancestor.cc) | [236. 二叉树的最近公共祖先](../../leetcode/图论/236_lowest_common_ancestor_of_a_binary_tree.cc) |

## 搜索

| Template | Trigger | Note | Code | Related practice |
| --- | --- | --- | --- | --- |
| 二分与答案二分 | 有序空间或可行性随答案单调变化。 | [搜索专题指南](../../template/5-搜索.md) | [binary_search.cc](../../其它常见的题目/src/binary_search.cc) | [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array) |
| BFS 与状态空间搜索 | 无权状态图中的最少步数、网格扩散或状态转移。 | [搜索专题指南](../../template/5-搜索.md) | [graph_shortest_path_algorithms.cc](../../其它常见的题目/src/graph_shortest_path_algorithms.cc) | [127. 单词接龙](https://leetcode.cn/problems/word-ladder) |
| DFS 与回溯 | 需要枚举组合、排列、路径或满足约束的方案。 | [搜索专题指南](../../template/5-搜索.md) | — | [46. 全排列](https://leetcode.cn/problems/permutations) |
| 启发式搜索 | 状态空间较大，需要状态压缩或估价函数。 | [搜索专题指南](../../template/5-搜索.md) | [graph_a_star_eight_puzzle.cc](../../其它常见的题目/src/graph_a_star_eight_puzzle.cc) | [847. 访问所有节点的最短路径](https://leetcode.cn/problems/shortest-path-visiting-all-nodes) |

## 基本算法

| Template | Trigger | Note | Code | Related practice |
| --- | --- | --- | --- | --- |
| 双指针与滑动窗口 | 两个指针维护边界，或连续区间可以增量更新。 | [基本算法指南](../../template/6-基本算法.md) | [monotonic_structures.cc](../../其它常见的题目/src/monotonic_structures.cc) | [15. 三数之和](https://leetcode.cn/problems/3sum) |
| 哈希与前缀状态 | 需要快速判重、计数或查找历史前缀状态。 | [基本算法指南](../../template/6-基本算法.md) | [custom_comparator.cc](../../其它常见的题目/src/custom_comparator.cc) | [560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k) |
| 排序、Top K 与选择 | 排序后结构简化，或只关心第 k 个元素。 | [基本算法指南](../../template/6-基本算法.md) | [quickselect_kth.cc](../../其它常见的题目/src/quickselect_kth.cc) | [215. 数组中的第 K 个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array) |
| 贪心与分治 | 局部选择可证明最优，或子问题独立并在合并阶段得到答案。 | [基本算法指南](../../template/6-基本算法.md) | [sorting_algorithms_collection.cc](../../其它常见的题目/src/sorting_algorithms_collection.cc) | [435. 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals) |

## 数据结构

| Template | Trigger | Note | Code | Related practice |
| --- | --- | --- | --- | --- |
| 栈、队列与单调结构 | 需要维护最近极值、窗口极值或嵌套状态。 | [数据结构指南](../../template/7-数据结构.md) | [monotonic_structures.cc](../../其它常见的题目/src/monotonic_structures.cc) | [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum) |
| 并查集 | 动态合并集合并查询连通性。 | [数据结构指南](../../template/7-数据结构.md) | [union_find.cc](../../其它常见的题目/src/union_find.cc) | [684. 冗余连接](https://leetcode.cn/problems/redundant-connection) |
| Trie 与字符串结构 | 前缀查询、多模式匹配或字符串状态转移。 | [数据结构指南](../../template/7-数据结构.md) | [string_algorithms_collection.cc](../../其它常见的题目/src/string_algorithms_collection.cc) | [208. 实现 Trie（前缀树）](https://leetcode.cn/problems/implement-trie-prefix-tree) |
| 树状数组与线段树 | 单点/区间更新和区间聚合查询。 | [区间查询指南](../../template/2-区间查询与统计.md) | [range_query_algorithms.cc](../../其它常见的题目/src/range_query_algorithms.cc) | [307. 区域和检索 - 数组可修改](https://leetcode.cn/problems/range-sum-query-mutable) |
| 数据结构设计 | 要求 O(1) 访问、淘汰、频次或随机抽样。 | [数据结构指南](../../template/7-数据结构.md) | [lru_cache_design.cc](../../其它常见的题目/src/lru_cache_design.cc) | [146. LRU 缓存](https://leetcode.cn/problems/lru-cache) |

## 动态规划

| Template | Trigger | Note | Code | Related practice |
| --- | --- | --- | --- | --- |
| 线性动态规划 | 当前状态依赖前一或前两个位置。 | [动态规划指南](../../template/3-DP.md) | [198_house_robber.cc](../../leetcode/动态规划/198_house_robber.cc) | [198. 打家劫舍](../../leetcode/动态规划/198_house_robber.cc) |
| 背包动态规划 | 在容量、目标和或数量约束下选择物品。 | [动态规划指南](../../template/3-DP.md) | [knapsack_dp.cc](../../其它常见的题目/src/knapsack_dp.cc) | [494. 目标和](../../leetcode/动态规划/494_target_sum.cc) |
| 状态压缩动态规划 | 已选集合可用位掩码表示。 | [高级动态规划](../roadmap/03-advanced-topics.md#advanced-dp) | [traveling_salesman.cc](../../其它常见的题目/src/traveling_salesman.cc) | [698. 划分为 k 个相等的子集](../../leetcode/搜索（非图）/698_can_partition_ksubsets.cc) |
| 数位动态规划 | 统计具有位约束且不超过上界的数字。 | [动态规划指南](../../template/3-DP.md) | [digit_dp.cc](../../其它常见的题目/src/digit_dp.cc) | [600. 二进制不含连续 1 的非负整数](../../leetcode/动态规划/600_decimal_to_binary.cc) |

## 区间查询

| Template | Trigger | Note | Code | Related practice |
| --- | --- | --- | --- | --- |
| 前缀和与差分数组 | 静态区间和或批量区间更新。 | [区间查询指南](../../template/2-区间查询与统计.md) | [range_query_algorithms.cc](../../其它常见的题目/src/range_query_algorithms.cc) | [724. 寻找数组的中心下标](../../leetcode/模拟/724_pivot_index.cc) |
| 树状数组 | 单点更新与前缀和或区间和查询。 | [区间查询指南](../../template/2-区间查询与统计.md) | [fenwick_tree.cc](../../其它常见的题目/src/fenwick_tree.cc) | [307. 区域和检索 - 数组可修改](../../leetcode/图论/307_range_sum_query_mutable.cc) |
| 线段树 | 自定义合并或懒更新的区间聚合。 | [区间查询指南](../../template/2-区间查询与统计.md) | [segment_tree.cc](../../其它常见的题目/src/segment_tree.cc) | [218. 天际线问题](../../leetcode/数据结构运用/218_the_skyline_problem.cc) |
| 可持久化线段树 | 不可变前缀版本上的离线顺序统计。 | [区间数据结构](../roadmap/03-advanced-topics.md#interval-data-structures) | [persistent_segment_tree.cc](../../其它常见的题目/src/persistent_segment_tree.cc) | [327. 区间和的个数](../../leetcode/数据结构运用/327_count_of_range_sum.cc) |

## 数学

| Template | Trigger | Note | Code | Related practice |
| --- | --- | --- | --- | --- |
| 数论基础 | 素数、因子、最大公约数、最小公倍数或整除性。 | [数学指南](../../template/1-数学.md) | [number_theory_algorithms.cc](../../其它常见的题目/src/number_theory_algorithms.cc) | [172. 阶乘后的零](../../leetcode/数学/172_factorial_trailing_zeroes.cc) |
| 快速幂与模逆元 | 大指数、模乘或素数模数下的除法。 | [数学指南](../../template/1-数学.md) | [number_theory_algorithms.cc](../../其它常见的题目/src/number_theory_algorithms.cc) | [50. x 的 n 次幂](../../leetcode/模拟/50_pow_x_n.cc) |
| 组合数学 | 排列、组合或模数下的计数。 | [组合数学说明](../../leetcode/数学/组合数学与取模.md) | [math_combinations.cc](../../其它常见的题目/src/math_combinations.cc) | [233. 数字 1 的个数](../../leetcode/动态规划/233_number_of_digit_one.cc) |
| 矩阵快速幂 | 重复多次的线性递推或转移。 | [数学指南](../../template/1-数学.md) | [matrix_exponentiation.cc](../../其它常见的题目/src/matrix_exponentiation.cc) | [2851. 字符串 K 次转换等于目标串的方案数量](../../leetcode/动态规划/2851_kmp.cc) |
