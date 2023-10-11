# leetcode-primer

## 数据结构
1. 链表/单链表/双链表
      - [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)
	- [面试题 02.05. 链表求和](https://leetcode-cn.com/problems/sum-lists-lcci/)
	- [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)
	- [交换链表中的第K个节点和倒数第K个节点](https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list/)
2. stack/单调stack/双stack/（在线性时间内找到每个元素的上一个或者下一个更大或更小元素）
	- [503. 下一个更大元素 II](https://leetcode-cn.com/problems/next-greater-element-ii/)
	- [496. 下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/)
	- [739. 每日温度](https://leetcode.cn/problems/daily-temperatures/submissions/457081358/)
	- [最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/submissions/457085863/)
	- [2818. 操作使得分最大](https://leetcode.cn/problems/apply-operations-to-maximize-score/submissions/456747016/)
	- [901. 股票价格跨度](https://leetcode.cn/problems/online-stock-span/submissions/472058521/)
3. queue/双端deque/单调deque（单调队列通常用于解决滑动窗口问题，其中我们需要在滑动窗口内找到最大值或最小值）
	- [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/submissions/457105531/)
 	- [862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/submissions/457422626/)
	- [2810.  故障键盘](https://leetcode.cn/problems/faulty-keyboard/)
	- [918. 环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray/submissions/457447563/)
4. 优先队列和堆，任务调度
	- [最大平均通过率](https://leetcode-cn.com/problems/maximum-average-pass-ratio/)
	- [单线程 CPU](https://leetcode-cn.com/problems/single-threaded-cpu/)
	- [Minimum Possible Integer After at Most K Adjacent Swaps On Digits](https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/)
	- [Last Moment Before All Ants Fall Out of a Plank](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/)
	- [好子数组的最大分数](https://leetcode-cn.com/problems/maximum-score-of-a-good-subarray/)
4. 哈希unorderer_map/unordered_set
6. 平衡二叉树map/multimap/set/multimap
7. 循环数组和循环字符串
	- 使循环数组所有元素相等的最少秒数


## 基本算法
1. 二分算法 (lower_bound,map.lower_bound,check 二分答案）
	- [有界数组中指定下标处的最大值](https://leetcode-cn.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/)
	- [1482. 制作 m 束花所需的最少天数](https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/)
  	- [打家劫舍VI，小偷的最大能力最小，二分+DP](https://leetcode.cn/problems/house-robber-iv/submissions/466693294/)
2. top k，select kth
	- [面试题 17.09. 第 k 个数](https://leetcode.cn/problems/get-kth-magic-number-lcci/) 三指针，优先队列
      - [2512.奖励最顶尖的 K 名学生](https://leetcode.cn/problems/reward-top-k-students/submissions/473327675/)
3. 位运算
      - [所有数对按位与结果的异或和](https://leetcode-cn.com/problems/find-xor-sum-of-all-pairs-bitwise-and/)
      - 利用了 num & (num - 1) 的性质，可以快速消除 num 二进制表示中最右边的1
      - lowbit(x) = x & (-x)
      - x |= (1 << i)
      - (x & (1 << i)) == 0
      - 异或运算: 0^0=1,0^1=1,1^1=0,
      - x ^ (1 << i) = x
      - __builtin_clz,__builtin_ctz,__builtin_popcount
      - [2897. 对数组执行操作使平方和最大](https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares/submissions/473022397/)
4. 脑筋急转弯、技巧类
      - [2731. 移动机器人](https://leetcode.cn/problems/movement-of-robots/submissions/473011278/)



## 贪心算法
1. [超级洗衣机](https://leetcode.cn/problems/super-washing-machines/submissions/464025796/)
2. [课程表3(反悔贪心,排序、最大堆)](https://leetcode.cn/problems/course-schedule-iii/submissions/465271665/)


## 数据结构实现
-   [LRU](https://leetcode-cn.com/problems/lru-cache/)
-   [LFU](https://leetcode-cn.com/problems/lfu-cache/)
-   [HashSet](https://leetcode-cn.com/problems/design-hashset/)
-   [HashMap](https://leetcode-cn.com/problems/design-hashmap/)
-   跳表
-   trie树
-   [剑指 Offer 59 - II. 队列的最大值](https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/submissions/457437191/)

## 数学
1. 数论问题
      - [判断是否是素数（质数）](https://github.com/wxquare/online-algorithm-coding/blob/master/other/primes.cc)
      - [求1-n之间的所有素数，素数筛选法](https://github.com/wxquare/online-algorithm-coding/blob/master/other/primes.cc)
      - 分解质因数  
      - [求多个数的公共质因子](https://github.com/wxquare/online-algorithm-coding/blob/master/other/primes.cc)
      - [两数、多数最大公约数](https://github.com/wxquare/online-algorithm-coding/blob/master/other/primes.cc)
      - [两数、多数最小公倍数](https://github.com/wxquare/online-algorithm-coding/blob/master/other/primes.cc)
      - [2709. 最大公约数遍历](https://leetcode.cn/problems/greatest-common-divisor-traversal/submissions/436245155/)
      - [2698. 求一个整数的惩罚数](https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/submissions/435214562/)
      - [1998. 数组的最大公因数排序](https://leetcode.cn/problems/gcd-sort-of-an-array/description/)
2. 快速幂
      - [50. Pow(x, n)](https://leetcode.cn/problems/powx-n/submissions/448492142/)
      - [372. 超级次方](https://leetcode.cn/problems/super-pow/submissions/245597022/) （快速幂和模运算）
3. 模运算
      - (a + b) mod c = ((a mod c) + (b mod c)) mod c
      - (a * b) mod c =  ((a mod c) * (b mod c)) mod c
      - (a / b) mod c =  (a * (b^(-1))) mod c，其中 b^(-1) 是 b 的乘法逆元。如果 c 是一个素数，且 b 是不可被 c 整除的整数，那么 b 的乘法逆元（b模c的逆元）可以通过以下方式计算：
	b^(-1) ≡ b^(c-2) (mod c)
      - [2842. 统计一个字符串的 k 子序列美丽值最大的数目](https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty/submissions/463360552/)
      - 乘法逆元，扩展欧几里得算法
      - 费马定理
2. 拒绝抽样(rejection sampling)
      - [用 Rand7() 实现 Rand10()](https://leetcode.cn/problems/implement-rand10-using-rand7/solutions/978527/yong-rand7-shi-xian-rand10-by-leetcode-s-qbmd/)
3. 水塘抽样
      - [382. 链表随机节点](https://leetcode.cn/problems/linked-list-random-node/description/)
      - [398. 随机数索引](https://leetcode.cn/problems/random-pick-index/submissions/305425474/)
      - [reservoirSampling](https://github.com/wxquare/online-algorithm-coding/blob/master/other/math.cc)
4. 洗牌算法
      - [384. 打乱数组](https://leetcode.cn/problems/shuffle-an-array/submissions/)
5. 位运算
      - [所有数对按位与结果的异或和](https://leetcode-cn.com/problems/find-xor-sum-of-all-pairs-bitwise-and/)
      - 利用了 num & (num - 1) 的性质，可以快速消除 num 二进制表示中最右边的1
      - lowbit(x) = x & (-x)
      - x |= (1 << i)
      - (x & (1 << i)) == 0
      - 异或运算: 0^0=1,0^1=1,1^1=0,
      - x ^ (1 << i) = x
      - __builtin_clz,__builtin_ctz,__builtin_popcount
6. 排列
     - [31. 下一个排列](https://leetcode.cn/problems/next-permutation/)
     - [556. 下一个更大元素 III](https://leetcode-cn.com/problems/next-greater-element-iii/)
7. 组合和带取模的组合
   - [2842. 统计一个字符串的 k 子序列美丽值最大的数目](https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty/submissions/463360552/)


## 字符串匹配问题Trie Tree/kmp/ac状态
- [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)
- [Implement Magic Dictionary](https://leetcode.com/problems/implement-magic-dictionary/)
- [统计异或值在范围内的数对有多少](https://leetcode-cn.com/problems/count-pairs-with-xor-in-a-range/)
- [kmp](https://github.com/wxquare/online-algorithm-coding/blob/master/other/kmp.cc)
- [最长合法子字符串的长度 ac 自动机](https://leetcode.cn/submissions/detail/448173370/)

## 区间问题/前缀/后缀/差分/树状数组/线段树
1. 前缀和prefixSum,后缀和suffixSum
2. 差分数组 （区间同时加减一个数，求最终单点的值）
      - [1109. Corporate Flight Bookings](https://leetcode.cn/problems/corporate-flight-bookings/submissions/213589517/)
3. 树状数组 (单点修改，前缀和和区间和）（lowbit 函数会求出一个二进制的最低位1代表的数字， x & -x，树状树组index从1开始）
      - [307. Range Sum Query - Mutable](https://leetcode.cn/problems/range-sum-query-mutable/submissions/413938101/)
      - [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/submissions/436429471/)
4. 线段树 （区间修改，将一个区间的数据修改为某个相同的值，求区间合、最值，区间内可以聚合的值）
      - [307. Range Sum Query - Mutable](https://leetcode.cn/problems/range-sum-query-mutable/submissions/413762232/)
      - [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/submissions/436608727/)
      - [2407.最长递增子序列II](https://leetcode.cn/problems/longest-increasing-subsequence-ii/submissions/436945876/)
5. 离线问题
      - [2747. 统计没有收到请求的服务器数目](https://leetcode.cn/problems/count-zero-request-servers/submissions/444263284/)
      - [1851. 包含每个查询的最小区间](https://leetcode.cn/problems/minimum-interval-to-include-each-query/submissions/444281304/)
      - 1938. 查询最大基因差
      - 2070. 每一个查询的最大美丽值
      - 2343. 裁剪数字后查询第 K 小的数字
      - 2503. 矩阵查询可获得的最大分数
      - 2736. 最大和查询

## 搜索问题
1. BFS/多源BFS（源点为多个）/双向BFS
      - [2812. 找出最安全路径，多源BFS](https://leetcode.cn/problems/find-the-safest-path-in-a-grid/submissions/455237953/) 
2. DFS/剪枝/回溯（深度搜索+限制条件+限制搜索路径）
      - [LCR 086. 分割回文串](https://leetcode.cn/problems/M99OJA/submissions/465972869/)
      - [面试题 08.12. 八皇后 n皇后问题](https://leetcode.cn/problems/eight-queens-lcci/submissions/465946635/)
      - [2850. 将石头分散到网格图的最少移动次数](https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/submissions/465962967/)
      - [2698. 求一个整数的惩罚数，预处理+回溯](https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/submissions/435214562/)
3. 记忆化搜索 （动态规划，状态优化）
      - [2742. 给墙壁刷油漆，状态优化](https://leetcode.cn/problems/painting-the-walls/submissions/440997959/)
      - [2707. 字符串中的额外字符](https://leetcode.cn/problems/extra-characters-in-a-string/submissions/436332452/)
      - [2597. 美丽子集的数目](https://leetcode.cn/problems/the-number-of-beautiful-subsets/submissions/415822742/)
      - [2811. 判断是否能拆分数组](https://leetcode.cn/problems/check-if-it-is-possible-to-split-array/description/)
      - [996. 正方形数组的数目，预处理/重复数字全排列](https://leetcode.cn/problems/number-of-squareful-arrays/submissions/441000077/)
      - [2741. 特别的排列，全排列/剪枝](https://leetcode.cn/problems/special-permutations/submissions/440660237/)
      - [2896. 执行操作使两个字符串相等](https://leetcode.cn/problems/apply-operations-to-make-two-strings-equal/submissions/472717555/)
4. 启发式搜索
      - 八数码问题


## DP问题（递推类DP）
1. 线性 DP （包括状态机DP，序列DP,子问题有一个端点是固定不变的）
	1. 线性DP
	      - [斐波那契数列](https://leetcode.cn/problems/fibonacci-number/submissions/431236355/)
	      - [数字三角形](https://leetcode.cn/problems/triangle/submissions/431243125/)
	      - [跳跃游戏1，2，3，4](https://leetcode.cn/problems/jump-game/submissions/431244632/)
	      - [2708. 一个小组的最大实力值](https://leetcode.cn/problems/maximum-strength-of-a-group/submissions/436302364/)
	      - [销售利润最大化](https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/submissions/458598692/)
	2. 状态机DP（关键是设计状态以及状态转移方程，之后在处理边界条件）
 		- 打家劫舍（1.普通、2.环形、3.树形DP、4.DP+二分）
		- [将三个数组的排序](https://leetcode.cn/problems/sorting-three-groups/submissions/458601624/)
		- 买卖股票的最大利润（最多一次买卖、最多两次、最多K次、无限次买卖、冷冻期1天、手续费）
	4. 序列DP (序列DP是动态规划中的一种常见形式，通常用于解决一些关于序列的问题，比如最长递增子序列、编辑距离等)
	      - [最长上升子序列问题](https://leetcode.cn/problems/longest-increasing-subsequence/submissions/430135553/)
	      - [最长上升子序列问题 LIS](https://leetcode.cn/problems/longest-increasing-subsequence/submissions/430135553/)
	      - [最长公共子序列（LCS）](https://leetcode.cn/problems/longest-common-subsequence/submissions/430898547/)- [将一个字符串分割成回文串，最少分割次数](https://leetcode.cn/problems/omKAoA/)
2. 背包 DP
      - 01背包
      - 完全背包
      - 多重背包
      - [494. 目标和](https://leetcode.cn/problems/target-sum/submissions/458957015/)
      - [322. 零钱兑换](https://leetcode.cn/problems/coin-change/)
      - [518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-ii/submissions/458945557/)
3. 区间 DP （子问题向内缩小，两端都会向内移动）
      - [最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence/submissions/430171478/)
      - [石子游戏](https://leetcode.cn/problems/stone-game/submissions/430220611/)
4. bitmask，状压 和 状态压缩DP,bitmask vs map+vector （把集合用二进制表示,二进制mask 1<<n）
      - [优美的排列](https://leetcode.cn/problems/beautiful-arrangement/submissions/430278600/)
      - [638. 大礼包](https://leetcode.cn/problems/shopping-offers/submissions/467843620/)
      - [691. 贴纸拼词](https://leetcode.cn/problems/stickers-to-spell-word/submissions/468199760/)
5. 树形 DP （子树天然地形成子问题，需要考虑dp的信息是怎么从子树传给上面的子树的，记忆化搜索，递归。就是我们已经知道以uuu为根的答案，想要通过u−>v的父子关系把答案传递给）
      - [打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/submissions/466687291/)
      - [最小化旅行的价格总和](https://leetcode.cn/problems/minimize-the-total-price-of-the-trips/submissions/467832597/)
      - [2858. 可以到达每一个节点的最少边反转次数,换根DP](https://leetcode.cn/problems/minimum-edge-reversals-so-every-node-is-reachable/submissions/467513545/)
      - [834. 树中距离之和](https://leetcode.cn/problems/sum-of-distances-in-tree/submissions/467525870/)
      - [2581. 统计可能的树根数目](https://leetcode.cn/problems/count-number-of-possible-root-nodes/submissions/467531744/)
6. 数位 DP (dfs(int i,int state,bool is_limit,bool is_num)
      - [统计整数的数量](https://leetcode.cn/problems/count-of-integers/submissions/437570070/)
      - [1012. 至少有 1 位重复的数字](https://leetcode.cn/problems/numbers-with-repeated-digits/description/)
      - [233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one/submissions/437909738/)
      - [600. 不含连续1的非负整数](https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/submissions/438160324/)
      - [902. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/submissions/452354134/)
      - [2376. 统计特殊整数](https://leetcode.cn/problems/count-special-integers/submissions/452339066/)
      - [2801. 统计范围内的步进数字数目](https://leetcode.cn/problems/count-stepping-numbers-in-range/submissions/452043045/)
      - [2827. 范围中美丽整数的数目](https://leetcode.cn/problems/number-of-beautiful-integers-in-the-range/submissions/458609134/)
7. 数据结构优化DP
      - [2713. 矩阵中严格递增的单元格数](https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix/submissions/436001561/)
      - [2407.最长递增子序列II](https://leetcode.cn/problems/longest-increasing-subsequence-ii/submissions/436945876/)
8. 倍增和倍增优化DP
      - [2836. 在传球游戏中最大化函数值](https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game/submissions/461089653/)
      - [1483. 树节点的第 K 个祖先](https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/submissions/461103416/)
      - lca
      - [2846. 边权重均等查询](https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree/submissions/463012152/)
9. 矩阵快速幂优化DP
      - [2851. 字符串K次转换等于目标串的方案数量](https://leetcode.cn/problems/string-transformation/submissions465291899/)
        

## 树/图论
1. 二叉树、树和图的深搜和宽搜
      - [lowest common ancestor](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)
      - [二叉树的前、中、后序遍历,非递归的实现](https://github.com/wxquare/programming/blob/master/oj/datastruct-algorithm/binary_tree.cpp)（12.21）
      - [二叉搜索树的查找、插入和删除](https://github.com/wxquare/programming/blob/master/oj/datastruct-algorithm/binary_search_tree.cpp)
      - [2872. 可以被 K 整除连通块的最大数目](https://leetcode.cn/problems/maximum-number-of-k-divisible-components/submissions/472078651/)

2. [最短路径和K短问题](https://github.com/wxquare/online-algorithm-coding/blob/master/other/graph_short_path.cc)
      - BFS（单源，无权路，权值为1的最短路，O(n)）
      - Dijkstra（单源，权值为正,O((E)logE))
      - Ballmanford （单源，n-1次松驰，,权值可正可负，可用于检测负环,O(V*E))
      - Floyd（多源，任意两点的距离，O(n^3))
      - A*
            - [八数码问题](https://github.com/wxquare/online-algorithm-coding/blob/master/other/8-puzzle.cc)
      - [743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/submissions/416407193/)
      - [2045. 到达目的地的第二短时间](https://leetcode.cn/problems/second-minimum-time-to-reach-destination/submissions/416029633/)
3. [拓扑排序和度](https://github.com/wxquare/online-algorithm-coding/blob/master/other/topological.cc)
     - [207. 课程表](https://leetcode-cn.com/problems/course-schedule/)
     - [210. 课程表 II](https://leetcode-cn.com/problems/course-schedule-ii/)
     - [2603. 收集树中金币](https://leetcode.cn/problems/collect-coins-in-a-tree/submissions/418411707/)
4. [并查集](https://github.com/wxquare/online-algorithm-coding/blob/master/other/union_find.cc)
     - [547. 省份的数量](https://leetcode-cn.com/problems/number-of-provinces/)
     - [2709. 最大公约数遍历](https://leetcode.cn/problems/greatest-common-divisor-traversal/submissions/436245155/)
     - [1998. 数组的最大公因数排序](https://leetcode.cn/problems/gcd-sort-of-an-array/description/)
     - [冗余连接](https://leetcode.cn/problems/redundant-connection/submissions/)
5. 最小生成树
      - [Kruskal](https://github.com/wxquare/online-algorithm-coding/blob/master/other/minimum_spanning_tree.cc)
      - [1584. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points/submissions/424543501/)
6. 基环树、内向树、外向树
      - [2127. 参加会议的最多员工数](https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/submissions/453034664/)
      - [2360. 图中的最长环](https://leetcode.cn/problems/longest-cycle-in-a-graph/submissions/453037901/)
      - [2876. 有向图访问计数](https://leetcode.cn/problems/count-visited-nodes-in-a-directed-graph/submissions/)
6. 图的最大环最小环
      - [图中的最短环,BFS有向图和无向图都可以](https://leetcode.cn/problems/shortest-cycle-in-a-graph/submissions/)
      - 无向图枚举点做BFS
      - 有向图枚举点做DFS
8. 欧拉回路/通路
      - [Reconstruct Itinerary](https://leetcode.cn/problems/reconstruct-itinerary/submissions/417006045/)
9. 图的连通性
      - [1489. 找到最小生成树里的关键边和伪关键边](https://leetcode.cn/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/submissions/419266120/)
      - [2685. 统计完全连通分量的数量](https://leetcode.cn/problems/count-the-number-of-complete-components/submissions/432982804/)
      - [查找集群内的关键连接](https://leetcode.cn/problems/critical-connections-in-a-network/submissions/464145062/)
      - tarjan 求强连通分量 模版
      - tarjan 求割点 模版
      - tartan 求割边 模版
10. 寻找符合条件的路径
      - [6942. 树中可以形成回文的路径数](https://leetcode.cn/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/)
12. 二分图问题
      - [染色分二分图判定是否存在基环，785. 判断二分图](https://leetcode.cn/problems/is-graph-bipartite/submissions/453421857/)
      - 二分图最大匹配，匈牙利增广路算法
14. 网络流
      - 最大流dinic算法
      - 最小割
      - 1349. 参加考试的最大学生数
      - 1350. [787. K 站中转内最便宜的航班]
      - [788. https://leetcode.cn/problems/possible-bipartition/description/]
      - https://www.cnblogs.com/wenruo/p/12357543.html
      - leetcode 1595.连通两组点的最小成
      - https://leetcode.cn/problems/7rLGCR/description/（守卫城堡）

## 参考
- [leetcode](https://leetcode.cn/)
- [灵茶山艾府](https://leetcode.cn/u/endlesscheng/)
- [宫水三叶](https://github.com/SharingSource/LogicStack-LeetCode)
- [代码随想录](https://github.com/youngyangyang04/leetcode-master)
- https://oi-wiki.org/
- https://zerotrac.github.io/leetcode_problem_rating/
- https://cp-algorithms.com/
