# 其它常见的题目

这里收录 LeetCode 与《剑指 Offer》之外的常见算法题、可复用模板、数据结构设计题与并发练习。源码统一位于平铺的 [`src/`](src/) 目录，采用小写英文 `snake_case`，并用主题前缀表达用途。

## 整理规则

- 一个文件只承载一个独立题目，或同一算法领域的一组可协同复用实现。
- `合集`类文件保留多个紧密相关的变体，例如多种排序或最短路；它们不是互不相关题目的堆放。
- 已有独立实现时不再从旧合集重复拆出同名副本，例如 `cache_lru.cc`、`cache_lfu.cc`、`string_kmp.cc`、`trie.cc` 与 `union_find.cc`。

## 算法合集

| 文件 | 主题与包含内容 | 主要入口 / 核心类型 | 难度 |
| --- | --- | --- | --- |
| [sorting_algorithms.cc](src/sorting_algorithms.cc) | 排序算法合集：冒泡、插入、选择、希尔、快排、归并、基数、计数、桶与堆排序。 | `bubbleSort`、`quickSort`、`mergeSort`、`heapSort` | ★★★ |
| [math_algorithms.cc](src/math_algorithms.cc) | 数论与随机算法：素数筛、因子、GCD/LCM、扩欧、快速幂、组合数、采样与洗牌。 | `isPrime`、`gcd`、`pow_mod`、`reservoirSampling` | ★★★ |
| [string_algorithms.cc](src/string_algorithms.cc) | 字符串算法合集：KMP、Trie 与 AC 自动机。 | `kmp`、`Trie`、`acAutomaton` | ★★★★ |
| [range_query_algorithms.cc](src/range_query_algorithms.cc) | 区间更新与查询：差分数组、树状数组、动态开点线段树。 | `difference`、`FenwickTree`、`SegTree` | ★★★★ |
| [dp_knapsack.cc](src/dp_knapsack.cc) | 背包 DP：0/1、完全、多重、二进制优化与混合背包。 | `zeroOnePack`、`completePack`、`boundedKnapsack`、`mixPack` | ★★★★ |
| [graph_shortest_path_algorithms.cc](src/graph_shortest_path_algorithms.cc) | 最短路基础合集：无权 BFS、Dijkstra、Bellman-Ford、Floyd。 | `bfs`、`dijkstra`、`bellmanFord`、`floyd` | ★★★★ |
| [graph_shortest_path_variants.cc](src/graph_shortest_path_variants.cc) | 最短路的另一组实现，含负环检测。 | `bfs`、`dijkstra`、`bellmanFord`、`floyd` | ★★★★ |
| [data_structure_design_collection.cc](src/data_structure_design_collection.cc) | 旧版数据结构合集：LRU、LFU、哈希表与跳表；优先使用下方独立实现。 | `LRUCache`、`LFUCache`、`MyHashMap`、`SkipList` | ★★★★ |

## 独立数据结构与基础算法

| 文件 | 题目/用途 | 主入口或核心类型 | 难度 |
| --- | --- | --- | --- |
| [cache_lru.cc](src/cache_lru.cc) | LRU 缓存设计。 | `LRUCache` | ★★★ |
| [cache_lfu.cc](src/cache_lfu.cc) | LFU 缓存设计。 | `LFUCache` | ★★★★ |
| [union_find.cc](src/union_find.cc) | 并查集：连通性、合并与路径压缩。 | `UnionFind` | ★★ |
| [fenwick_tree.cc](src/fenwick_tree.cc) | 树状数组：单点更新、前缀和与区间和。 | `FenwickTree` | ★★★ |
| [segment_tree.cc](src/segment_tree.cc) | 动态开点线段树与懒标记。 | `SegTree` | ★★★★ |
| [persistent_segment_tree.cc](src/persistent_segment_tree.cc) | 主席树：区间第 k 小。 | `PersistentSegmentTree` | ★★★★★ |
| [sparse_table.cc](src/sparse_table.cc) | 静态区间最值查询。 | `SparseTableMin` | ★★★ |
| [monotonic_structures.cc](src/monotonic_structures.cc) | 单调栈与单调队列。 | `next_greater_index`、`sliding_window_maximum` | ★★★ |
| [binary_search.cc](src/binary_search.cc) | 递归与迭代二分查找。 | `binarySearch` | ★ |
| [binary_search_tree.cc](src/binary_search_tree.cc) | 二叉搜索树插入、查找与删除。 | `BinarySearchTree` | ★★★ |
| [trie.cc](src/trie.cc) | 前缀树实现。 | `Trie` | ★★★ |
| [tree_lowest_common_ancestor.cc](src/tree_lowest_common_ancestor.cc) | 倍增法最近公共祖先。 | `lca` | ★★★★ |
| [heavy_light_decomposition.cc](src/heavy_light_decomposition.cc) | 树链剖分。 | `HeavyLightDecomposition` | ★★★★★ |
| [linear_basis.cc](src/linear_basis.cc) | 异或线性基。 | `LinearBasis` | ★★★★ |

