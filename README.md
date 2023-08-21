# leetcode-primer


## 数据结构
1. 数组/数组
	- 使循环数组所有元素相等的最少秒数
2. 链表/单链表/双链表
     - [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)
	- [面试题 02.05. 链表求和](https://leetcode-cn.com/problems/sum-lists-lcci/)
	- [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)
	- [交换链表中的第K个节点和倒数第K个节点](https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list/)
3. stack/单调stack/双stack/（在线性时间内找到每个元素的上一个或者下一个更大或更小元素）
	- [503. 下一个更大元素 II](https://leetcode-cn.com/problems/next-greater-element-ii/)
	- [496. 下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/)
	- [739. 每日温度](https://leetcode.cn/problems/daily-temperatures/submissions/457081358/)
	- [最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence/submissions/457085863/)
	- [2818. 操作使得分最大](https://leetcode.cn/problems/apply-operations-to-maximize-score/submissions/456747016/)
4. queue/双端deque/单调deque（单调队列通常用于解决滑动窗口问题，其中我们需要在滑动窗口内找到最大值或最小值）
	- [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/submissions/457105531/)
 	- [862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/submissions/457422626/)
	- [2810.  故障键盘](https://leetcode.cn/problems/faulty-keyboard/)
	- [918. 环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray/submissions/457447563/)
5. 优先队列和堆，任务调度
	- [最大平均通过率](https://leetcode-cn.com/problems/maximum-average-pass-ratio/)
	- [单线程 CPU](https://leetcode-cn.com/problems/single-threaded-cpu/)
	- [Minimum Possible Integer After at Most K Adjacent Swaps On Digits](https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/)
	- [Last Moment Before All Ants Fall Out of a Plank](https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/)
	- [好子数组的最大分数](https://leetcode-cn.com/problems/maximum-score-of-a-good-subarray/)
6. 哈希unorderer_map/unordered_set
7. 平衡二叉树map/multimap/set/multimap


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
6. 排列
     - [31. 下一个排列](https://leetcode.cn/problems/next-permutation/)
     - [556. 下一个更大元素 III](https://leetcode-cn.com/problems/next-greater-element-iii/)
7. 组合


## 基础算法
1. 排序算法
2. 二分算法 (lower_bound,map.lower_bound,check 二分答案）
	 - [有界数组中指定下标处的最大值](https://leetcode-cn.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/)
	- [1482. 制作 m 束花所需的最少天数](https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/)
3. top k，select kth
	- [面试题 17.09. 第 k 个数](https://leetcode.cn/problems/get-kth-magic-number-lcci/) 三指针，优先队列
4. 贪心
5. 模拟
6. kmp算法
7. ac状态算法
8. 洗牌算法



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



## 搜索问题 DFS/剪枝/回溯与状态恢复/记忆化搜索/状态压缩记忆化/选与不选/分割问题）
1. DFS 深度搜索 （树、图）
2. BFS/多源BFS/双向BFS
      - [2812. 找出最安全路径](https://leetcode.cn/problems/find-the-safest-path-in-a-grid/submissions/455237953/) 
4. 回溯（深度搜索+限制条件+限制搜索路径）
      - [2698. 求一个整数的惩罚数，预处理+回溯](https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/submissions/435214562/)
      - [131. 切割回文串131，切割+保存状态路径]
5. 记忆化搜索 （动态规划，状态优化）
      - [2742. 给墙壁刷油漆，状态优化](https://leetcode.cn/problems/painting-the-walls/submissions/440997959/)
      - [2707. 字符串中的额外字符](https://leetcode.cn/problems/extra-characters-in-a-string/submissions/436332452/)
      - [132. 切割回文串132]
      - [2597. 美丽子集的数目](https://leetcode.cn/problems/the-number-of-beautiful-subsets/submissions/415822742/)
      - [2811. 判断是否能拆分数组](https://leetcode.cn/problems/check-if-it-is-possible-to-split-array/description/)
6. 状态压缩记忆化搜索 （状态压缩动态规划）
      - [996. 正方形数组的数目，预处理/重复数字全排列](https://leetcode.cn/problems/number-of-squareful-arrays/submissions/441000077/)
      - [2741. 特别的排列，全排列/剪枝](https://leetcode.cn/problems/special-permutations/submissions/440660237/)
7. 分支限界搜索
8. 启发式搜索
9. 平面格子问题
      - [2812. 找出最安全路径](https://leetcode.cn/problems/find-the-safest-path-in-a-grid/submissions/455237953/) 

## DP问题（递推类DP）
1. 线性 DP
      - [斐波那契数列](https://leetcode.cn/problems/fibonacci-number/submissions/431236355/)
      - [数字三角形](https://leetcode.cn/problems/triangle/submissions/431243125/)
      - [最长上升子序列问题 LIS](https://leetcode.cn/problems/longest-increasing-subsequence/submissions/430135553/)
      - [最长公共子序列（LCS）](https://leetcode.cn/problems/longest-common-subsequence/submissions/430898547/)
      - [跳跃游戏](https://leetcode.cn/problems/jump-game/submissions/431244632/)
      - [跳跃游戏2](https://leetcode.cn/problems/jump-game-ii/submissions/424001382/)
      - [跳跃游戏3](https://leetcode.cn/problems/jump-game-iii/submissions/431516086/)
      - [跳跃游戏4](https://leetcode.cn/problems/jump-game-iv/submissions/431789470/)
      - [2708. 一个小组的最大实力值](https://leetcode.cn/problems/maximum-strength-of-a-group/submissions/436302364/)
      - [销售利润最大化](https://leetcode.cn/problems/maximize-the-profit-as-the-salesman/submissions/458598692/)
2. 状态机 DP
	- 将三个数组的排序
4. 背包 DP
      - 01背包
      - 完全背包
      - 多重背包，多重背包二进制优化
5. 序列 DP
      - 序列DP是动态规划中的一种常见形式，通常用于解决一些关于序列的问题，比如最长递增子序列、编辑距离等。
      - [最长上升子序列问题](https://leetcode.cn/problems/longest-increasing-subsequence/submissions/430135553/)
6. 区间 DP
      - [最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence/submissions/430171478/)
      - [石子游戏](https://leetcode.cn/problems/stone-game/submissions/430220611/)
7. 状压 DP
      - 旅行商问题
      - [优美的排列](https://leetcode.cn/problems/beautiful-arrangement/submissions/430278600/)
8. 数位 DP (dfs(int i,int state,bool is_limit,bool is_num)
      - [统计整数的数量](https://leetcode.cn/problems/count-of-integers/submissions/437570070/)
      - [1012. 至少有 1 位重复的数字](https://leetcode.cn/problems/numbers-with-repeated-digits/description/)
      - [233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one/submissions/437909738/)
      - [600. 不含连续1的非负整数](https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/submissions/438160324/)
      - [902. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/submissions/452354134/)
      - [2376. 统计特殊整数](https://leetcode.cn/problems/count-special-integers/submissions/452339066/)
      - [2801. 统计范围内的步进数字数目](https://leetcode.cn/problems/count-stepping-numbers-in-range/submissions/452043045/)
9. 树形 DP
      - 打家劫舍 III
      - 最小化旅行的价格总和
10. 数据结构优化DP
      -  [2713. 矩阵中严格递增的单元格数](https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix/submissions/436001561/)
      -  [2407.最长递增子序列II](https://leetcode.cn/problems/longest-increasing-subsequence-ii/submissions/436945876/)


## 树/图论
1. 树/二叉树
      - [lowest common ancestor](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)
      - [二叉树的前、中、后序遍历,非递归的实现](https://github.com/wxquare/programming/blob/master/oj/datastruct-algorithm/binary_tree.cpp)（12.21）
      - [二叉搜索树的查找、插入和删除](https://github.com/wxquare/programming/blob/master/oj/datastruct-algorithm/binary_search_tree.cpp)
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
4. [并查集模版](https://github.com/wxquare/online-algorithm-coding/blob/master/other/union_find.cc)
     - [547. 省份的数量](https://leetcode-cn.com/problems/number-of-provinces/)
     - [2709. 最大公约数遍历](https://leetcode.cn/problems/greatest-common-divisor-traversal/submissions/436245155/)
     - [1998. 数组的最大公因数排序](https://leetcode.cn/problems/gcd-sort-of-an-array/description/)
5. 最小生成树
      - [Kruskal](https://github.com/wxquare/online-algorithm-coding/blob/master/other/minimum_spanning_tree.cc)
      - [1584. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points/submissions/424543501/)
6. 基环树、内向树、外向数据
      - [2127. 参加会议的最多员工数](https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/submissions/453034664/)
      - [2360. 图中的最长环](https://leetcode.cn/problems/longest-cycle-in-a-graph/submissions/453037901/)
6. 图的最大环最小环
      - [图中的最短环,BFS有向图和无向图都可以](https://leetcode.cn/problems/shortest-cycle-in-a-graph/submissions/)
      - 无向图枚举点做BFS
      - 有向图枚举点做DFS
8. 欧拉回路/通路
      - [Reconstruct Itinerary](https://leetcode.cn/problems/reconstruct-itinerary/submissions/417006045/)
9. 连通量
      - [1489. 找到最小生成树里的关键边和伪关键边](https://leetcode.cn/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/submissions/419266120/)
      - [tarjan 求有向图的连通分量](https://github.com/wxquare/online-algorithm-coding/blob/master/other/tarjan.cc)
      - [2685. 统计完全连通分量的数量](https://leetcode.cn/problems/count-the-number-of-complete-components/submissions/432982804/)
      - https://www.cnblogs.com/Jr1Preg/p/12300735.html
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
      - 超级洗衣机
      - 查找集群内的关键连接
      - 找到最小生成树里的关键边和伪关键边

## 其它
- [1503. 所有蚂蚁掉下来前的最后一刻](https://leetcode.cn/problems/last-moment-before-all-ants-fall-out-of-a-plank/submissions/439537379/)
- [2731. 移动机器人](https://leetcode.cn/problems/movement-of-robots/submissions/439535180/))

## 参考
- [leetcode](https://leetcode.cn/)
- [灵茶山艾府](https://leetcode.cn/u/endlesscheng/)
- [宫水三叶](https://github.com/SharingSource/LogicStack-LeetCode)
- [代码随想录](https://github.com/youngyangyang04/leetcode-master)
- https://oi-wiki.org/
- https://zerotrac.github.io/leetcode_problem_rating/
- https://cp-algorithms.com/
