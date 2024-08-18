# leetcode-primer

<p align="center">
  <img src="/images/mind.png" width=600 height=800>
</p>


## 数据结构
1. 单链表/双链表(快慢指针)
      - [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)
      - [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)
      - [1721. 交换链表中的节点](https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list/)
      - [147. 对链表进行插入排序](https://leetcode.cn/problems/insertion-sort-list)
      - [148. 链表归并排序](https://leetcode.cn/problems/sort-list)

2. 二叉树
      - [144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal)
      - [94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal)
      - [145. 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal)
      - [236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree)
      - [117. 填充每个节点的下一个右侧节点指针 II](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii)
      - [2872. 可以被 K 整除连通块的最大数目](https://leetcode.cn/problems/maximum-number-of-k-divisible-components)
      - [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal)
      - [106. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal)
      - [2673. 使二叉树所有路径值相等的最小代价](https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree)
      - [2385. 感染二叉树需要的总时间](https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected)
      - [572. 另一棵树的子树](https://leetcode.cn/problems/subtree-of-another-tree)

3. stack/单调stack/双stack/（在线性时间内找到每个元素的上一个或者下一个更大或更小元素）
      - [496. 下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/)
      - [503. 下一个更大元素 II](https://leetcode-cn.com/problems/next-greater-element-ii/)
      - [739. 每日温度](https://leetcode.cn/problems/daily-temperatures)
      - [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence)
      - [2818. 操作使得分最大](https://leetcode.cn/problems/apply-operations-to-maximize-score)
      - [901. 股票价格跨度](https://leetcode.cn/problems/online-stock-span)
      - [2216. 美化数组的最少删除数](https://leetcode.cn/problems/minimum-deletions-to-make-array-beautifu)
      - [84. 柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram)
      - [42. 接雨水](https://leetcode.cn/problems/trapping-rain-water)
      - [907. 子数组的最小值之和](https://leetcode.cn/problems/sum-of-subarray-minimums)
      - [2866. 美丽塔 II](https://leetcode.cn/problems/beautiful-towers-ii)
      - [2865. 美丽塔 I](https://leetcode.cn/problems/beautiful-towers-i)
      
4. queue/双端deque/单调deque/priority_queue（单调队列通常用于解决滑动窗口问题，其中我们需要在滑动窗口内找到最大值或最小值）
      - [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum)
      - [862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k)
      - [2810. 故障键盘](https://leetcode.cn/problems/faulty-keyboard/)
      - [918. 环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray)
      - [最大平均通过率](https://leetcode-cn.com/problems/maximum-average-pass-ratio/)
      - [单线程 CPU](https://leetcode-cn.com/problems/single-threaded-cpu/)

6. 哈希unorderer_map/unordered_set

7. 平衡二叉树map/multimap/set/multimap

8. 前缀、后缀、左边和右边、一维和二维
      - [1423. 可获得的最大点数](https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards)
      - [2132. 用邮票贴满网格图](https://leetcode.cn/problems/stamping-the-grid/description/)(二维前缀和)
      - [1671. 得到山形数组的最少删除次数](https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array)
      - [3212. 统计 X 和 Y 频数相等的子矩阵数量](https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/)(二维)
      - [3152. 特殊数组 II](https://leetcode.cn/problems/special-array-ii)【prefix sum array】

9. 差分
      - [1109. Corporate Flight Bookings](https://leetcode.cn/problems/corporate-flight-bookings)
      - [1094. 拼车](https://leetcode.cn/problems/car-pooling/)
      - [2132. 用邮票贴满网格图](https://leetcode.cn/problems/stamping-the-grid/description/)（二维差分）

10. 树状数组
      - [307. Range Sum Query - Mutable](https://leetcode.cn/problems/range-sum-query-mutable)【单点加法（更新），求区间和】

11. 线段树(区间修改/区间add，求区间合、最值，区间内可以聚合的值）
      - 手撕线段树，支持区间update和区间聚合值（最大，最小、和）等
      - [2276. 统计区间中的整数数目](https://leetcode.cn/problems/count-integers-in-intervals)【线段树】
      - [699. 掉落的方块](https://leetcode.cn/problems/falling-squares)【区间更新，查询区间最大值】
      - [218. 天际线问题,区间更新，单点查询](https://leetcode.cn/problems/the-skyline-problem) 【区间更新、查询单点的值】
      - [2407.最长递增子序列II](https://leetcode.cn/problems/longest-increasing-subsequence-ii)【DP、线段树优化、 单点更新、区间最大值
      - [2916. 子数组不同元素数目的平方和 II](https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-ii)【线段树】

12. trie树
      - [Implement Trie (Prefix Tree)](https://leetcode.cn/problems/implement-trie-prefix-tree/)
      - [Implement Magic Dictionary](https://leetcode.cn/problems/implement-magic-dictionary)
      - [统计异或值在范围内的数对有多少](https://leetcode-cn.com/problems/count-pairs-with-xor-in-a-range/)

13. 字符串匹配 
      - [28. 找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string)
      - [3006. 找出数组中的美丽下标 I](https://leetcode.cn/problems/find-beautiful-indices-in-the-given-array-i)
      - [最长合法子字符串的长度 ac 自动机](https://leetcode.cn173370/)

13. 并查集
      - [并查集](https://github.com/wxquare/online-algorithm-coding/blob/master/other/union_find.cc)
      - [547. 省份的数量](https://leetcode-cn.com/problems/number-of-provinces/)
      - [684.冗余连接](https://leetcode.cn/problems/redundant-connection)
      - [721. 账户合并](https://leetcode.cn/problems/accounts-merge)
      - [924. 尽量减少恶意软件的传播](https://leetcode.cn/problems/minimize-malware-spread)
      - [1998. 数组的最大公因数排序](https://leetcode.cn/problems/gcd-sort-of-an-array)
      - [2709. 最大公约数遍历](https://leetcode.cn/problems/greatest-common-divisor-traversal)

14. 高级数据结构实现
      - [LRU](https://leetcode-cn.com/problems/lru-cache/)
      - [LFU](https://leetcode-cn.com/problems/lfu-cache/)
      - [HashSet 链地址法](https://leetcode-cn.com/problems/design-hashset/)
      - [HashMap 链地址法](https://leetcode-cn.com/problems/design-hashmap/)
      - [剑指 Offer 59 - II. 队列的最大值](https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof)
      - 跳表

15. 离线query
      - [2747. 统计没有收到请求的服务器数目](https://leetcode.cn/problems/count-zero-request-servers/)
      - [1851. 包含每个查询的最小区间](https://leetcode.cn/problems/minimum-interval-to-include-each-query)
      - [2940. 找到 Alice 和 Bob 可以相遇的建筑](https://leetcode.cn/problems/find-building-where-alice-and-bob-can-meet)


## 基本算法
1. 二分算法 (lower_bound,map.lower_bound,check 二分答案）
      - [有界数组中指定下标处的最大值](https://leetcode-cn.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/)
      - [1482. 制作 m 束花所需的最少天数](https://leetcode-cn.com/problems/minimum-number-of-days-to-make-m-bouquets/)
      - [打家劫舍VI，小偷的最大能力最小，二分+DP](https://leetcode.cn/problems/house-robber-iv)
      - [1901. 寻找峰值 II](https://leetcode.cn/problems/find-a-peak-element-ii)
      - [162. 寻找峰值](https://leetcode.cn/problems/find-peak-element)
      - [3007. 价值和小于等于 K 的最大数字](https://leetcode.cn/problems/maximum-number-that-sum-of-the-prices-is-less-than-or-equal-to-k)

2. 滑动窗口/双指针
      - [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum)
      - [862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k)
      - [30. 串联所有单词的子串](https://leetcode.cn/problems/substring-with-concatenation-of-all-words)
      - [2938. 区分黑球与白球](https://leetcode.cn/problems/separate-black-and-white-balls)
      - [统计最大元素出现至少 K 次的子数组](https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times)
      - [1793.好子数组的最大分数](https://leetcode-cn.com/problems/maximum-score-of-a-good-subarray/)
      - [1052. 爱生气的书店老板](https://leetcode.cn/problems/grumpy-bookstore-owner)
      - [2970. 统计移除递增子数组的数目 I](https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-i)
      - [42. 接雨水](https://leetcode.cn/problems/trapping-rain-water)【双指针接雨水，木桶效应】

4. 排序算法/top k/select kth
      - [面试题 17.09. 第 k 个数](https://leetcode.cn/problems/get-kth-magic-number-lcci/) 三指针，优先队列
      - [2512.奖励最顶尖的 K 名学生](https://leetcode.cn/problems/reward-top-k-students)
      - [912. 排序数组，快速排序和归并排序](https://leetcode.cn/problems/sort-an-array)
      - [147. 对链表进行插入排序](https://leetcode.cn/problems/insertion-sort-list)
      - [148. 链表归并排序](https://leetcode.cn/problems/sort-list)
      - [1329. 将矩阵按对角线排序](https://leetcode.cn/problems/sort-the-matrix-diagonally)

5. 枚举
      - [2735. 收集巧克力](https://leetcode.cn/problems/collecting-chocolates)

8. 分组/循环 (group/cycle arrray)
    	- [按照题目要求，数组会被分割成若干组，且每一组的判断/处理逻辑是一样的](https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold/solutions/2528771/jiao-ni-yi-ci-xing-ba-dai-ma-xie-dui-on-zuspx/)
      - [466. 统计重复个数](https://leetcode.cn/problems/count-the-repetitions)
      - [2808. 使循环数组所有元素相等的最少秒数](https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array)

9. 分组
      
10. 简单但易错题：
      - [2760. 最长奇偶子数组](https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold)

11. 贪心
      - [超级洗衣机](https://leetcode.cn/problems/super-washing-machines)
      - [课程表3(反悔贪心,排序、最大堆)](https://leetcode.cn/problems/course-schedule-iii)
      - [2171 拿出最少数目的魔法豆](https://leetcode.cn/problems/removing-minimum-number-of-magic-beans)
      - [2009. 使数组连续的最少操作数](https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-continuous)
      - [1702. 修改后的最大二进制字符串](https://leetcode.cn/problems/maximum-binary-string-after-change)
      - [2007. 从双倍数组中还原原数组](https://leetcode.cn/problems/find-original-array-from-doubled-array)
      - [3111. 覆盖所有点的最少矩形数目](https://leetcode.cn/problems/minimum-rectangles-to-cover-points)【排序+贪心】
      - [2731. 移动机器人](https://leetcode.cn/problems/movement-of-robots)
      - [2897. 对数组执行操作使平方和最大](https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares)【平方和贪心，和的平方>=平方和】

## 数学
1. 数论问题
      - [判断是否是素数（质数）](https://github.com/wxquare/online-algorithm-coding/blob/master/other/primes.cc)
      - [求1-n之间的所有素数，素数筛选法](https://github.com/wxquare/online-algorithm-coding/blob/master/other/primes.cc)
      - 分解质因数  
      - [求多个数的公共质因子](https://github.com/wxquare/online-algorithm-coding/blob/master/other/primes.cc)
      - [两数、多数最大公约数](https://github.com/wxquare/online-algorithm-coding/blob/master/other/primes.cc)
      - [两数、多数最小公倍数](https://github.com/wxquare/online-algorithm-coding/blob/master/other/primes.cc)
      - [2709. 最大公约数遍历](https://leetcode.cn/problems/greatest-common-divisor-traversal)
      - [2698. 求一个整数的惩罚数](https://leetcode.cn/problems/find-the-punishment-number-of-an-integer)
      - [1998. 数组的最大公因数排序](https://leetcode.cn/problems/gcd-sort-of-an-array)

2. 模运算
      - (a + b) mod c = ((a mod c) + (b mod c)) mod c
      - (a * b) mod c =  ((a mod c) * (b mod c)) mod c
      - (a / b) mod c =  (a * (b^(-1))) mod c，其中 b^(-1) 是 b 的乘法逆元。如果 c 是一个素数，且 b 是不可被 c 整除的整数，那么 b 的乘法逆元（b模c的逆元）可以通过以下方式计算：b^(-1) ≡ b^(c-2) (mod c)
      - [2842. 统计一个字符串的 k 子序列美丽值最大的数目](https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty)
      - 乘法逆元，扩展欧几里得算法
      - 费马定理

3. 位运算
      - 利用了 num & (num - 1) 的性质，可以快速消除 num 二进制表示中最右边的1
      - lowbit(x) = x & (-x),快速获取最右侧1的位置的树，例如lowbit(6) = (110) = 2,lowbit(12) = (1100) = 4 
      - (x & (1 << i)) == 0
      - 异或运算: 0^0=0,0^1=1,1^1=0,
      - __builtin_clz, count leading zero
      - __builtin_ctz, count trainling zero
      - __builtin_popcount, population count
      - [260. 只出现一次的数字 I、II、III](https://leetcode.cn/problems/single-number-iii)
      - [421. 数组中两个数的最大异或值](https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array)
      - [所有数对按位与结果的异或和](https://leetcode-cn.com/problems/find-xor-sum-of-all-pairs-bitwise-and/)
      - [318. 最大单词长度乘积](https://leetcode.cn/problems/maximum-product-of-word-lengths)
      - [2939. 最大异或乘积](https://leetcode.cn/problems/maximum-xor-product)
      - [2397. 被列覆盖的最多行数](https://leetcode.cn/problems/maximum-rows-covered-by-columns)
      - [2897. 对数组执行操作使平方和最大](https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares)[操作题、位运算、贪心]

3. 拒绝抽样(rejection sampling)
      - [用 Rand7() 实现 Rand10()](https://leetcode.cn/problems/implement-rand10-using-rand7)

4. 水塘抽样
      - [382. 链表随机节点](https://leetcode.cn/problems/linked-list-random-node/description/)
      - [398. 随机数索引](https://leetcode.cn/problems/random-pick-index)
      - [reservoirSampling](https://github.com/wxquare/online-algorithm-coding/blob/master/other/math.cc)

5. 洗牌算法
      - [384. 打乱数组](https://leetcode.cn/problems/shuffle-an-array)

6. 快速幂
      - [50. Pow(x, n)](https://leetcode.cn/problems/powx-n)
      - [372. 超级次方](https://leetcode.cn/problems/super-pow) （快速幂和模运算）
      - [2961.双模幂运算](https://leetcode.cn/problems/double-modular-exponentiation)

7. 排列组合数学取模(大数取模)
     - 求c(n,k),大数c(n,k,mod)
     - [31. 下一个排列](https://leetcode.cn/problems/next-permutation/)
     - [556. 下一个更大元素 III](https://leetcode-cn.com/problems/next-greater-element-iii/)
     - [2842. 统计一个字符串的 k 子序列美丽值最大的数目](https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty)
     - [2930. 重新排列后包含指定子字符串的字符串数目](https://leetcode.cn/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/)
     - [统计感冒序列的数目](https://leetcode.cn/problems/count-the-number-of-infection-sequences)
     - 正着困难反着求（容斥原理）
     - [3154. 到达第 K 级台阶的方案数](https://leetcode.cn/problems/find-number-of-ways-to-reach-the-k-th-stair/)

8. 容斥原理

9. 区间合并
      - [56. 合并区间](https://leetcode.cn/problems/merge-intervals)
      - [2580. 统计将重叠区间合并成组的方案数](https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges)

10. 几何运算（距离：距离、欧式距离、曼哈顿距离、切比雪夫距离）
      - 曼哈顿距离和切比雪夫距离变换 d(A,B) = max(|x1-y1 - (x2-y2)|,|x1+y1-(x2+y2)|)
      - [3102. 最小化曼哈顿距离](https://leetcode.cn/problems/minimize-manhattan-distances)

## 搜索问题
1. BFS
      - 一维、二维网格、树、图
      - BFS/多源BFS（源点为多个）/双向BFS/ BFS + 优先队列
      - [2812. 找出最安全路径，多源BFS](https://leetcode.cn/problems/find-the-safest-path-in-a-grid) 
      - [407. 接雨水 II](https://leetcode.cn/problems/trapping-rain-water-ii/description/)
      - [2258. 逃离火灾](https://leetcode.cn/problems/escape-the-spreading-fire/)
      - [2477. 到达首都的最少油耗](https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital)


2. DFS/剪枝/回溯（深度搜索+限制条件+限制搜索路径）
      - 一维、二维网格、树、图
      - [39. 组合总和](https://leetcode.cn/problems/combination-sum)
      - [113. 路径总和 II](https://leetcode.cn/problems/path-sum-ii)(回溯模版题)
      - [LCR 086. 分割回文串](https://leetcode.cn/problems/M99OJA)
      - [面试题 08.12. 八皇后 n皇后问题](https://leetcode.cn/problems/eight-queens-lcci)
      - [928. 尽量减少恶意软件的传播 II](https://leetcode.cn/problems/minimize-malware-spread-ii)
      - [2850. 将石头分散到网格图的最少移动次数](https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid)
      - [2698. 求一个整数的惩罚数，预处理+回溯](https://leetcode.cn/problems/find-the-punishment-number-of-an-integer)
      - [3211. 生成不含相邻零的二进制字符串](https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros)
      - [2101. 引爆最多的炸弹](https://leetcode.cn/problems/detonate-the-maximum-bombs)

3. 启发式搜索
      - 八数码问题


## DP问题（递推类DP）
1. 线性 DP （包括状态机DP，序列DP,子问题有一个端点是固定不变的）
      1. 线性DP
            - [斐波那契数列](https://leetcode.cn/problems/fibonacci-number)
            - [LCR 168. 第n个丑数](https://leetcode.cn/problems/chou-shu-lcof/description/)
            - [数字三角形](https://leetcode.cn/problems/triangle)
            - [跳跃游戏1，2，3，4](https://leetcode.cn/problems/jump-game)
            - [2708. 一个小组的最大实力值](https://leetcode.cn/problems/maximum-strength-of-a-group)
            - [销售利润最大化](https://leetcode.cn/problems/maximize-the-profit-as-the-salesman)
            - [42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/description/)
            - [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray)
            - [1997. 访问完所有房间的第一天](https://leetcode.cn/problems/first-day-where-you-have-been-in-all-the-rooms)
      2. 状态机DP（关键是设计状态以及状态转移方程，之后在处理边界条件）
            - 打家劫舍（1.普通、2.环形、3.树形DP、4.DP+二分）
            - [将三个数组的排序](https://leetcode.cn/problems/sorting-three-groups)
            - 买卖股票的最大利润（最多一次买卖、最多两次、最多K次、无限次买卖、冷冻期1天、手续费）
            - [552. 学生出勤记录 II](https://leetcode.cn/problems/student-attendance-record-ii)【三维】
      3. 序列DP (序列DP是动态规划中的一种常见形式，通常用于解决一些关于序列的问题，比如最长递增子序列、编辑距离等)
            - [300. 最长上升子序列问题 LIS](https://leetcode.cn/problems/longest-increasing-subsequence)
            - [最长公共子序列（LCS）](https://leetcode.cn/problems/longest-common-subsequence)
            - [将一个字符串分割成回文串，最少分割次数](https://leetcode.cn/problems/omKAoA/)
            - [2901. 最长相邻不相等子序列 II](https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii)
            - [5.最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)
            - [2915. 和为目标值的最长子序列的长度](https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target)
            - [3098. 求出所有子序列的能量和](https://leetcode.cn/problems/find-the-sum-of-subsequence-powers)
            - [最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence)
            - [72. 编辑距离](https://leetcode.cn/problems/edit-distance/)
      4. 数组DP dp[i][j] 
            - [3130. 找出所有稳定的二进制数组 II](https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-ii)【dp[i][j][2] 以0或者1结尾的方案数】
            - [3251. 单调数组对的数目 II](https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-ii)【dp[i][j],前i个数，以j结尾的方案数】

      4. DP回溯 (很多时候只是求DP最值，但有时需要回溯DP的过程)
            - [689. 三个无重叠子数组的最大和](https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays)
     
      5. 网格，矩阵DP
            - [221. 最大正方形](https://leetcode.cn/problems/maximal-square)
            - [3148. 矩阵中的最大得分](https://leetcode.cn/problems/maximum-difference-score-in-a-grid)

2. 背包 DP
      - 01背包
      - [494. 目标和](https://leetcode.cn/problems/target-sum)
      - 完全背包
      - [322. 零钱兑换](https://leetcode.cn/problems/coin-change/)
      - [518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-ii)
      - 多重背包
      - [1155. 掷骰子等于目标和的方法数](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum)
      - 分组背包


3. 区间 DP （子问题向内缩小，两端都会向内移动）
      - [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring/)
      - [最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence)
      - [石子游戏](https://leetcode.cn/problems/stone-game)

4. bitmask，状压 和 状态压缩DP,bitmask vs map+vector （把集合用二进制表示,二进制mask 1<<n）
      - [526.优美的排列](https://leetcode.cn/problems/beautiful-arrangement)
      - [638. 大礼包](https://leetcode.cn/problems/shopping-offers)
      - [691. 贴纸拼词](https://leetcode.cn/problems/stickers-to-spell-word)
      - [2741. 特别的排列](https://leetcode.cn/problems/special-permutations)


5. 树形 DP （子树天然地形成子问题，需要考虑dp的信息是怎么从子树传给上面的子树的，记忆化搜索，递归。就是我们已经知道以uuu为根的答案，想要通过u−>v的父子关系把答案传递）

      1. 树上最大独立集 (不选相连的节点)
            - [337. 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii)
            - [2646. 最小化旅行的价格总和](https://leetcode.cn/problems/minimize-the-total-price-of-the-trips)

      - [2920. 收集所有金币可获得的最大积分](https://leetcode.cn/problems/maximum-points-after-collecting-coins-from-all-nodes/)
      - [2925. 在树上执行操作以后得到的最大分数](https://leetcode.cn/problems/maximum-score-after-applying-operations-on-a-tree)
      - [894. 所有可能的真二叉树](https://leetcode.cn/problems/all-possible-full-binary-trees)
      - 树的直径和路径问题
      - [3203. 合并两棵树后的最小直径](https://leetcode.cn/problems/find-minimum-diameter-after-merging-two-trees)
      1. 定根DP，一次扫描
            - [543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree/description/)
            - [124. 二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum)
            - [687. 最长同值路径](https://leetcode.cn/problems/longest-univalue-path)
            - [2246. 相邻字符不同的最长路径](https://leetcode.cn/problems/longest-path-with-different-adjacent-characters)
      2. 换根DP，二次扫描法
            - [834. 树中距离之和](https://leetcode.cn/problems/sum-of-distances-in-tree)
            - [2581. 统计可能的树根数目](https://leetcode.cn/problems/count-number-of-possible-root-nodes)
            - [2858. 可以到达每一个节点的最少边反转次数](https://leetcode.cn/problems/minimum-edge-reversals-so-every-node-is-reachable)
            - [3241. 标记所有节点需要的时间](https://leetcode.cn/problems/time-taken-to-mark-all-nodes)


6. 数位 DP (dfs(int i,int state,bool is_limit,bool is_num)
      - [233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one)【dfs = [&](int i,int cnt,int is_limit)】
      - [600. 二进制不含连续1的非负整数](https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones)【数位DP】
      - [902. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set)【dfs = [&](int i,bool is_limit,bool is_num)】
      - [1012. 至少有 1 位重复的数字](https://leetcode.cn/problems/numbers-with-repeated-digits)【dfs = [&](int i,int mask,bool is_limit,bool is_num)】
      - [2376. 统计特殊整数](https://leetcode.cn/problems/count-special-integers)【dfs = [&](int i,int mask,bool is_limit,bool is_num)】
      - [2801. 统计范围内的步进数字数目](https://leetcode.cn/problems/count-stepping-numbers-in-range)【dfs = [&](int i,int pre,bool is_limit,bool is_num)->int】
      - [2827. 范围中美丽整数的数目](https://leetcode.cn/problems/number-of-beautiful-integers-in-the-range)
      - [2719. 统计整数数目](https://leetcode.cn/problems/count-of-integers/)

7. 数据结构优化DP
      - [2713. 矩阵中严格递增的单元格数](https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix)
      - [2407.最长递增子序列II](https://leetcode.cn/problems/longest-increasing-subsequence-ii/submissions)
      - [2926. 平衡子序列的最大和](https://leetcode.cn/problems/maximum-balanced-subsequence-sum/)

8. 倍增和倍增优化DP
      - [2836. 在传球游戏中最大化函数值](https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game)
      - [1483. 树节点的第 K 个祖先](https://leetcode.cn/problems/kth-ancestor-of-a-tree-node)
      - lca
      - [2846. 边权重均等查询](https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree)

9. 矩阵快速幂优化DP
      - [2851. 字符串K次转换等于目标串的方案数量](https://leetcode.cn/problems/string-transformation/submissions465291899/)

6. 记忆化搜索 （动态规划，状态优化，求方案数量）
      - [2742. 给墙壁刷油漆，状态优化](https://leetcode.cn/problems/painting-the-walls)
      - [2707. 字符串中的额外字符](https://leetcode.cn/problems/extra-characters-in-a-string)
      - [2597. 美丽子集的数目](https://leetcode.cn/problems/the-number-of-beautiful-subsets)
      - [2811. 判断是否能拆分数组](https://leetcode.cn/problems/check-if-it-is-possible-to-split-array/description/)
      - [996. 正方形数组的数目，预处理/重复数字全排列](https://leetcode.cn/problems/number-of-squareful-arrays)
      - [2741. 特别的排列，全排列/剪枝](https://leetcode.cn/problems/special-permutations)
      - [2896. 执行操作使两个字符串相等](https://leetcode.cn/problems/apply-operations-to-make-two-strings-equal)
      - [2003. 每棵子树内缺失的最小基因值](https://leetcode.cn/problems/smallest-missing-genetic-value-in-each-subtree/)
      - [72. 编辑距离](https://leetcode.cn/problems/edit-distance)
      - [3154. 到达第 K 级台阶的方案数](https://leetcode.cn/problems/find-number-of-ways-to-reach-the-k-th-stair/)
      - [3129. 找出所有稳定的二进制数组 I](https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-i)
        
## 树/图论
1. [最短路径和K短问题](https://github.com/wxquare/online-algorithm-coding/blob/master/other/graph_short_path.cc)
      - BFS（单源，无权路，权值为1的最短路，O(n)）
      - Dijkstra（单源，权值为正,O((E)logE))
      - Ballmanford （单源，n-1次松驰，,权值可正可负，可用于检测负环,O(V*E))
      - Floyd（多源，任意两点的距离，O(n^3))
      - [743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time)
      - [1334. 阈值距离内邻居最少的城市](https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance)
      - [A* 八数码问题](https://github.com/wxquare/online-algorithm-coding/blob/master/other/8-puzzle.cc)
      - [2045. 到达目的地的第二短时间](https://leetcode.cn/problems/second-minimum-time-to-reach-destination)
      - [1976. 到达目的地的方案数](https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination)
      - [2642. 设计可以求最短路径的图类](https://leetcode.cn/problems/design-graph-with-shortest-path-calculator)
      - [2065. 最大化一张图中的路径价值](https://leetcode.cn/problems/maximum-path-quality-of-a-graph/description/)
      - [2959.关闭分部的可行集合数目](https://leetcode.cn/problems/number-of-possible-sets-of-closing-branche)
      - [3112. 访问消失节点的最少时间](https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes)

2. [拓扑排序和度](https://github.com/wxquare/online-algorithm-coding/blob/master/other/topological.cc)
     - [207. 课程表](https://leetcode-cn.com/problems/course-schedule/)
     - [210. 课程表 II](https://leetcode-cn.com/problems/course-schedule-ii/)
     - [2603. 收集树中金币](https://leetcode.cn/problems/collect-coins-in-a-tree)

3. 最小生成树
      - [Kruskal](https://github.com/wxquare/online-algorithm-coding/blob/master/other/minimum_spanning_tree.cc)
      - [1584. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points)

4. 基环树、内向树、外向树
      - [2127. 参加会议的最多员工数](https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting)
      - [2360. 图中的最长环](https://leetcode.cn/problems/longest-cycle-in-a-graph)
      - [2876. 有向图访问计数](https://leetcode.cn/problems/count-visited-nodes-in-a-directed-graph环最小环)
      - [图中的最短环,BFS有向图和无向图都可以](https://leetcode.cn/problems/shortest-cycle-in-a-无向图枚举点做BFS)
      - 有向图枚举点做DFS

6. 欧拉回路/通路
      - [Reconstruct Itinerary](https://leetcode.cn/problems/reconstruct-itinerary)

7. 图的连通性
      - [1489. 找到最小生成树里的关键边和伪关键边](https://leetcode.cn/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree)
      - [2685. 统计完全连通分量的数量](https://leetcode.cn/problems/count-the-number-of-complete-components)
      - [查找集群内的关键连接](https://leetcode.cn/problems/critical-connections-in-a-network)
      - tarjan 求强连通分量 模版
      - tarjan 求割点 模版
      - tartan 求割边 模版

8. 寻找符合条件的路径
      - [6942. 树中可以形成回文的路径数](https://leetcode.cn/problems/count-paths-that-can-form-a-palindrome-in-a-tree)

9. 二分图问题
      - [染色分二分图判定是否存在基环，785. 判断二分图](https://leetcode.cn/problems/is-graph-bipartite)
      - 二分图最大匹配，匈牙利增广路算法

10. 网络流
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
- https://leetcode.cn/circle/discuss/tXLS3i/