## 图论、字符串与动态规划专题

| 文件 | 题目/用途 | 主入口或核心类型 | 难度 |
| --- | --- | --- | --- |
| [graph_bridges.cc](src/graph_bridges.cc) | 求无向图桥与割点。 | `BridgeAndCutVertex` | ★★★★ |
| [tarjan.cc](src/tarjan.cc) | Tarjan 强连通分量。 | `tarjan` | ★★★★ |
| [graph_zero_one_bfs.cc](src/graph_zero_one_bfs.cc) | 0-1 BFS。 | `zero_one_bfs` | ★★★ |
| [graph_minimum_spanning_tree.cc](src/graph_minimum_spanning_tree.cc) | Kruskal 最小生成树。 | `kruskal` | ★★★ |
| [graph_topological_sort.cc](src/graph_topological_sort.cc) | Kahn 拓扑排序与环检测。 | `topologicalSort` | ★★★ |
| [graph_bipartite_matching.cc](src/graph_bipartite_matching.cc) | 二分图判定与匈牙利匹配。 | `isBipartite`、`maximumMatching` | ★★★★ |
| [graph_max_flow_dinic.cc](src/graph_max_flow_dinic.cc) | Dinic 最大流。 | `Dinic` | ★★★★★ |
| [min_cost_max_flow.cc](src/min_cost_max_flow.cc) | 最小费用最大流。 | `MinCostMaxFlow` | ★★★★★ |
| [traveling_salesman.cc](src/traveling_salesman.cc) | 状压 DP 求 TSP。 | `travelingSalesman` | ★★★★★ |
| [manacher.cc](src/manacher.cc) | 线性最长回文子串。 | `longest_palindromic_substring` | ★★★★ |
| [z_function.cc](src/z_function.cc) | Z 函数。 | `z_function` | ★★★ |
| [dp_digit.cc](src/dp_digit.cc) | 数位 DP。 | `digitDP` | ★★★★ |
| [matrix_exponentiation.cc](src/matrix_exponentiation.cc) | 矩阵快速幂。 | `matrix_power` | ★★★ |

## 设计、并发与工程练习

| 文件 | 题目/用途 | 主入口或核心类型 | 难度 |
| --- | --- | --- | --- |
| [factory.cc](src/factory.cc) | 工厂模式示例。 | `Factory` | ★★ |
| [observer.cc](src/observer.cc) | 观察者/访问者模式示例。 | `Visitor` | ★★ |
| [singleton.cc](src/singleton.cc) | 线程安全单例。 | `Singleton` | ★★ |
| [cpp_string_raii.cc](src/cpp_string_raii.cc) | 自定义字符串的资源管理。 | `CString` | ★★★ |
| [cpp_string_raii_variant.cc](src/cpp_string_raii_variant.cc) | 自定义容器/字符串练习。 | `CString` | ★★★ |
| [producer_consumer.cc](src/producer_consumer.cc) | C++ 生产者—消费者模型。 | `ProducerConsumer` | ★★★ |
| [read_write_locker.cc](src/read_write_locker.cc) | 读写锁。 | `ReadWriteLock` | ★★★ |
| [concurrency_h2o.go](src/concurrency_h2o.go) | 并发协调生成 H₂O。 | `H2O` | ★★★ |
| [concurrency_dining_philosophers.go](src/concurrency_dining_philosophers.go) | 哲学家进餐死锁规避。 | `DiningPhilosophers` | ★★★★ |
| [concurrency_producer_consumer_sum.go](src/concurrency_producer_consumer_sum.go) | Go 并发生产与消费。 | `main` | ★★★ |
| [lua_token_rate_limit.lua](src/lua_token_rate_limit.lua) | Redis Lua 令牌桶限流。 | Redis 脚本入口 | ★★★ |
| [lua_token_limiter.py](src/lua_token_limiter.py) | Redis 令牌桶限流客户端。 | `TokenLimiter` | ★★★ |

## 独立题目

| 文件 | 题目含义 | 主要入口 | 难度 |
| --- | --- | --- | --- |
| [graph_shortest_path_visiting_all_nodes.cc](src/graph_shortest_path_visiting_all_nodes.cc) | 访问所有节点的最短路径（状态压缩 BFS）。 | `shortestPathLength` | ★★★★★ |
| [graph_a_star_eight_puzzle.cc](src/graph_a_star_eight_puzzle.cc) | 八数码 A* 搜索。 | `solvePuzzle` | ★★★★★ |
| [interview_valid_sudoku.cc](src/interview_valid_sudoku.cc) | 判断 9×9 数独是否合法。 | `isValidSudoku` | ★★ |

## 后续拆分边界

当前无需把同一算法领域的合集强行拆成几十个小文件；这些函数共享辅助逻辑且作为复习模板更易查阅。若后续要进一步模块化，优先拆分 `data_structure_design_collection.cc` 中尚未独立的 `MyHashMap` 与 `SkipList`，再处理 `math_algorithms.cc` 中的随机采样部分。
