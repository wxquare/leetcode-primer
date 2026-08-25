# 模板目录

本目录保留算法学习笔记；对应的 C/C++ 源码已平铺迁至 [其它常见的题目](../其它常见的题目/src/)。使用前请按题目输入、索引范围和编译环境调整。

## 图论与树

| 模板 | 内容 |
| --- | --- |
| [graph_shortest_path_algorithms.cc](../其它常见的题目/src/graph_shortest_path_algorithms.cc) | 包含无权图 BFS、Dijkstra、Bellman-Ford（含负环检测）和 Floyd 全源最短路。 |
| [graph_shortest_path_variants.cc](../其它常见的题目/src/graph_shortest_path_variants.cc) | 包含无权 BFS、Dijkstra、Bellman-Ford（含负环检测）和 Floyd 全源最短路。 |
| [graph_minimum_spanning_tree.cc](../其它常见的题目/src/graph_minimum_spanning_tree.cc) | 包含并查集（路径压缩、按大小合并）与 Kruskal 最小生成树。 |
| [union_find.cc](../其它常见的题目/src/data_structure_union_find_template.cc) | 独立并查集：路径压缩、按大小合并、连通性判断、集合大小和连通块计数。 |
| [graph_topological_sort.cc](../其它常见的题目/src/graph_topological_sort.cc) | 包含基于入度与队列的 Kahn 拓扑排序，并以空结果表示存在环。 |
| [graph_bipartite_matching.cc](../其它常见的题目/src/graph_bipartite_matching.cc) | 二分图判定与匈牙利算法最大匹配。 |
| [graph_cycle_detection.cc](../其它常见的题目/src/graph_cycle_detection.cc) | 有向/无向图的环检测与最长环相关实现。 |
| [graph_functional_graph_cycles.cc](../其它常见的题目/src/graph_functional_graph_cycles.cc) | 包含无向图枚举起点 BFS 求最短环，以及有向基环树/内向基环树处理框架。 |
| [graph_max_flow_dinic.cc](../其它常见的题目/src/graph_max_flow_dinic.cc) | 包含残量网络建图的最大流思路，以及 Dinic 的分层 BFS、增广 DFS 和 `maxFlow` 接口。 |
| [graph_max_flow_dinic_example.cc](../其它常见的题目/src/graph_max_flow_dinic_example.cc) | Dinic 最大流完整实现示例。 |
| [graph_a_star_eight_puzzle.cc](../其它常见的题目/src/graph_a_star_eight_puzzle.cc) | 八数码的 A* 启发式搜索。 |
| [graph_shortest_path_visiting_all_nodes.cc](../其它常见的题目/src/graph_shortest_path_visiting_all_nodes.cc) | 状态压缩 BFS：访问所有节点的最短路径。 |
| [tarjan.cc](../其它常见的题目/src/tarjan.cc) | Tarjan 强连通分量算法。 |
| [graph_bridges.cc](../其它常见的题目/src/graph_bridges.cc) | 无向图 Tarjan：同时求桥和割点。 |
| [graph_zero_one_bfs.cc](../其它常见的题目/src/graph_zero_one_bfs.cc) | 0-1 BFS：边权仅为 0 或 1 时的单源最短路。 |
| [tree_lowest_common_ancestor.cc](../其它常见的题目/src/tree_lowest_common_ancestor.cc) | 倍增法最近公共祖先（LCA）。 |
| [tree_lowest_common_ancestor_variant.cc](../其它常见的题目/src/tree_lowest_common_ancestor_variant.cc) | 当前内容同为 LCA 相关实现，文件名可能需后续调整。 |
| [heavy_light_decomposition.cc](../其它常见的题目/src/heavy_light_decomposition.cc) | 树链剖分：构建重链与节点 DFS 序，并将路径拆分为连续区间。 |
| [tree_rerooting_dp.cc](../其它常见的题目/src/tree_rerooting_dp.cc) | 换根 DP：以“所有节点距离和”为例提供两次 DFS 框架。 |
| [traveling_salesman.cc](../其它常见的题目/src/traveling_salesman.cc) | 旅行商问题（TSP）的状态压缩 DP。 |
| [min_cost_max_flow.cc](../其它常见的题目/src/min_cost_max_flow.cc) | 最小费用最大流：残量网络、SPFA 找增广路与流量上限控制。 |

## 数据结构、搜索与基础算法

| 模板 | 内容 |
| --- | --- |
| [binary_search.cc](../其它常见的题目/src/binary_search.cc) | 递归与迭代二分查找。 |
| [binary_search_tree.cc](../其它常见的题目/src/binary_search_tree.cc) | 二叉搜索树的查找、插入和删除。 |
| [fenwick_tree.cc](../其它常见的题目/src/fenwick_tree.cc) | 树状数组：单点加、前缀和与区间和查询。 |
| [segment_tree.cc](../其它常见的题目/src/segment_tree.cc) | 动态开点线段树：建树、区间赋值、懒标记下推、区间聚合查询，以及 LeetCode `NumArray` 封装。 |
| [persistent_segment_tree.cc](../其它常见的题目/src/persistent_segment_tree.cc) | 主席树：按前缀版本插入离散值，并查询任意子数组的第 k 小值。 |
| [sparse_table.cc](../其它常见的题目/src/sparse_table.cc) | ST 表：静态区间最小值预处理与 `O(1)` 查询。 |
| [range_query_algorithms.cc](../其它常见的题目/src/range_query_algorithms.cc) | 包含差分数组区间增减、树状数组单点更新/区间和、动态开点线段树的区间更新与查询。 |
| [2-区间查询与统计.md](2-区间查询与统计.md) | 教学文档：从选型、推导到 C++17 模板，覆盖前缀和/差分、离散化、BIT、线段树、莫队和随机哈希。 |
| [monotonic_structures.cc](../其它常见的题目/src/monotonic_structures.cc) | 单调栈求下一个更大元素下标，单调队列求滑动窗口最大值。 |
| [sorting_algorithms.cc](../其它常见的题目/src/sorting_algorithms.cc) | 包含冒泡、插入、选择、希尔、快速、归并、基数、计数、桶和堆排序；同时给出数组与 `vector` 版快排/归并。 |
| [select_k.cc](../其它常见的题目/src/select_k.cc) | 基于快速排序分区的递归 Quickselect，求第 k 小元素。 |
| [custom_compare.cc](../其它常见的题目/src/custom_compare.cc) | 包含结构体 `operator<`、函数对象比较器、`sort`、`priority_queue` 与 `set` 的自定义排序写法。 |
| [math_algorithms.cc](../其它常见的题目/src/math_algorithms.cc) | 包含素性判定、两种筛法、因子/公共质因子、gcd/lcm、扩展欧几里得、快速幂与逆元、组合数、拒绝采样、水塘抽样和洗牌。 |
| [linear_basis.cc](../其它常见的题目/src/linear_basis.cc) | 64 位异或线性基：插入、最大异或值与可表示性判断。 |
| [matrix_exponentiation.cc](../其它常见的题目/src/matrix_exponentiation.cc) | 模意义矩阵乘法与二分快速幂，适用于线性递推。 |
| [coordinate_compression.cc](../其它常见的题目/src/coordinate_compression.cc) | 泛型坐标压缩：去重排序、值到下标和下标到值的双向映射。 |
| [dp_digit.cc](../其它常见的题目/src/dp_digit.cc) | 数位 DP：前导零/上界标记、记忆化 DFS，以及区间内步进数计数示例。 |
| [dp_knapsack.cc](../其它常见的题目/src/dp_knapsack.cc) | 包含 0/1 背包、完全背包、多重背包朴素枚举、多重背包二进制优化，以及混合背包。 |

## 字符串与自动机

| 模板 | 内容 |
| --- | --- |
| [cpp_integer_conversion.cc](../其它常见的题目/src/cpp_integer_conversion.cc) | 字符串与整数的转换实现。 |
| [cpp_c_string_functions.cc](../其它常见的题目/src/cpp_c_string_functions.cc) | 包含 `memcpy`（含内存重叠处理）、`memset`、`strcpy`、`strncpy`、`strcat`、`strcmp` 和 `strlen` 实现。 |
| [string_algorithms.cc](../其它常见的题目/src/string_algorithms.cc) | 包含 KMP、Trie 的插入/查询，以及 AC 自动机的构建、失败指针和多模式匹配。 |
| [string_kmp_template.cc](../其它常见的题目/src/string_kmp_template.cc) | KMP 前缀函数与匹配模板。 |
| [string_aho_corasick_array.cc](../其它常见的题目/src/string_aho_corasick_array.cc) | 数组子节点版 AC 自动机。 |
| [string_aho_corasick_map.cc](../其它常见的题目/src/string_aho_corasick_map.cc) | 哈希子节点版 AC 自动机与失败指针。 |
| [manacher.cc](../其它常见的题目/src/manacher.cc) | Manacher 算法：线性时间求最长回文子串。 |
| [z_function.cc](../其它常见的题目/src/z_function.cc) | Z 函数：计算每个后缀与原串的最长公共前缀长度。 |

## C++ 实现与工程练习

| 模板 | 内容 |
| --- | --- |
| [dp_lis_fenwick_tree.cc](../其它常见的题目/src/dp_lis_fenwick_tree.cc) | 包含树状数组的更新/查询，以及用树状数组求最长递增子序列的示例。 |
| [data_structure_design_collection.cc](../其它常见的题目/src/data_structure_design_collection.cc) | 包含 LRU 缓存、LFU 缓存、自定义哈希表和跳表的实现。 |
| [cpp_string_raii.cc](../其它常见的题目/src/cpp_string_raii.cc) | 自定义字符串类的拷贝控制与内存管理。 |
| [cpp_string_raii_variant.cc](../其它常见的题目/src/cpp_string_raii_variant.cc) | 当前内容为自定义字符串类实现，文件名可能需后续调整。 |
| [factory.cc](../其它常见的题目/src/factory.cc) | 工厂模式示例。 |
| [observer.cc](../其它常见的题目/src/observer.cc) | 当前内容为访问者模式示例。 |
| [singleton.cc](../其它常见的题目/src/singleton.cc) | 单例模式与线程安全初始化。 |
| [producer_consumer.cc](../其它常见的题目/src/producer_consumer.cc) | 多线程生产者—消费者模型。 |
| [read_write_locker.cc](../其它常见的题目/src/read_write_locker.cc) | 读写锁实现。 |
| [fast_io_and_debug.hpp](../其它常见的题目/src/fast_io_and_debug.hpp) | 快速 I/O 初始化与仅在 `LOCAL` 宏下生效的调试输出宏。 |
