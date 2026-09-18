# leetcode-primer

## 导航

- [学习路线入口](../guides/roadmap/00-start-here.md)
- [完整 LeetCode 题单](../guides/indexes/leetcode-problems.md)
- [按主题索引](../guides/indexes/problems-by-topic.md)
- [按模式索引](../guides/indexes/problems-by-pattern.md)
- [按难度索引](../guides/indexes/problems-by-difficulty.md)
- [按来源索引](../guides/indexes/problems-by-source.md)
- 本目录角色：LeetCode 题解的本地目录，长目录保留为题目查找入口，源码按主要解法归档在下方七个主题目录。

## 数据结构

### 1. 数组与矩阵 (核心模式归类)

#### 1.1 旋转、反转与原地重排（$O(1)$ 额外空间）
- [48. 旋转图像](https://leetcode.cn/problems/rotate-image)【转置 + 水平翻转】
- [61. 旋转链表](https://leetcode.cn/problems/rotate-list)【成环解环；先连成环再在 $n-(k\%n)$ 处断开】
- [189. 轮转数组](https://leetcode.cn/problems/rotate-array)【三次翻转实现原地位移】
- [151. 反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string)【双指针 + 局部翻转】
- [283. 移动零](https://leetcode.cn/problems/move-zeroes)【快慢指针原地压缩】
- [88. 合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array)【从后向前双指针写入】
- [31. 下一个排列](https://leetcode.cn/problems/next-permutation)【找 pivot，再交换并反转后缀】
- [41. 缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive)【原地置换；将值放回对应下标】
- [54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix)【四边界收缩；$O(1)$ 额外空间遍历】
- [73. 矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes)【首行首列复用为标记位】
- [79. 单词搜索](https://leetcode.cn/problems/word-search)【临时改写网格标记访问，再恢复】
- [130. 被围绕的区域](https://leetcode.cn/problems/surrounded-regions)【从边界出发原地标记】
- [200. 岛屿数量](https://leetcode.cn/problems/number-of-islands)【DFS/BFS 沉岛，直接改写网格】
- [289. 生命游戏](https://leetcode.cn/problems/game-of-life)【位编码同时保存旧状态和新状态】
- [448. 找到所有数组中消失的数字](https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array)【原地负号标记】

#### 1.2 缺失、重复、唯一与峰值，多数

- [41. 缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive)【原地置换；将值放回对应下标】
- [268. 丢失的数字](https://leetcode.cn/problems/missing-number)【异或或等差求和】
- [448. 找到所有数组中消失的数字](https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array)【原地负号标记】
- [2028. 找出缺失的观测数据](https://leetcode.cn/problems/find-missing-observations)【总和约束下的余数分配】
- [136. 只出现一次的数字](https://leetcode.cn/problems/single-number)【异或抵消】
- [137. 只出现一次的数字 II](https://leetcode.cn/problems/single-number-ii)【位运算；逐位统计出现次数并对 3 取模恢复唯一数字】
- [260. 只出现一次的数字 III](https://leetcode.cn/problems/single-number-iii)【整体异或后按 lowbit 分组】
- [217. 存在重复元素](https://leetcode.cn/problems/contains-duplicate)【哈希集合判重】
- [219. 存在重复元素 II](https://leetcode.cn/problems/contains-duplicate-ii)【固定窗口哈希】
- [220. 存在重复元素 III](https://leetcode.cn/problems/contains-duplicate-iii)【滑动窗口 + 有序集合】
- [287. 寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number)【快慢指针找环】
- [169. 多数元素](https://leetcode.cn/problems/majority-element)【摩尔投票法；抵消不同元素后，剩余候选即出现次数超过一半的元素】
- [229. 多数元素 II](https://leetcode.cn/problems/majority-element-ii)【摩尔投票法；维护两个候选与计数，再二次验证出现次数超过 `n / 3` 的元素】
- [128. 最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence)【哈希集合；仅从连续段起点扩展】
- [162. 寻找峰值](https://leetcode.cn/problems/find-peak-element)【局部单调二分】
- [1901. 寻找峰值 II](https://leetcode.cn/problems/find-a-peak-element-ii)【二维二分】

#### 1.3 两数之和与 K 数之和
- [1. 两数之和](https://leetcode.cn/problems/two-sum)【哈希表记录已遍历元素】
- [15. 三数之和](https://leetcode.cn/problems/3sum)【排序 + 固定一数 + 双指针去重】
- [16. 最接近的三数之和](https://leetcode.cn/problems/3sum-closest)【排序 + 双指针维护最小差值】
- [18. 四数之和](https://leetcode.cn/problems/4sum)【排序 + 两层枚举 + 双指针去重】
- [167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted)【有序数组对撞双指针】
- [454. 四数相加 II](https://leetcode.cn/problems/4sum-ii)【两两配对和 + 哈希表】
- [653. 两数之和 IV - 输入 BST](https://leetcode.cn/problems/two-sum-iv-input-is-a-bst)【遍历 BST + 哈希集合】
- [923. 三数之和的多种可能](https://leetcode.cn/problems/3sum-with-multiplicity)【排序/计数 + 组合计数】
- [1679. K 和数对的最大数目](https://leetcode.cn/problems/max-number-of-k-sum-pairs)【哈希计数或排序双指针】
- [2824. 统计和小于目标的下标对数目](https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target)【排序 + 双指针计数】

#### 1.4 区间问题（合并、贪心、差分与范围查询）

##### 1.4.1 合并、插入与贪心决策
- [56. 合并区间](https://leetcode.cn/problems/merge-intervals)【模式：区间合并；核心：按起点排序，维护 `[L, R]`，利用 `l <= cur_right` 动态扩展右边界】
- [57. 插入区间](https://leetcode.cn/problems/insert-interval)【模式：分类讨论；核心：将区间分为“左侧不重叠”、“中间重叠合并”、“右侧不重叠”三部分处理】
- [228. 汇总区间](https://leetcode.cn/problems/summary-ranges)【模式：分组循环 / 双指针；核心：识别连续数字序列的断点】
- [252. 会议室](https://leetcode.cn/problems/meeting-rooms)【按开始时间排序；相邻区间的前一结束时间晚于后一开始时间即发生重叠】
- [253. 会议室 II](https://leetcode.cn/problems/meeting-rooms-ii)【模式：上下车/差分思想；核心：将起点看作 +1，终点看作 -1，求最大并发数；或利用小顶堆维护当前结束时间】
- [435. 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals)【模式：贪心留空；核心：按终点排序，尽量保留先结束的区间，以给后续留出更多空间】
- [452. 用最少数量的箭引爆气球](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons)【模式：区间交集；核心：按终点排序，贪心选择重叠区域的边缘】
- [1851. 包含每个查询的最小区间](https://leetcode.cn/problems/minimum-interval-to-include-each-query)【排序查询 + 最小堆维护候选区间】
- [2580. 统计将重叠区间合并成组的方案数](https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges)【模式：区间合并 + 组合数学；核心：合并后得到 m 个独立连通块，结果为 $2^m$】
- [3111. 覆盖所有点的最少矩形数目](https://leetcode.cn/problems/minimum-rectangles-to-cover-points)【按横坐标排序，尽可能延长当前覆盖范围】

##### 1.4.2 差分：区间批量更新

- [995. K 连续位的最小翻转次数](https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips)【差分；记录长度为 `k` 的翻转影响范围】
- [1094. 拼车](https://leetcode.cn/problems/car-pooling)【差分；按站点累计上下车人数】
- [1109. 航班预订统计](https://leetcode.cn/problems/corporate-flight-bookings)【一维差分；区间端点标记后一次还原】
- [2132. 用邮票贴满网格图](https://leetcode.cn/problems/stamping-the-grid)【二维差分】

##### 1.4.3 范围查询与更新：树状数组、线段树

- [307. Range Sum Query - Mutable](https://leetcode.cn/problems/range-sum-query-mutable)【树状数组；单点更新与区间和查询】
- [218. 天际线问题](https://leetcode.cn/problems/the-skyline-problem)【线段树；区间更新、单点查询】
- [699. 掉落的方块](https://leetcode.cn/problems/falling-squares)【线段树；区间最大值查询与区间更新】
- [2276. 统计区间中的整数数目](https://leetcode.cn/problems/count-integers-in-intervals)【动态开点线段树；区间更新与聚合】
- [2916. 子数组不同元素数目的平方和 II](https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-ii)【线段树】
- [3479. 将水果装入篮子 III](https://leetcode.cn/problems/fruits-into-baskets-iii)【线段树；单点更新与区间最大值查询】

#### 1.5 子数组
- [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray)【Kadane 算法】
- [152. 乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray)【维护最大值和最小值】
- [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum)【正数数组滑动窗口；窗口和达到目标后收缩左边界以更新最短长度】
- [560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k)【前缀和 + 哈希表】
- [689. 三个无重叠子数组的最大和](https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays)【动态规划】
- [862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k)【前缀和 + 单调队列】
- [907. 子数组的最小值之和](https://leetcode.cn/problems/sum-of-subarray-minimums)【单调栈 + 贡献法】
- [918. 环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray)【Kadane 算法变形】
- [1793. 好子数组的最大分数](https://leetcode.cn/problems/maximum-score-of-a-good-subarray)【双指针/贪心】
- [2760. 最长奇偶子数组](https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold)【枚举/分组】
- [2962. 统计最大元素出现至少 K 次的子数组](https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times)【滑动窗口】
- [2970. 统计移除递增子数组的数目 I](https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-i)【双指针】

#### 1.6 子序列
- [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence)【二分 + 贪心】
- [392. 判断子序列](https://leetcode.cn/problems/is-subsequence)【双指针】
- [516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence)【动态规划】
- [1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence)【动态规划】
- [2407. 最长递增子序列 II](https://leetcode.cn/problems/longest-increasing-subsequence-ii)【线段树优化】
- [2842. 统计一个字符串的 k 子序列美丽值最大的数目](https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty)【组合数学】
- [2901. 最长相邻不相等子序列 II](https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii)【动态规划】
- [2915. 和为目标值的最长子序列的长度](https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target)【动态规划】
- [2926. 平衡子序列的最大和](https://leetcode.cn/problems/maximum-balanced-subsequence-sum)【动态规划】
- [3098. 求出所有子序列的能量和](https://leetcode.cn/problems/find-the-sum-of-subsequence-powers)【动态规划】
- [3404. 统计特殊子序列的数目](https://leetcode.cn/problems/count-special-subsequences)【枚举/哈希表】

#### 1.7 二维矩阵
- [36. 有效的数独](https://leetcode.cn/problems/valid-sudoku)【行、列与九宫格状态统计】
- [48. 旋转图像](https://leetcode.cn/problems/rotate-image)【转置 + 水平翻转】
- [51. N 皇后](https://leetcode.cn/problems/n-queens)【棋盘回溯 + 列与对角线标记】
- [52. N 皇后 II](https://leetcode.cn/problems/n-queens-ii)【棋盘回溯计数】
- [54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix)【四边界收缩】
- [73. 矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes)【首行首列标记】
- [74. 搜索二维矩阵](https://leetcode.cn/problems/search-a-2d-matrix)【二分查找】
- [79. 单词搜索](https://leetcode.cn/problems/word-search)【网格回溯 + 原地标记】
- [120. 三角形最小路径和](https://leetcode.cn/problems/triangle)【二维动态规划】
- [130. 被围绕的区域](https://leetcode.cn/problems/surrounded-regions)【边界 DFS/BFS 标记】
- [200. 岛屿数量](https://leetcode.cn/problems/number-of-islands)【网格 DFS/BFS】
- [212. 单词搜索 II](https://leetcode.cn/problems/word-search-ii)【Trie + 网格回溯】
- [221. 最大正方形](https://leetcode.cn/problems/maximal-square)【二维动态规划】
- [1277. 统计全为 1 的正方形子矩阵](https://leetcode.cn/problems/count-square-submatrices-with-all-ones)【二维 DP；以当前位置为右下角的最大边长累加到答案】
- [240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii)【右上角起步的线性搜索】
- [289. 生命游戏](https://leetcode.cn/problems/game-of-life)【原地状态编码】
- [305. 岛屿数量 II](https://leetcode.cn/problems/number-of-islands-ii)【二维坐标 + 并查集】
- [407. 接雨水 II](https://leetcode.cn/problems/trapping-rain-water-ii)【优先队列 BFS】
- [909. 蛇梯棋](https://leetcode.cn/problems/snakes-and-ladders)【二维坐标映射 + BFS】
- [1329. 将矩阵按对角线排序](https://leetcode.cn/problems/sort-the-matrix-diagonally)【按对角线分组排序】
- [1901. 寻找峰值 II](https://leetcode.cn/problems/find-a-peak-element-ii)【二维二分】
- [2132. 用邮票贴满网格图](https://leetcode.cn/problems/stamping-the-grid)【二维前缀和 + 差分】
- [2258. 逃离火灾](https://leetcode.cn/problems/escape-the-spreading-fire)【网格多源 BFS + 二分】
- [2713. 矩阵中严格递增的单元格数](https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix)【动态规划】
- [2812. 找出最安全路径](https://leetcode.cn/problems/find-the-safest-path-in-a-grid)【网格多源 BFS】
- [2850. 将石头分散到网格图的最少移动次数](https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid)【状态压缩搜索】
- [3127. 构造相同颜色的正方形](https://leetcode.cn/problems/make-a-square-with-the-same-color)【枚举 2×2 子矩阵】
- [3148. 矩阵中的最大得分](https://leetcode.cn/problems/maximum-difference-score-in-a-grid)【动态规划】
- [85. 最大矩形](https://leetcode.cn/problems/maximal-rectangle)【柱状图转化；逐行累积高度后用单调栈求最大矩形】
- [3212. 统计 X 和 Y 频数相等的子矩阵数量](https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y)【二维前缀和】

#### 1.8 回文
- [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring)【中心扩展或 Manacher】
- [9. 回文数](https://leetcode.cn/problems/palindrome-number)【反转后一半数字，避免整数溢出】
- [LCR 086. 分割回文串](https://leetcode.cn/problems/M99OJA)【回溯枚举 + 回文判定】
- [LCR 094. 少回文分割](https://leetcode.cn/problems/omKAoA)【回文预处理 + 动态规划】
- [266. 判断一个字符串是否是回文排列](https://leetcode.cn/problems/palindrome-permutation)【统计奇数频次】
- [409. 最长回文串](https://leetcode.cn/problems/longest-palindrome)【贪心使用成对字符】
- [516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence)【区间动态规划】
- [6942. 树中可以形成回文的路径数](https://leetcode.cn/problems/count-paths-that-can-form-a-palindrome-in-a-tree)【位掩码记录字符奇偶性】

#### 1.9 字符串
- [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters)【滑动窗口 + 哈希表】
- [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring)【中心扩展或 Manacher】
- [20. 有效的括号](https://leetcode.cn/problems/valid-parentheses)【栈匹配】
- [22. 括号生成](https://leetcode.cn/problems/generate-parentheses)【回溯 + 括号余额】
- [28. 找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string)【KMP】
- [30. 串联所有单词的子串](https://leetcode.cn/problems/substring-with-concatenation-of-all-words)【分组滑动窗口 + 词频统计】
- [49. 字母异位词分组](https://leetcode.cn/problems/group-anagrams)【排序或频次作为哈希键】
- [65. 有效数字](https://leetcode.cn/problems/valid-number)【有限状态模拟】
- [71. 简化路径](https://leetcode.cn/problems/simplify-path)【栈 + 字符串分割】
- [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring)【滑动窗口 + 频次计数】
- [LCR 086. 分割回文串](https://leetcode.cn/problems/M99OJA)【回溯 + 回文判定】
- [LCR 094. 少回文分割](https://leetcode.cn/problems/omKAoA)【动态规划】
- [97. 交错字符串](https://leetcode.cn/problems/interleaving-string)【字符串DP】
- [127. 单词接龙](https://leetcode.cn/problems/word-ladder)【双向 BFS + 中间状态】
- [151. 反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string)【双指针 + 局部翻转】
- [205. 同构字符串](https://leetcode.cn/problems/isomorphic-strings)【双向字符映射】
- [208. 实现 Trie（前缀树）](https://leetcode.cn/problems/implement-trie-prefix-tree)【前缀树】
- [211. 添加与搜索单词](https://leetcode.cn/problems/design-add-and-search-words-data-structure)【Trie + DFS】
- [212. 单词搜索 II](https://leetcode.cn/problems/word-search-ii)【Trie + 网格回溯】
- [242. 有效的字母异位词](https://leetcode.cn/problems/valid-anagram)【字符频次计数】
- [266. 判断一个字符串是否是回文排列](https://leetcode.cn/problems/palindrome-permutation)【统计奇数频次】
- [290. 单词规律](https://leetcode.cn/problems/word-pattern)【单词与字符双向映射】
- [383. 赎金信](https://leetcode.cn/problems/ransom-note)【字符频次计数】
- [387. 字符串中的第一个唯一字符](https://leetcode.cn/problems/first-unique-character-in-a-string)【频次统计 + 二次遍历】
- [392. 判断子序列](https://leetcode.cn/problems/is-subsequence)【双指针】
- [394. 字符串解码](https://leetcode.cn/problems/decode-string)【栈模拟嵌套结构】
- [409. 最长回文串](https://leetcode.cn/problems/longest-palindrome)【字符频次 + 贪心】
- [91. 解码方法](https://leetcode.cn/problems/decode-ways)【线性 DP；按一位和两位数字的合法性转移】
- [139. 单词拆分](https://leetcode.cn/problems/word-break)【DP + 哈希集合；`dp[i]` 表示前缀是否可拆分】
- [140. 单词拆分 II](https://leetcode.cn/problems/word-break-ii)【记忆化 DFS；枚举可切分单词并缓存后缀结果】
- [647. 回文子串](https://leetcode.cn/problems/palindromic-substrings)【中心扩展；枚举奇偶中心统计回文数量】
- [415. 字符串相加](https://leetcode.cn/problems/add-strings)【模拟竖式加法】
- [516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence)【区间动态规划】
- [1702. 修改后的最大二进制字符串](https://leetcode.cn/problems/maximum-binary-string-after-change)【贪心构造】
- [2707. 字符串中的额外字符](https://leetcode.cn/problems/extra-characters-in-a-string)【动态规划】
- [2842. 统计一个字符串的 k 子序列美丽值最大的数目](https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty)【组合数学 + 频次】
- [2851. 字符串 K 次转换等于目标串的方案数量](https://leetcode.cn/problems/string-transformation)【KMP + 矩阵快速幂】
- [2896. 执行操作使两个字符串相等](https://leetcode.cn/problems/apply-operations-to-make-two-strings-equal)【动态规划】
- [2930. 重新排列后包含指定子字符串的字符串数目](https://leetcode.cn/problems/number-of-strings-which-can-be-rearranged-to-contain-substring)【组合计数】
- [3144. 分割字符频率相等的最少子字符串](https://leetcode.cn/problems/minimum-substring-partition-of-equal-frequency)【动态规划】
- [3211. 生成不含相邻零的二进制字符串](https://leetcode.cn/problems/generate-binary-strings-without-adjacent-zeros)【回溯】
- [3291. 形成目标字符串需要的最少字符串数 I](https://leetcode.cn/problems/minimum-number-of-valid-strings-to-form-target-i)【Trie + 动态规划】
- [3463. 判断操作后字符串中的数字是否相等 II](https://leetcode.cn/problems/check-if-digits-are-equal-in-string-after-operations-ii)【组合数学 + 模运算】

### 2. 栈与单调栈 (核心模式归类)

#### 2.1 基础栈应用与模拟 (处理嵌套、撤销与状态存取)
- [20. 有效的括号](https://leetcode.cn/problems/valid-parentheses)【模式：括号匹配；核心：利用栈的 LIFO 特性处理嵌套关系】
- [71. 简化路径](https://leetcode.cn/problems/simplify-path)【模式：路径模拟；核心：遇到 `..` 执行出栈，配合 `stringstream` 拆分单词】
- [150. 逆波兰表达式求值](https://leetcode.cn/problems/evaluate-reverse-polish-notation)【模式：后缀表达式计算；核心：遇到运算符弹出两数计算，注意减/除顺序】
- [227. 基本计算器 II](https://leetcode.cn/problems/basic-calculator-ii)【栈模拟；借助前一运算符处理乘除优先级】
- [772. 基本计算器 III](https://leetcode.cn/problems/basic-calculator-iii)【递归下降/栈模拟；用递归处理括号并维护运算优先级】
- [155. 最小栈](https://leetcode.cn/problems/min-stack)【模式：双栈/辅助栈；核心：同步维护一个“当前的最小值”栈】
- [224. 基本计算器](https://leetcode.cn/problems/basic-calculator)【模式：符号栈模拟；核心：利用栈维护当前括号层级的“全局正负号”，实现 $O(n)$ 一次遍历展开括号】
- [232. 用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks)【模式：双栈翻转；核心：利用入栈和出栈两个容器实现 FIFO】
- [394. 字符串解码](https://leetcode.cn/problems/decode-string)【模式：多栈状态存取；核心：分别用栈存储当前的倍数 `cnt` 和已拼出的 `string`】

#### 2.2 单调栈基础 (在线性时间内寻找左右最近的极值)
- [496. 下一个更大元素 I](https://leetcode.cn/problems/next-greater-element-i)【模式：单调递减栈；核心：在栈中保留尚未找到“下一个更大数”的元素】
- [503. 下一个更大元素 II](https://leetcode.cn/problems/next-greater-element-ii)【模式：循环数组；核心：通过遍历两遍数组模拟环形结构】
- [739. 每日温度](https://leetcode.cn/problems/daily-temperatures)【模式：距离计算；核心：栈中存储索引，用于计算下标差值】
- [901. 股票价格跨度](https://leetcode.cn/problems/online-stock-span)【模式：在线单调栈；核心：将历史跨度累加，实现 $O(1)$ 的平均查询】

#### 2.3 单调栈进阶 (处理区间面积与贡献度计算)
- [84. 柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram)【模式：左右扩展边界；核心：利用单调栈一次性确定每个柱子的左、右边界，求最大矩形面积】
- [768. 最多能完成排序的块 II](https://leetcode.cn/problems/max-chunks-to-make-sorted-ii)【模式：单调栈维护块极值；核心：栈中每个元素代表一个“块”的最大值，重叠则合并】
- [907. 子数组的最小值之和](https://leetcode.cn/problems/sum-of-subarray-minimums)【模式：贡献度法；核心：计算每个元素作为最小值的区间覆盖范围 $(i-L)*(R-i)$】
- [2866. 美丽塔 II](https://leetcode.cn/problems/beautiful-towers-ii)【模式：前后缀单调栈；核心：分别计算左侧和右侧的单调递增和，最后枚举顶点取 Max】

#### 2.4 栈与贪心/其他
- [769. 最多能完成排序的块](https://leetcode.cn/problems/max-chunks-to-make-sorted)【模式：贪心模拟；核心：维护当前最大值，若 `max == index` 则可分块】
- [2216. 美化数组的最少删除数](https://leetcode.cn/problems/minimum-deletions-to-make-array-beautifu)【模式：相邻元素冲突；核心：贪心删除或栈模拟相邻不同】
- [2818. 操作使得分最大](https://leetcode.cn/problems/apply-operations-to-maximize-score)【模式：组合应用；核心：质因数分解 + 贡献度计数 + 单调栈】

### 3. 队列、双端队列与堆 (用于滑动窗口极值或动态 TopK)
- [剑指 Offer 59 - II. 队列的最大值](https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof)【队列 + 双端队列 + 单调队列】
- [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum) 【双端单调递减队列】
- [295. 数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream)【最大堆 + 最小堆】
- [480. 滑动窗口中位数](https://leetcode.cn/problems/sliding-window-median)【双堆 + 延迟删除；维护窗口两半元素数量平衡】
- [703. 数据流中的第 K 大元素](https://leetcode.cn/problems/kth-largest-element-in-a-stream)【大小为 `k` 的最小堆；堆顶即第 K 大元素】
- [862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k)【前缀和 + 单调队列；处理包含负数的最短区间和】
- [1823. 找出游戏的获胜者](https://leetcode.cn/problems/find-the-winner-of-the-circular-game)【队列模拟】
- [1792. 最大平均通过率](https://leetcode.cn/problems/maximum-average-pass-ratio)【最大堆；每次选择增加通过学生后边际收益最大的班级】
- [1834. 单线程 CPU](https://leetcode.cn/problems/single-threaded-cpu)【最小堆；按到达时间加入任务并按处理时间、编号选择】
- [2810. 故障键盘](https://leetcode.cn/problems/faulty-keyboard)【deque 模拟】

### 4. 链表 (核心模式归类)

#### 4.1 基础操作与反转 (双指针、递归与 Dummy Node)
- [2. 两数相加](https://leetcode.cn/problems/add-two-numbers)【模式：模拟加法；注意进位处理与 Dummy Node 的使用】
- [25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group)【模式：分段翻转；核心：先求长度确定组数，利用“头插法”在 $O(n)$ 时间 $O(1)$ 空间内完成翻转】
- [83. 删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list)【一次遍历；相等节点直接跳过，仅保留一个】
- [82. 删除排序链表中的重复元素 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii)【模式：三指针去重；核心：利用 Dummy 节点，彻底跳过重复项】
- [92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii)【模式：局部反转；核心：头插法实现一次遍历反转】
- [160. 相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists)【模式：双指针同步；核心：`a+c+b = b+c+a`，消除长度差实现首遇】
- [206. 反转链表](https://leetcode.cn/problems/reverse-linked-list)【模式：迭代反转；核心：利用 `pre`, `cur`, `next` 三指针完成原地调向】
- [1721. 交换链表中的节点](https://leetcode.cn/problems/swapping-nodes-in-a-linked-list)【模式：快慢指针；核心：找倒数第 k 个节点与正数第 k 个节点进行交换】

#### 4.2 快慢指针与环形检测
- [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list)【模式：快慢指针；核心：利用 $n$ 步位移差定位倒数第 $n+1$ 个节点（前驱节点）】
- [61. 旋转链表](https://leetcode.cn/problems/rotate-list)【模式：成环解环；核心：先连成环再在 $n-(k\%n)$ 处断开，简化指针操作】
- [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle)【模式：快慢指针；核心：利用步长差 $(2-1=1)$，在 $O(n)$ 时间 $O(1)$ 空间内检测链表是否有环】
- [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii)【模式：双指针追赶；核心：相遇后将一指针归零，同步慢走寻找环入口】
- [287. 寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number)【模式：映射找环；将数组索引视为链表指针，转化为环入口问题】
- [876. 链表的中间结点](https://leetcode.cn/problems/middle-of-the-linked-list)【模式：快慢指针；核心：`fast` 走两步 `slow` 走一步，`fast` 到头时 `slow` 在中点】

#### 4.3 合并、排序与分隔
- [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists)【模式：双指针归并；合并有序链表的基础】
- [23. 合并 K 个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists)【分治归并/最小堆；每次合并两个有序链表或弹出当前最小节点】
- [86. 分隔链表](https://leetcode.cn/problems/partition-list)【模式：双链表拆分；将节点按大小分拨到两个哑节点链表，最后首尾相连】
- [147. 对链表进行插入排序](https://leetcode.cn/problems/insertion-sort-list)【模式：插入排序；维护已排序部分，将新节点插入合适位置】
- [148. 链表归并排序](https://leetcode.cn/problems/sort-list)【模式：归并排序；核心：快慢指针找中点 + 递归合并】

#### 4.4 复杂链表与采样
- [138. 随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer)【模式：原地克隆；核心：`A->A'->B->B'` 插入法，实现 $O(1)$ 空间拷贝随机指针】
- [146. LRU 缓存](https://leetcode.cn/problems/lru-cache)【模式：哈希表 + 双向链表；实现 $O(1)$ 的访问与淘汰】
- [382. 链表随机节点](https://leetcode.cn/problems/linked-list-random-node)【模式：水塘抽样；核心：从未知长度流中等概率采样，确保概率为 $1/i$】
- [460. LFU 缓存](https://leetcode.cn/problems/lfu-cache)【模式：双哈希表 + 频次链表；实现 $O(1)$ 的频率敏感淘汰】

### 5. 二叉树与树形结构 (核心模式归类)

#### 5.1 遍历、属性与结构基础 (递归与迭代)
- [144. 二叉树的前序遍历](https://leetcode.cn/problems/binary-tree-preorder-traversal)【模式：栈迭代；先访问根节点，再依次压入右、左子树】
- [94. 二叉树的中序遍历](https://leetcode.cn/problems/binary-tree-inorder-traversal)【模式：栈迭代；左孩子一路入栈，弹栈后访问右子树】
- [145. 二叉树的后序遍历](https://leetcode.cn/problems/binary-tree-postorder-traversal)【模式：栈迭代；按根、右、左访问后反转结果】
- [101. 对称二叉树](https://leetcode.cn/problems/symmetric-tree)【模式：分治；核心：判断 `L->left vs R->right` 且 `L->right vs R->left`】
- [102. 二叉树的层序遍历](https://leetcode.cn/problems/binary-tree-level-order-traversal)【模式：BFS；核心：利用队列按层处理，`size` 控制当前层边界】
- [103. 二叉树的锯齿形层序遍历](https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal)【模式：BFS + Deque；核心：根据层数奇偶性决定从队头或队尾插入，规避显式翻转开销】
- [104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree)【模式：DFS/回溯；核心：`max(left, right) + 1`】
- [199. 二叉树的右视图](https://leetcode.cn/problems/binary-tree-right-side-view)【模式：BFS / DFS；核心：BFS 记录层末节点，或 DFS 优先访问右子树并记录首次到达深度】
- [222. 完全二叉树的节点个数](https://leetcode.cn/problems/count-complete-tree-nodes)【模式：分治 + 完全二叉树性质；核心：利用左右子树高度差判断满二叉树，实现 $O(\log^2 n)$ 极速计数】
- [226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree)【模式：递归/层序；核心：交换左右子节点，自底向上或自顶向下均可】
- [637. 二叉树的层平均值](https://leetcode.cn/problems/average-of-levels-in-binary-tree)【模式：BFS；核心：按层求和，注意利用 `long long` 防止累加溢出】

#### 5.2 路径、祖先与贡献度计算 (DFS 进阶)
- [114. 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list)【模式：递归/前驱节点；核心：将左子树插入右侧，注意清空左指针以防成环】
- [124. 二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum)【模式：树形 DP / 贡献度；核心：区分“节点作为转折点”与“节点作为贡献者”两种状态，利用 `max(0, gain)` 过滤负贡献】
- [112. 路径总和](https://leetcode.cn/problems/path-sum)【模式：DFS；维护当前路径和，到达叶子节点时校验】
- [113. 路径总和 II](https://leetcode.cn/problems/path-sum-ii)【模式：回溯；维护当前路径与路径和，命中目标后记录答案】
- [129. 求根节点到叶节点数字之和](https://leetcode.cn/problems/sum-root-to-leaf-numbers)【模式：DFS 路径累加；核心：利用 `x * 10 + node->val` 传递路径状态，推荐“结果上传”的纯函数写法】
- [236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree)【模式：DFS 递归；核心：利用返回值上传状态（自底向上聚合），实现无副作用的纯函数设计】
- [572. 另一棵树的子树](https://leetcode.cn/problems/subtree-of-another-tree)【模式：双重递归；核心：对每个节点调用 `isSameTree`】
- [1644. LCA II](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree-ii)【模式：计数 DFS；核心：需完整遍历以确认 p, q 是否均存在】

#### 5.3 构造、变换与序列化
- [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal)【模式：分治；核心：前序定根，中序分左右；优化：哈希表预处理索引实现 $O(n)$】
- [106. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal)【模式：分治；核心：后序定根，中序分左右】
- [117. 填充每个节点的下一个右侧节点指针 II](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii)【模式：层序遍历 / 链表模拟；核心：利用已建立的 `next` 指针作为“下一层”的驱动，实现 $O(1)$ 空间复杂度】

#### 5.4 二叉搜索树 (BST 专项)
- [98. 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree)【模式：中序遍历 / 分治；陷阱：需保证子树所有节点均在全局上下界内，而非仅满足局部父子关系】
- [108. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree)【模式：分治/二分构造；核心：选取中间节点作为根，确保左右子树高度平衡】
- [173. 二叉搜索树迭代器](https://leetcode.cn/problems/binary-search-tree-iterator)【模式：栈模拟中序遍历；核心：利用显式栈实现懒加载，确保 $O(h)$ 空间与均摊 $O(1)$ 时间】
- [LCR 193. 二叉搜索树的最近公共祖先](https://leetcode.cn/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof)【模式：数值比较；核心：利用 `root->val` 与 `p, q` 的大小关系快速剪枝】
- [230. 二叉搜索树中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-bst)【模式：中序遍历；核心：利用 BST 中序递增特性，通过迭代法实现“早期停止”以优化性能；进阶：频繁查询可维护子树 size 实现 $O(h)$ 检索】
- [530. 二叉搜索树的最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference-in-bst)【模式：中序遍历；核心：利用 BST 中序递增特性；进阶：Morris 遍历可实现 $O(1)$ 空间复杂度】
- [2673. 使二叉树所有路径值相等的最小代价](https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree)【模式：贪心/树形 DP；核心：自底向上平衡左右子树代价】

### 6. 平衡二叉搜索树 (std::map/set)

### 7. 区间查询与统计（算法选型与题单）

> 选型速查：静态可减聚合用前缀和；批量区间修改用差分；单点修改配区间和/频次用树状数组；复杂聚合或区间修改用线段树；无法快速合并但可离线的复杂统计用莫队或离线扫描线；频次奇偶校验可考虑前缀异或/随机哈希。
>
> 决策路径：有修改时，单点修改优先树状数组，区间修改优先带 Lazy 标记的线段树；无修改时，可由左右子段合并或相减则用前缀和，不能直接合并但能离线则选离线扫描线或莫队，否则考虑可持久化线段树、分块或哈希。

#### 7.1 前缀和、差分与二维扩展
- [303. 区域和检索 - 数组不可变](https://leetcode.cn/problems/range-sum-query-immutable)【前缀和；`pref[r + 1] - pref[l]` 在 $O(1)$ 时间查询静态区间和】
- [238. 除了自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self)【前缀积 + 后缀积；两次扫描避免使用除法】
- [560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k)【前缀和 + 哈希表；将子数组和转化为两前缀和之差】
- [1423. 可获得的最大点数](https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards)【前缀和/滑动窗口；枚举从两端取得的牌数】
- [253. 会议室 II](https://leetcode.cn/problems/meeting-rooms-ii)【差分/扫描线；起点 `+1`、终点 `-1`，前缀最大值为最大并发数】
- [995. K 连续位的最小翻转次数](https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips)【差分；记录翻转影响的起止位置】
- [1094. 拼车](https://leetcode.cn/problems/car-pooling)【差分；按站点累计上下车人数】
- [1109. 航班预订统计](https://leetcode.cn/problems/corporate-flight-bookings)【一维差分模板；区间端点标记后一次还原】
- [2132. 用邮票贴满网格图](https://leetcode.cn/problems/stamping-the-grid)【二维前缀和 + 二维差分；常数时间判定矩形并批量标记】
- [3127. 构造相同颜色的正方形](https://leetcode.cn/problems/make-a-square-with-the-same-color)【二维局部统计；检查每个 $2 \times 2$ 区域】
- [3152. 特殊数组 II](https://leetcode.cn/problems/special-array-ii)【相邻奇偶变化前缀和；将区间合法性化为一次区间和判断】
- [3212. 统计 X 和 Y 频数相等的子矩阵数量](https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y)【二维前缀和 + 哈希；固定上下边界后统计列前缀差】

#### 7.2 离散化：大值域的紧凑索引
- [315. 计算右侧小于当前元素的个数](https://leetcode.cn/problems/count-of-smaller-numbers-after-self)【离散化 + 树状数组；将数值映射为排名后倒序累计】
- [218. 天际线问题](https://leetcode.cn/problems/the-skyline-problem)【离散化 + 扫描线；对稀疏横坐标压缩后维护高度变化】

#### 7.3 树状数组与离线扫描线
- [307. 区域和检索 - 数组可修改](https://leetcode.cn/problems/range-sum-query-mutable)【树状数组；单点更新、前缀和查询均为 $O(\log n)$】
- [315. 计算右侧小于当前元素的个数](https://leetcode.cn/problems/count-of-smaller-numbers-after-self)【离散化 + 树状数组；经典逆序统计】
- [1505. 最多 K 次交换相邻数位后得到的最小整数](https://leetcode.cn/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits)【树状数组；维护已删除位置造成的相对偏移】
- [DQUERY. D-query](https://www.spoj.com/problems/DQUERY/)【离线扫描线 + 树状数组；按右端点扫描，元素最近出现位置置换以统计区间不同元素数】
- [1851. 包含每个查询的最小区间](https://leetcode.cn/problems/minimum-interval-to-include-each-query)【离线排序 + 最小堆；按查询值推进区间起点】
- [2747. 统计没有收到请求的服务器数目](https://leetcode.cn/problems/count-zero-request-servers)【离线排序 + 滑动窗口；按查询时间维护活跃服务器】
- [2940. 找到 Alice 和 Bob 可以相遇的建筑](https://leetcode.cn/problems/find-building-where-alice-and-bob-can-meet)【离线查询 + 单调栈/树状结构；按右端点倒序处理候选建筑】

#### 7.4 线段树：区间聚合、Lazy 与动态开点
- [307. 区域和检索 - 数组可修改](https://leetcode.cn/problems/range-sum-query-mutable)【树状数组/线段树模板；单点更新与区间和】
- [699. 掉落的方块](https://leetcode.cn/problems/falling-squares)【动态开点线段树；区间最大值查询与区间赋值】
- [2276. 统计区间中的整数数目](https://leetcode.cn/problems/count-integers-in-intervals)【动态开点 + Lazy 标记；大值域区间覆盖与长度聚合】
- [2916. 子数组不同元素数目的平方和 II](https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-ii)【Lazy 线段树；维护区间最大值、次数和平方和】
- [3479. 将水果装入篮子 III](https://leetcode.cn/problems/fruits-into-baskets-iii)【线段树；区间最大值引导查找首个可用下标并单点更新】

#### 7.5 莫队算法：离线的复杂频次统计
- [DQUERY. D-query](https://www.spoj.com/problems/DQUERY/)【莫队算法；分块排序后平滑移动双指针统计区间不同元素数】
- [2003. 每棵子树内缺失的最小基因值](https://leetcode.cn/problems/smallest-missing-genetic-value-in-each-subtree)【树上统计参考；利用包含基因 `1` 的路径缩小需要维护的子树范围】

#### 7.6 前缀异或与随机哈希
- [2588. 统计美丽子数组数目](https://leetcode.cn/problems/count-the-number-of-beautiful-subarrays)【前缀异或 + 哈希表；相同前缀异或之间的子数组异或和为 $0$】
- [1915. 最美子字符串的数目](https://leetcode.cn/problems/number-of-wonderful-substrings)【状态压缩 + 前缀异或；枚举零或一个奇数频次的掩码差异】
> 知识点：随机异或哈希【概率校验；为值分配 64 位随机权重，区间异或为零可作为频次全部为偶数的高概率判定；需使用防碰撞随机数生成器】

### 8. 字典树 (Trie)
- [208. 实现 Trie (前缀树)](https://leetcode.cn/problems/implement-trie-prefix-tree)【模式：多叉树；用于高效字符串检索与前缀匹配】
- [211. 添加与搜索单词](https://leetcode.cn/problems/design-add-and-search-words-data-structure)【模式：Trie + DFS；核心：利用递归处理 `.` 通配符的模糊匹配】
- [212. 单词搜索 II](https://leetcode.cn/problems/word-search-ii)【模式：Trie + 回溯；核心：将词典建模为 Trie，在网格回溯中同步移动 Trie 指针，实现多模式高效匹配】
- [421. 数组中两个数的最大异或值](https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array)【模式：0-1 Trie；利用二进制前缀树实现 $O(n \log C)$ 的异或极值查找】
- [676. 设计神奇字典](https://leetcode.cn/problems/implement-magic-dictionary)【模式：Trie + DFS；支持模糊匹配】
- [1707. 与数组中元素的最大异或值](https://leetcode.cn/problems/maximum-xor-with-an-element-from-array)【模式：离线查询 + 0-1 Trie】
- [1803. 统计异或值在范围内的数对有多少](https://leetcode.cn/problems/count-pairs-with-xor-in-a-range)【模式：0-1 Trie + 计数；类似于数位 DP 的统计思想】

### 9. 字符串匹配 (KMP / AC 自动机)
- [28. 找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string)【KMP】
- [3006. 找出数组中的美丽下标 I](https://leetcode.cn/problems/find-beautiful-indices-in-the-given-array-i)【字符串匹配 + 双指针；合并两个模式出现位置】
> 知识点：最长合法子字符串的长度（AC 自动机）【失败指针 + 多模式匹配；原题链接待补充】

### 10. 数据结构设计与实现 (Consolidated)

#### 10.1 基础结构实现
- [剑指 Offer 59 - II. 队列的最大值](https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof)【模式：单调队列；实现 $O(1)$ 获取队列最大值】
- [155. 最小栈](https://leetcode.cn/problems/min-stack)【模式：双栈辅助；实现 $O(1)$ 获取最小值】
- [232. 用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks)【模式：双栈翻转；实现 FIFO 逻辑】
- [622. 设计循环队列](https://leetcode.cn/problems/design-circular-queue)【模式：数组模拟；注意首尾指针的取模处理】
- [641. 设计循环双端队列](https://leetcode.cn/problems/design-circular-deque)【模式：数组模拟；支持两端插入与删除】

#### 10.2 缓存与高级哈希
- [146. LRU 缓存](https://leetcode.cn/problems/lru-cache)【模式：哈希表 + 双向链表；实现 $O(1)$ 的访问与淘汰】
- [380. O(1) 时间插入、删除和获取随机元素](https://leetcode.cn/problems/insert-delete-getrandom-o1)【模式：哈希表 + 动态数组；利用数组末尾交换实现 $O(1)$ 删除】
- [460. LFU 缓存](https://leetcode.cn/problems/lfu-cache)【模式：双哈希表 + 频次链表；实现 $O(1)$ 的频率敏感淘汰】
- [705. 设计哈希集合](https://leetcode.cn/problems/design-hashset)【模式：链地址法；处理哈希冲突的基础实现】
- [706. 设计哈希映射](https://leetcode.cn/problems/design-hashmap)【模式：链地址法；KV 存储的基础实现】

#### 10.3 树与图的高级结构
- [208. 实现 Trie (前缀树)](https://leetcode.cn/problems/implement-trie-prefix-tree)【模式：多叉树；用于高效字符串检索与前缀匹配】
- [211. 添加与搜索单词](https://leetcode.cn/problems/design-add-and-search-words-data-structure)【模式：Trie + DFS；核心：利用递归处理 `.` 通配符的模糊匹配】
- [676. 设计神奇字典](https://leetcode.cn/problems/implement-magic-dictionary)【模式：Trie + DFS；支持模糊匹配】
> 模板：手撕线段树（Segment Tree）【二叉树递归；支持区间修改与 $O(\log n)$ 聚合查询】
> 模板：树状数组（Fenwick Tree）【位运算 lowbit；极简实现的区间和维护】
> 模板：跳表（SkipList）【多级索引链表；Redis 核心数据结构，替代平衡树】

## 基本算法
基本算法专题负责导航和完整题单；题目按解题模式归类，每行一个题目，并在右侧标注关键点。

### 1. 双指针

> 识别信号：两个或多个下标协作移动，以排除不可能的答案、原地处理元素，或标记连续段的边界。

#### 1.1 对撞双指针

- [15. 三数之和](https://leetcode.cn/problems/3sum)【排序 + 双指针；枚举第一个数后，对撞寻找其余两数并去重】
- [125. 验证回文串](https://leetcode.cn/problems/valid-palindrome)【首尾夹逼；跳过非字母数字字符后比较】
- [167. 两数之和 II - 输入有序数组](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted)【双指针夹逼；利用有序性按和的大小收缩搜索空间】

#### 1.2 同向指针

- [26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array)【同向快慢指针；读指针扫描，写指针维护去重结果的尾部】
- [151. 反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string)【双指针 + 局部翻转；原地整理单词边界后逐段翻转】
- [283. 移动零](https://leetcode.cn/problems/move-zeroes)【同向快慢指针；读指针扫描非零元素，写指针维护写入位置】
- [392. 判断子序列](https://leetcode.cn/problems/is-subsequence)【同向双指针；依次匹配 `s` 与 `t`，进阶可预处理 `t` 的序列自动机】
- [2938. 区分黑球与白球](https://leetcode.cn/problems/separate-black-and-white-balls)【同向扫描；累计左侧白球数量】

#### 1.3 快慢指针：循环检测

- [141. 环形链表](https://leetcode.cn/problems/linked-list-cycle)【Floyd 判环；快指针每次两步、慢指针每次一步，相遇即存在循环】
- [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii)【Floyd 找环入口；相遇后将一指针移回起点，两指针同步前进再次相遇于入口】
- [202. 快乐数](https://leetcode.cn/problems/happy-number)【状态映射 + Floyd 判环；反复替换为各位平方和，最终到达 1 或进入循环】
- [287. 寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number)【数组映射成链表 + Floyd 找环；不修改原数组，在 $O(n)$ 时间和 $O(1)$ 空间内找到重复数】

#### 1.4 分组双指针

- [228. 汇总区间](https://leetcode.cn/problems/summary-ranges)【分组扫描；用起止下标识别 `nums[j + 1] != nums[j] + 1` 的断点】
- [2970. 统计移除递增子数组的数目 I](https://leetcode.cn/problems/count-the-number-of-incremovable-subarrays-i)【前后缀 + 双指针；枚举删除区间的左右边界】

#### 1.5 三指针分区

- [75. 颜色分类](https://leetcode.cn/problems/sort-colors)【荷兰国旗；`left`、`cur`、`right` 分别维护 0 区、未知区和 2 区】

### 2. 滑动窗口

> 识别信号：处理连续子串或子数组；`right` 扩张窗口，`left` 在窗口不合法或已满足条件时收缩。哈希表、计数数组和单调队列是维护窗口状态的工具。

#### 2.1 固定长度窗口

- [219. 存在重复元素 II](https://leetcode.cn/problems/contains-duplicate-ii)【固定窗口 Hash Set；窗口宽度不超过 `k`】
- [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum)【固定窗口 + 单调队列；队首始终是窗口最大值候选】
- [438. 找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string)【固定窗口 + 字符频次；窗口长度等于模式串长度】
- [567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string)【固定窗口 + 频次匹配；判断是否存在排列子串】
- [1052. 爱生气的书店老板](https://leetcode.cn/problems/grumpy-bookstore-owner)【固定窗口求和；选择连续 `minutes` 分钟挽回最多顾客】

#### 2.2 可变窗口：最长与计数

- [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters)【不定长窗口；用索引 Map 或计数数组维护无重复约束】
- [30. 串联所有单词的子串](https://leetcode.cn/problems/substring-with-concatenation-of-all-words)【按单词长度分组的窗口 + 词频统计】
- [2024. 考试的最大困扰度](https://leetcode.cn/problems/maximize-the-confusion-of-an-exam)【不定长窗口；窗口内较少字符数不超过 `k`】
- [1004. 最大连续 1 的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii)【不定长窗口；窗口内 0 的数量不超过 `k`】
- [2962. 统计最大元素出现至少 K 次的子数组](https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times)【满足条件后收缩左边界；累计以当前右端点结尾的合法子数组】
- [3298. 统计重新排列后包含另一个字符串的子字符串数目 II](https://leetcode.cn/problems/count-substrings-that-can-be-rearranged-to-contain-a-string-ii)【需求频次窗口；满足覆盖后累计合法左边界数量】

#### 2.3 可变窗口：最短覆盖

- [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring)【需求计数 + 窗口计数；覆盖目标后极致收缩左边界】
- [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum)【正数数组窗口和；和满足目标后收缩】
- [862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k)【前缀和 + 单调队列；用于包含负数的最短区间和】

#### 2.4 窗口中的有序查询

- [220. 存在重复元素 III](https://leetcode.cn/problems/contains-duplicate-iii)【窗口 + 有序集合 `lower_bound`；同时约束下标距离与数值距离】

### 3. 哈希表、集合与频率统计

> 识别信号：核心是快速查询历史状态、统计频次、验证映射关系或将等价对象分组；题目本身不以连续窗口为主要结构。

#### 3.1 在线查找与集合去重

- [1. 两数之和](https://leetcode.cn/problems/two-sum)【在线 Hash Map；一边查补数，一边存当前数】
- [128. 最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence)【Hash Set + 智能起点；仅从 `x - 1` 不存在的位置开始扩展】
- [202. 快乐数](https://leetcode.cn/problems/happy-number)【Hash Set 记录历史状态以检测循环；也可作为快慢指针题复习】
- [217. 存在重复元素](https://leetcode.cn/problems/contains-duplicate)【Hash Set；插入时检查元素是否已出现】

#### 3.2 字符频次与奇偶性

- [242. 有效的字母异位词](https://leetcode.cn/problems/valid-anagram)【频次数组对比；先加后减并可在负数时提前退出】
- [266. 回文排列](https://leetcode.cn/problems/palindrome-permutation)【奇偶计数；最多一个字符可出现奇数次】
- [383. 赎金信](https://leetcode.cn/problems/ransom-note)【字符频次余额；可用 `int[26]` 实现】
- [387. 字符串中的第一个唯一字符](https://leetcode.cn/problems/first-unique-character-in-a-string)【先统计频次，再按原顺序查找频次为 1 的字符】
- [409. 最长回文串](https://leetcode.cn/problems/longest-palindrome)【统计成对字符；该题的贪心证明保留在贪心题单】

#### 3.3 映射、归类与前缀状态

- [49. 字母异位词分组](https://leetcode.cn/problems/group-anagrams)【等类规约；排序字符串或字符频次作为 Map 的 Key】
- [205. 同构字符串](https://leetcode.cn/problems/isomorphic-strings)【双向映射；验证两个字符集合的一一对应】
- [290. 单词规律](https://leetcode.cn/problems/word-pattern)【双向 Hash；字符与单词构成双射】
- [560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k)【前缀和 + 频次 Map；查找之前出现过的 `prefix - k`】


### 4. 排序、Top K 与选择
- [面试题 17.09. 第 k 个数](https://leetcode.cn/problems/get-kth-magic-number-lcci)【三指针或优先队列；按丑数生成顺序求第 k 个数】
- [179. 最大数](https://leetcode.cn/problems/largest-number)【自定义逆序排序 + 贪心】
- [912. 排序数组，快速排序和归并排序](https://leetcode.cn/problems/sort-an-array)【三段式快速排序less,more】
> 知识点：数组插入排序【原地、稳定；将当前元素插入左侧已排序区，适合近乎有序的数据】
- [147. 对链表进行插入排序](https://leetcode.cn/problems/insertion-sort-list)【插入排序；维护已排序链表，将当前节点插入正确位置】
- [148. 链表归并排序](https://leetcode.cn/problems/sort-list)【归并排序；快慢指针拆分链表，再合并两个有序链表】
- [1329. 将矩阵按对角线排序](https://leetcode.cn/problems/sort-the-matrix-diagonally)【按对角线分组；分别排序后写回矩阵】
- [2512. 奖励最顶尖的 K 名学生](https://leetcode.cn/problems/reward-top-k-students)【评分统计 + 排序/堆；按总分和姓名规则取前 K 名】
- [215. 数组中的第 K 个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array)【快速选择/最小堆；平均 $O(n)$ 定位第 K 大元素】
- [295. 数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream)【对顶堆；最大堆维护较小一半、最小堆维护较大一半，堆顶给出中位数】
- [703. 数据流中的第 K 大元素](https://leetcode.cn/problems/kth-largest-element-in-a-stream)【大小为 K 的最小堆；流式插入后堆顶始终是第 K 大元素】

### 5. 枚举与状态遍历
- [2555. 两个线段获得的最多奖品](https://leetcode.cn/problems/maximize-win-from-two-segments)【维护左边，枚举右边】
- [2735. 收集巧克力](https://leetcode.cn/problems/collecting-chocolates)【枚举旋转次数；维护每种巧克力当前可取得的最低价格】
- [3404. 统计特殊子序列的数目](https://leetcode.cn/problems/count-special-subsequences)【枚举中间结构；结合数值关系和频次统计方案】

### 6. 模拟、分组与循环
- [66. 加一](https://leetcode.cn/problems/plus-one)【模拟进位；从最低位向前传播进位】
- [65. 有效数字](https://leetcode.cn/problems/valid-number)【一个字符串包含+-.e判断是否是一个有效的数字】
- [415. 字符串相加](https://leetcode.cn/problems/add-strings)【逐位模拟加法；从低位向高位维护进位】
- [466. 统计重复个数](https://leetcode.cn/problems/count-the-repetitions)【循环模拟 + 周期加速；记录重复状态避免逐字符超时】
- [1103. 分糖果 II](https://leetcode.cn/problems/distribute-candies-to-people)【循环队列分糖果】
> 知识点：按照题目要求，数组会被分割成若干组，且每一组的判断/处理逻辑是一样的【分组模拟；识别每组边界并复用相同处理逻辑】
- [1823. 找出游戏的获胜者](https://leetcode.cn/problems/find-the-winner-of-the-circular-game)【队列模拟】
- [2332. 坐上公交的最晚时间](https://leetcode.cn/problems/the-latest-time-to-catch-a-bus)【双指针-易错模拟题】
- [2760. 最长奇偶子数组](https://leetcode.cn/problems/longest-even-odd-subarray-with-threshold)【线性扫描分组；遇到不满足阈值或奇偶条件的位置重新开始】
- [2808. 使循环数组所有元素相等的最少秒数](https://leetcode.cn/problems/minimum-seconds-to-equalize-a-circular-array)【按值分组 + 环形距离；计算相同值出现位置之间的最大间隔】

### 7. 贪心：局部最优的证明与训练

> 做题时先回答：**当前舍弃的选择，为什么以后不可能更优？** 能用交换论证、不变量或单调边界回答，才适合贪心。

#### 7.1 边界淘汰与可达性

- [11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water)【移动短板；短板不动无法得到更优解】
- [42. 接雨水](https://leetcode.cn/problems/trapping-rain-water)【处理较低边界；其蓄水上界已被确定】
- [45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii)【维护当前层可达边界与下一层最远位置，维护当前cur_max_dis,全局 max_dis】
- [55. 跳跃游戏](https://leetcode.cn/problems/jump-game)【维护最远可达位置】
- [134. 加油站](https://leetcode.cn/problems/gas-station)【失败起点到失败点之间的起点均可跳过,维护 total_net,cur_net】
- [135. 分发糖果](https://leetcode.cn/problems/candy)【左右各扫一次，分别满足单侧局部约束】
- [1793. 好子数组的最大分数](https://leetcode.cn/problems/maximum-score-of-a-good-subarray)【向较高一侧扩张，尽量延缓最小值下降】
- [2216. 美化数组的最少删除数](https://leetcode.cn/problems/minimum-deletions-to-make-array-beautiful)【冲突时删除当前元素，保留更早的可用位置】
- [2332. 坐上公交的最晚时间](https://leetcode.cn/problems/the-latest-time-to-catch-a-bus)【模拟后从最后可行时刻向前避开已占用时间】

#### 7.2 区间、排序与交换论证

- [56. 合并区间](https://leetcode.cn/problems/merge-intervals)【按起点排序后只维护当前合并区间】
- [57. 插入区间](https://leetcode.cn/problems/insert-interval)【利用区间有序性分段处理】
- [435. 无重叠区间](https://leetcode.cn/problems/non-overlapping-intervals)【优先保留结束最早的区间】
- [452. 用最少数量的箭引爆气球](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons)【每次选择当前重叠区间的最右公共点】
- [215. 数组中的第 K 个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array)【排序后决策；排序后直接定位，或维护大小为 K 的最小堆保留当前 K 个最大元素】
- [3111. 覆盖所有点的最少矩形数目](https://leetcode.cn/problems/minimum-rectangles-to-cover-points)【按横坐标排序，尽可能延长当前覆盖范围】

#### 7.3 排序、配对与阈值选择

- [455. 分发饼干](https://leetcode.cn/problems/assign-cookies)【排序 + 双指针；优先用最小可满足的饼干匹配当前胃口】
- [910. 最小差值 II](https://leetcode.cn/problems/smallest-range-ii)【排序后枚举唯一可能的分界点】
- [2007. 从双倍数组中还原原数组](https://leetcode.cn/problems/find-original-array-from-doubled-array)【从小到大优先匹配当前数的两倍】
- [2009. 使数组连续的最少操作数](https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-continuous)【排序去重后维护最长合法值域窗口】
- [2171. 拿出最少数目的魔法豆](https://leetcode.cn/problems/removing-minimum-number-of-magic-beans)【枚举保留值，其他值只增不减地清空】
- [2576. 求出最多标记下标](https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices)【小值依次匹配满足条件的最小大值】
- [3789. 采购的最小花费](https://leetcode.cn/problems/minimum-cost-to-acquire-required-items)【比较组合定价的边际成本后优先购买】

#### 7.4 反悔贪心与状态维护

- [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence)【维护各长度的最小结尾；更小结尾总是不劣】
- [517. 超级洗衣机](https://leetcode.cn/problems/super-washing-machines)【用前缀盈亏刻画跨边界的最低传输量】
- [769. 最多能完成排序的块](https://leetcode.cn/problems/max-chunks-to-make-sorted)【前缀最大值等于下标时可安全分块】

#### 7.5 构造、不变量与贡献分配

- [409. 最长回文串](https://leetcode.cn/problems/longest-palindrome)【所有成对字符可保留，至多留一个奇数频次作中心】
- [1702. 修改后的最大二进制字符串](https://leetcode.cn/problems/maximum-binary-string-after-change)【归纳操作后的唯一最优形态】
- [2731. 移动机器人](https://leetcode.cn/problems/movement-of-robots)【相撞等价于穿透，转化为排序后的距离贡献】
- [2818. 操作使得分最大](https://leetcode.cn/problems/apply-operations-to-maximize-score)【单调栈算贡献次数，优先使用更大数】
- [2897. 对数组执行操作使平方和最大](https://leetcode.cn/problems/apply-operations-on-array-to-maximize-sum-of-squares)【平方凸性；将高位尽量集中】

#### 7.6 二分答案中的贪心 check

- [1482. 制作 m 束花所需的最少天数](https://leetcode.cn/problems/minimum-number-of-days-to-make-m-bouquets)【固定天数后从左到右尽早组成花束】
- [2560. 打家劫舍 IV](https://leetcode.cn/problems/house-robber-iv)【固定能力值后尽早选择不相邻房屋】
- [2812. 找出最安全路径](https://leetcode.cn/problems/find-the-safest-path-in-a-grid)【固定安全系数后判定路径是否可达】

#### 7.7 前后缀贪心匹配

> 适用：`pattern` 是 `text` 的子序列，且目标需要最大化或最小化匹配位置之间的跨度。
>
> - 正向贪心：求每个字符最早匹配位置 `L[i]`。
> - 反向贪心：求每个字符最晚匹配位置 `R[i]`。
> - 跨度最大化：前一个字符取 `L[i - 1]`，后一个字符取 `R[i]`，答案为 `max(R[i] - L[i - 1])`。

- [4026. 工位的最大间隔](https://leetcode.cn/problems/maximum-gap-between-stations)【前后缀贪心匹配；最早/最晚匹配位置取极值以最大化相邻跨度】

#### 7.8 堆驱动的贪心：资源调度、候选选择与反悔

> 先按时间或阈值排序，把当前可用对象加入候选堆；再依据目标函数取堆顶。最小堆通常用于“最早释放”或“最小代价”，最大堆通常用于“最大边际收益”或“反悔时淘汰最差选择”。

- [252. 会议室](https://leetcode.cn/problems/meeting-rooms)【按开始时间排序；相邻区间的前一结束时间晚于后一开始时间即发生折叠】
- [253. 会议室 II](https://leetcode.cn/problems/meeting-rooms-ii)【按开始时间扫描；最小堆维护占用会议室的最早结束时间，堆大小即所需会议室数】
- [630. 课程表 III](https://leetcode.cn/problems/course-schedule-iii)【按结束时间选择课程；超时则用最大堆移除耗时最长课程，实现反悔】
- [1792. 最大平均通过率](https://leetcode.cn/problems/maximum-average-pass-ratio)【最大堆维护每次新增一名通过学生带来的边际收益，优先投入收益最大的班级】
- [1834. 单线程 CPU](https://leetcode.cn/problems/single-threaded-cpu)【时间推进；将已到达任务加入最小堆，按处理时间、编号依次选择】
- [1851. 包含每个查询的最小区间](https://leetcode.cn/problems/minimum-interval-to-include-each-query)【排序查询；最小堆维护已开始且尚能覆盖当前查询的候选区间】
- [2402. 会议室 III](https://leetcode.cn/problems/meeting-rooms-iii)【双最小堆：`occupied` 按结束时间维护占用会议室，`ready` 按编号维护空闲会议室；无空闲时延后到最早释放时刻】
- [502. IPO](https://leetcode.cn/problems/ipo)【双堆贪心；按资本解锁项目，用最大堆选择当前收益最高项目】

#### 7.9 栈驱动的贪心：单调淘汰与字典序构造

> 从左到右扫描并维护单调栈。若当前元素比栈顶更优，且栈顶被淘汰后仍能满足长度、去重等约束，就弹出栈顶；被弹出的劣候选不会再进入最优答案。与“求下一个更大元素”的单调栈不同，这里的弹栈是构造最优解的贪心决策。

- [316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters)【最小字典序 + 去重；当前字母更小时，弹出仍会在后面出现的较大栈顶字母】
- [321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number)【与 402 方向相反；在可删除次数内弹出较小栈顶，构造最大字典序子序列后归并】
- [402. 移掉 K 位数字](https://leetcode.cn/problems/remove-k-digits)【最小字典序数值；在删除次数允许时，弹出大于当前数字的栈顶】
- [768. 最多能完成排序的块 II](https://leetcode.cn/problems/max-chunks-to-make-sorted-ii)【单调栈维护每个块的最大值；当前值破坏块间有序性时，弹栈合并冲突块】
- [1081. 不同字符的最小子序列](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters)【316 的等价模型；`inStack` 防重，剩余频次保证被弹字符还能补回】
- [1673. 找出最具竞争力的子序列](https://leetcode.cn/problems/find-the-most-competitive-subsequence)【固定长度的最小字典序；弹出较大栈顶时须保留足够元素填满长度 `k`】

### 8. 分治 (Divide and Conquer)
> **核心逻辑**：
> 1. **分解 (Divide)**：将原问题拆分为规模较小、相互独立的子问题（如左右子树、数组半区）。
> 2. **解决 (Conquer)**：递归解决子问题，直到触及边界。
> 3. **合并 (Combine)**：将子问题的解合并为原问题的解（如归并排序的 `merge` 或 LCA 的状态上传）。

- [50. Pow(x, n)](https://leetcode.cn/problems/powx-n) 【模式：快速幂；将大指数拆分为一半计算，实现 $O(\log n)$】
- [101. 对称二叉树](https://leetcode.cn/problems/symmetric-tree) 【模式：镜像分治；判断 `L->left vs R->right` 且 `L->right vs R->left`】
- [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal) 【模式：结构重建；利用前序定根，中序划分左右子树区间】
- [108. 将有序数组转换为二叉搜索树](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree) 【模式：二分构造；选取中点作为根，递归处理左右子区间】
- [148. 排序链表](https://leetcode.cn/problems/sort-list) 【模式：归并排序；快慢指针找中点 + 递归拆分 + 有序链表合并】
- [222. 完全二叉树的节点个数](https://leetcode.cn/problems/count-complete-tree-nodes) 【模式：属性统计；利用完全二叉树性质，通过高度差判断满二叉树并递归】
- [236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree) 【模式：状态上传；递归寻找左右子树中的目标，根据返回值决策】


## 数学

数学专题负责导航和完整题单；完整公式、证明思路、C++ 模板、易错点与复习计划见：[数学、位运算与随机算法复习手册](../template/1-数学.md)。

### 1. 基础数论

质数判断、埃氏筛、质因数分解、GCD / LCM、丑数与阶乘因子。

- [204. 计数质数](https://leetcode.cn/problems/count-primes)【埃氏筛；从质数的平方开始标记合数】
- [263. 丑数](https://leetcode.cn/problems/ugly-number)【质因数分解；反复除去 2、3、5 判断剩余值是否为 1】
- [264. 丑数 II](https://leetcode.cn/problems/ugly-number-ii)【三指针 DP；分别生成乘以 2、3、5 的候选值并去重】
- [172. 阶乘后的零](https://leetcode.cn/problems/factorial-trailing-zeroes)【统计因子 5；答案为 `n/5 + n/25 + ...`】
- [1998. 数组的最大公因数排序](https://leetcode.cn/problems/gcd-sort-of-an-array)【质因数分解 + 并查集；按公共质因数连接可交换元素】
- [2709. 最大公约数遍历](https://leetcode.cn/problems/greatest-common-divisor-traversal)【质因数分解 + 连通性；判断所有元素是否属于同一连通块】

### 2. 模运算与快速幂

模运算、快速幂、乘法逆元、扩展欧几里得、费马小定理和模意义下组合数。

- [50. Pow(x, n)](https://leetcode.cn/problems/powx-n)【二分快速幂；按指数二进制位累乘，注意负数边界】
- [372. 超级次方](https://leetcode.cn/problems/super-pow)【模意义快速幂；按十进制位递推指数并结合欧拉/费马性质】
- [2842. 统计一个字符串的 k 子序列美丽值最大的数目](https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty)【频次排序 + 组合数；处理临界频次的选取方案】
- [3463. 判断操作后字符串中的数字是否相等 II](https://leetcode.cn/problems/check-if-digits-are-equal-in-string-after-operations-ii)【组合数 + 模运算；用二项式系数压缩多轮差分】

### 3. 组合数学与计数

组合数、排列、容斥和方案计数。

- [77. 组合](https://leetcode.cn/problems/combinations)【回溯枚举组合；用 `start` 保证不重复选择】
- [118. 杨辉三角](https://leetcode.cn/problems/pascals-triangle)【组合数递推；每项由上一行相邻两项相加得到】
- [2930. 重新排列后包含指定子字符串的字符串数目](https://leetcode.cn/problems/number-of-strings-which-can-be-rearranged-to-contain-substring)【容斥原理 + 组合计数；统计至少包含目标字符集合的排列数】
- [3154. 到达第 K 级台阶的方案数](https://leetcode.cn/problems/find-number-of-ways-to-reach-the-k-th-stair)【组合数 + 状态计数；按跳跃次数确定可达位置】
- [3405. 统计恰好有 K 个相等相邻元素的数组数目](https://leetcode.cn/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements)【组合计数；先选择相等相邻位置，再填充不同元素】

### 4. 数位与数字构造

数位统计、数位 DP、前导零、上界限制和数字切分。

- [233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one)【数位统计；按当前位、高位和低位分情况计数】
- [400. 第 N 位数字](https://leetcode.cn/problems/nth-digit)【数字分组定位；按位数段扣除数量后定位具体数字和数字位】
- [2698. 求一个整数的惩罚数](https://leetcode.cn/problems/find-the-punishment-number-of-an-integer)【数字切分 + DFS；枚举平方数的分段和是否等于原数】
- [2801. 统计范围内的步进数字数目](https://leetcode.cn/problems/count-stepping-numbers-in-range)【数位 DP；状态记录上一位、上界和前导零】
- [3007. 价值和小于等于 K 的最大数字](https://leetcode.cn/problems/maximum-number-that-sum-the-prices-is-less-than-or-equal-to-k)【答案二分 + 数位计数；检查区间内数字价值总和】

### 5. 位运算

lowbit、x & (x - 1)、异或、位掩码和二进制 Trie。

- [190. 颠倒二进制位](https://leetcode.cn/problems/reverse-bits)【逐位处理；循环取出最低位并移入结果】
- [191. 位 1 的个数](https://leetcode.cn/problems/number-of-1-bits)【`x & (x - 1)`；每次消去一个最低位的 1】
- [231. 2 的幂](https://leetcode.cn/problems/power-of-two)【位性质；正数且满足 `x & (x - 1) == 0`】
- [260. 只出现一次的数字 III](https://leetcode.cn/problems/single-number-iii)【异或分组；利用最低不同位将两个答案分开】
- [318. 最大单词长度乘积](https://leetcode.cn/problems/maximum-product-of-word-lengths)【位掩码表示字符集合；通过按位与判断是否有公共字符】
- [421. 数组中两个数的最大异或值](https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array)【二进制 Trie；从高位到低位贪心寻找相反位】

### 6. 随机化与概率算法

随机集合、水塘抽样、Fisher–Yates 洗牌、拒绝采样、加权随机、无重复抽样和几何随机。

- [380. O(1) 时间插入、删除和获取随机元素](https://leetcode.cn/problems/insert-delete-getrandom-o1)【数组 + 哈希表；用交换尾元素实现常数时间删除】
- [381. O(1) 时间插入、删除和获取随机元素 II](https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed)【重复元素随机集合；哈希表维护值到多个下标的集合】
- [382. 链表随机节点](https://leetcode.cn/problems/linked-list-random-node)【水塘抽样；遍历时以 `1/i` 概率替换候选节点】
- [384. 打乱数组](https://leetcode.cn/problems/shuffle-an-array)【Fisher–Yates 洗牌；第 `i` 位从未确定区间均匀选择】
- [398. 随机数索引](https://leetcode.cn/problems/random-pick-index)【水塘抽样；只遍历匹配目标的元素并保持等概率】
- [470. 用 Rand7() 实现 Rand10()](https://leetcode.cn/problems/implement-rand10-using-rand7)【拒绝采样；构造足够大的均匀空间后舍弃超出部分】
- [478. 在圆内随机生成点](https://leetcode.cn/problems/generate-random-point-in-a-circle)【几何随机；半径按平方根变换避免点集中在圆心】
- [497. 非重叠矩形中的随机点](https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles)【面积加权；前缀和定位矩形后在矩形内均匀取点】
- [519. 随机翻转矩阵](https://leetcode.cn/problems/random-flip-matrix)【无重复随机抽样；映射已抽位置并用哈希表实现近似 O(1)】
- [528. 按权重随机选择](https://leetcode.cn/problems/random-pick-with-weight)【前缀和 + 二分；在总权重区间内均匀取随机数】
- [710. 黑名单中的随机数](https://leetcode.cn/problems/random-pick-with-blacklist)【黑名单映射；将合法区间尾部的黑名单值映射到前部合法值】

### 7. 几何与距离

斜率规范化、矩形与面积、曼哈顿距离、欧式距离和切比雪夫距离。

- [149. 直线上最多的点数](https://leetcode.cn/problems/max-points-on-a-line)【斜率规范化；用最大公约数统一方向并统计共线点】
- [223. 矩形面积](https://leetcode.cn/problems/rectangle-area)【面积容斥；总面积减去重叠矩形面积】
- [836. 矩形重叠](https://leetcode.cn/problems/rectangle-overlap)【坐标判断；检查两个轴方向的投影是否有正长度交集】
- [3102. 最小化曼哈顿距离](https://leetcode.cn/problems/minimize-manhattan-distances)【坐标变换；利用 `x+y` 与 `x-y` 的极值处理曼哈顿距离】

跨专题题目以主算法所属章节为准；例如 478、497 主归类在随机化专题，138 主归类在链表专题。

## 搜索问题

搜索专题负责导航和完整题单；完整的识别信号、搜索不变量、C++ 模板、易错点和 7 天复习闭环见：[搜索专题复习手册](../template/5-搜索.md)。

### 1. 二分查找与答案二分

覆盖标准二分、边界、旋转数组、峰值、二维单调性，以及“最小的最大值/最大的最小值”这类可行性二分。

- [4. 寻找两个正序数组的中位数](https://leetcode.cn/problems/median-of-two-sorted-arrays)【二分划分；在较短数组上寻找切割点，平衡左右两侧元素数量】
- [33. 搜索旋转排序数组](https://leetcode.cn/problems/search-in-rotated-sorted-array)【旋转数组二分；判断一侧有序区间后收缩范围】
- [34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array)【两次边界二分；分别查找第一个和最后一个目标位置】
- [74. 搜索二维矩阵](https://leetcode.cn/problems/search-a-2d-matrix)【将矩阵按行展开为一维有序数组后进行二分】
- [162. 寻找峰值](https://leetcode.cn/problems/find-peak-element)【局部单调二分；根据相邻元素大小向上坡方向移动】
- [153. 寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array)【比较 `mid` 与右端点；定位旋转点所在的无序区间】
- [154. 寻找旋转排序数组中的最小值 II](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii)【重复元素导致无法判断时收缩右边界】
- [1482. 制作 m 束花所需的最少天数](https://leetcode.cn/problems/minimum-number-of-days-to-make-m-bouquets)【二分最小天数；用贪心判断能否组成足够花束】
- [410. 分割数组的最大值](https://leetcode.cn/problems/split-array-largest-sum)【二分答案；贪心检查分段数量是否不超过限制】

### 2. BFS 与状态空间最短路

覆盖网格、连通分量、单源/多源/双向 BFS，以及状态建模；带权最短路和完整图算法转到图论专题。

- [127. 单词接龙](https://leetcode.cn/problems/word-ladder)【双向 BFS；用通用状态模式减少邻接状态生成成本】
- [200. 岛屿数量](https://leetcode.cn/problems/number-of-islands)【网格 BFS/DFS；遍历每个未访问陆地并统计连通分量】
- [433. 最小基因变化](https://leetcode.cn/problems/minimum-genetic-mutation)【状态图 BFS；每次修改一个字符并按层数求最少变化次数】
- [752. 打开转盘锁](https://leetcode.cn/problems/open-the-lock)【状态空间 BFS；四位密码每次转动一格，避开死亡状态】
- [909. 蛇梯棋](https://leetcode.cn/problems/snakes-and-ladders)【棋盘状态 BFS；将编号映射到坐标并模拟一次掷骰转移】
- [994. 腐烂的橘子](https://leetcode.cn/problems/rotting-oranges)【多源 BFS；所有腐烂橘子同时作为初始层扩散】
- [1306. 跳跃游戏 III](https://leetcode.cn/problems/jump-game-iii)【数组状态 BFS/DFS；访问下标并避免重复跳转】
- [1345. 跳跃游戏 IV](https://leetcode.cn/problems/jump-game-iv)【BFS + 值到下标映射；同值下标只扩展一次】
- [1368. 使网格图至少有一条有效路径的最小代价](https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid)【0-1 BFS；免费沿箭头走，改变方向代价为 1】

### 3. DFS 与回溯

覆盖组合、排列、子集、棋盘约束、网格路径和剪枝。只求计数/最值的背包模型归入 DP 专题。

- [17. 电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number)【多叉树回溯；每一位从电话按键映射中选择一个字符】
- [22. 括号生成](https://leetcode.cn/problems/generate-parentheses)【约束回溯；左括号不超过 n，右括号数量不能超过左括号】
- [39. 组合总和](https://leetcode.cn/problems/combination-sum)【可重复组合；递归继续从当前下标选择】
- [40. 组合总和 II](https://leetcode.cn/problems/combination-sum-ii)【不可重复组合 + 去重；排序后进行树层去重】
- [46. 全排列](https://leetcode.cn/problems/permutations)【排列回溯；用 `used` 标记当前路径已经使用的元素】
- [47. 全排列 II](https://leetcode.cn/problems/permutations-ii)【重复排列去重；排序后结合 `used` 做树层剪枝】
- [51. N 皇后](https://leetcode.cn/problems/n-queens)【棋盘回溯；用列、主对角线和副对角线快速判断冲突】
- [52. N 皇后 II](https://leetcode.cn/problems/n-queens-ii)【棋盘回溯计数；状态与 N 皇后相同但只累计方案数】
- [79. 单词搜索](https://leetcode.cn/problems/word-search)【网格回溯；原地标记访问位置并在递归结束后恢复】
- [131. 分割回文串](https://leetcode.cn/problems/palindrome-partitioning)【字符串回溯 + 预处理；枚举切分位置并判断子串回文】
- [698. 划分为 k 个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets)【回溯 + 剪枝；按桶分配元素并跳过等价桶状态】

### 4. 逆向、状态压缩与启发式搜索

覆盖从边界反向标记、把额外约束编码进状态，以及 A* 等需要估价函数的搜索。专题实现和边界说明见模板。

- [130. 被围绕的区域](https://leetcode.cn/problems/surrounded-regions)【逆向搜索；从边界出发标记不会被包围的区域】
- [847. 访问所有节点的最短路径](https://leetcode.cn/problems/shortest-path-visiting-all-nodes)【状态压缩 BFS；状态为当前位置与已访问节点集合】
- [2850. 将石头分散到网格图的最少移动次数](https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid)【状态压缩 + 回溯；枚举多余石块向空位移动】
> 模板：[八数码 A* 模板](../其它常见的题目/src/graph_a_star_eight_puzzle.cc)【A* 启发式搜索；用曼哈顿距离估计当前状态到目标的代价】



## DP问题（递推类DP）

DP 专题负责粗粒度分类和完整题单；完整的状态定义、转移推导、C++ 模板、易错点与 7 天复习闭环见：[动态规划复习手册](../template/3-DP.md)。

### 1. 线性 DP 与状态机

处理位置、天数或阶段按顺序推进的状态；重点是明确“以当前位置结尾”和“当前持有哪些状态”。

- [45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii)【线性状态；维护到达当前位置的最少跳跃次数】
- [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray)【Kadane；维护以当前位置结尾的最大子数组和】
- [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs)【线性递推；当前状态由前两级转移】
- [198. 打家劫舍](https://leetcode.cn/problems/house-robber)【状态机；当前房屋在“偷/不偷”之间选择】
- [309. 买卖股票的最佳时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown)【状态机 DP；持有、卖出、冷冻期分别建模】
- [746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs)【滚动 DP；到达当前台阶的最小代价】

### 2. 背包 DP

根据物品使用次数区分 0/1、完全、多重、分组和多维背包；先判断目标是可达性、最值还是计数。

- [139. 单词拆分](https://leetcode.cn/problems/word-break)【完全背包式可达性；判断前缀能否由字典单词拼出】
- [322. 零钱兑换](https://leetcode.cn/problems/coin-change)【完全背包最值；求凑成金额的最少硬币数】
- [416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum)【0/1 背包可达性；目标容量为总和的一半】
- [474. 一和零](https://leetcode.cn/problems/ones-and-zeroes)【二维 0/1 背包；同时限制 0 和 1 的数量】
- [494. 目标和](https://leetcode.cn/problems/target-sum)【0/1 背包计数；将正负号选择转为目标和】
- [518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-ii)【完全背包组合计数；物品放在外层避免排列重复】
- [698. 划分为 k 个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets)【状态压缩/回溯；把元素分配到等和桶中】
- [879. 盈利计划](https://leetcode.cn/problems/profitable-schemes)【二维 0/1 计数；人数和利润共同构成状态】

### 3. 双序列与序列 DP

两个字符串/数组通常使用 `dp[i][j]`；连续子数组、子序列和编辑操作要分别建模。

- [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring)【区间/序列 DP；由短区间判断长区间】
- [72. 编辑距离](https://leetcode.cn/problems/edit-distance)【双序列 DP；插入、删除、替换对应三种转移】
- [1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence)【LCS；相等时取对角线，否则取上/左最大值】
- [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence)【序列 DP；也可用贪心 + 二分优化到 `O(n log n)`】
- [354. 俄罗斯套娃信封问题](https://leetcode.cn/problems/russian-doll-envelopes)【排序 + LIS；宽度升序、相同宽度高度降序】
- [583. 两个字符串的删除操作](https://leetcode.cn/problems/delete-operation-for-two-strings)【LCS 变形；长度减去公共子序列贡献】
- [673. 最长递增子序列的个数](https://leetcode.cn/problems/number-of-longest-increasing-subsequence)【长度 DP + 方案计数】
- [1035. 不相交的线](https://leetcode.cn/problems/uncrossed-lines)【数组版 LCS；匹配元素不能交叉】

### 4. 区间 DP

状态通常为 `dp[l][r]`，依赖更短区间；常见思路是枚举最后一次合并或最后一个被处理的位置。

- [312. 戳气球](https://leetcode.cn/problems/burst-balloons)【区间 DP；枚举区间内最后被戳破的气球】
- [375. 猜数字大小 II](https://leetcode.cn/problems/guess-number-higher-or-lower-ii)【区间最坏代价 DP；枚举第一次猜测位置】
- [516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence)【区间 DP；两端相等时向内转移】
- [877. 石子游戏](https://leetcode.cn/problems/stone-game)【区间博弈 DP；维护当前玩家相对对手的最优差值】
- [887. 鸡蛋掉落](https://leetcode.cn/problems/super-egg-drop)【状态优化 DP；按操作次数计算可覆盖楼层数】
- [1140. 石子游戏 II](https://leetcode.cn/problems/stone-game-ii)【区间 + 状态 DP；状态包含当前位置和可取石子上限】

### 5. 树形 DP 与图上 DP

树上状态通过后序 DFS 从子树向父节点汇总；图上若存在 DAG 结构，可按拓扑序转移。

- [124. 二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum)【树形 DP；节点向父节点只贡献单侧最大收益】
- [337. 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii)【树上选/不选状态；父子节点不能同时选择】
- [543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree)【后序 DFS；汇总左右子树最大深度】
- [834. 树中距离之和](https://leetcode.cn/problems/sum-of-distances-in-tree)【换根 DP；第一次统计子树，第二次向子节点换根】
- [2246. 相邻字符不同的最长路径](https://leetcode.cn/problems/longest-path-with-different-adjacent-characters)【树形 DP；每个节点保留满足条件的两条最长向下链】
- [2646. 最小化旅行的价格总和](https://leetcode.cn/problems/minimize-the-total-price-of-the-trips)【树上差分 + 树形 DP；统计节点经过次数后做选/不选】
- [3291. 形成目标字符串需要的最少字符串数 I](https://leetcode.cn/problems/minimum-number-of-valid-strings-to-form-target-i)【Trie + 线性 DP；从每个位置转移可匹配的前缀】

### 6. 状态压缩 DP

当已选集合或访问集合规模较小，用 `mask` 表示集合；状态通常是 `dp[mask]` 或 `dp[mask][last]`。

- [526. 优美的排列](https://leetcode.cn/problems/beautiful-arrangement)【位掩码回溯/DP；记录已经使用的数字集合】
- [638. 大礼包](https://leetcode.cn/problems/shopping-offers)【状态压缩记忆化；状态表示各类商品剩余需求】
- [847. 访问所有节点的最短路径](https://leetcode.cn/problems/shortest-path-visiting-all-nodes)【状态压缩 BFS；状态为当前位置与已访问节点集合】
- [996. 正方形数组的数目](https://leetcode.cn/problems/number-of-squareful-arrays)【状态压缩排列 DP；按相邻平方关系转移】
- [2741. 特别的排列](https://leetcode.cn/problems/special-permutations)【位掩码排列 DP；记录最后一个元素和已用集合】

### 7. 数位 DP

统计范围内满足每位约束的数字，核心状态是位置、限制标记、前导零和题目相关状态。

- [233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one)【数位统计；按高位、当前位、低位分情况】
- [600. 不含连续 1 的非负整数](https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones)【数位 DP；记录上一位是否为 1】
- [902. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set)【数位 DP；处理上界和前导零】
- [1012. 至少有 1 位重复的数字](https://leetcode.cn/problems/numbers-with-repeated-digits)【数位 DP + 位掩码；记录已使用数字】
- [2376. 统计特殊整数](https://leetcode.cn/problems/count-special-integers)【数位 DP；统计各位互不相同的数字】
- [2801. 统计范围内的步进数字数目](https://leetcode.cn/problems/count-stepping-numbers-in-range)【数位 DP；记录前一位数字和上界状态】

### 8. 数据结构优化与倍增 DP

当转移需要区间最值、前驱跳转或大量重复查询时，用线段树、树状数组、倍增表等优化。

- [1483. 树节点的第 K 个祖先](https://leetcode.cn/problems/kth-ancestor-of-a-tree-node)【倍增；预处理 `2^j` 级祖先】
- [2407. 最长递增子序列 II](https://leetcode.cn/problems/longest-increasing-subsequence-ii)【线段树优化 DP；查询值域区间最大长度】
- [2713. 矩阵中严格递增的单元格数](https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix)【按值排序 + 行列状态维护】
- [2836. 在传球游戏中最大化函数值](https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-pfassing-game)【倍增跳转；同时维护跳转后的累计贡献】
- [2926. 平衡子序列的最大和](https://leetcode.cn/problems/maximum-balanced-subsequence-sum)【离散化 + 树状数组/线段树维护前缀最大值】

### 9. 博弈 DP、记忆化搜索与矩阵快速幂

有些递推天然适合记忆化搜索；博弈 DP 维护当前玩家相对收益；线性递推可用矩阵快速幂降复杂度。

- [10. 正则表达式匹配](https://leetcode.cn/problems/regular-expression-matching)【记忆化搜索；状态为字符串位置和模式位置】
- [44. 通配符匹配](https://leetcode.cn/problems/wildcard-matching)【记忆化搜索/贪心；处理 `*` 的匹配范围】
- [464. 我能赢吗](https://leetcode.cn/problems/can-i-win)【博弈 + 状态压缩；判断当前玩家是否存在必胜选择】
- [486. 预测赢家](https://leetcode.cn/problems/predict-the-winner)【区间博弈 DP；维护当前玩家相对分差】
- [913. 猫和老鼠](https://leetcode.cn/problems/cat-and-mouse)【图上博弈；状态包含双方位置与轮次】
- [2851. 字符串 K 次转换等于目标串的方案数量](https://leetcode.cn/problems/string-transformation)【KMP/循环结构 + 矩阵快速幂；快速计算多次转移】
- [3283. 吃掉所有兵需要的最多移动次数](https://leetcode.cn/problems/maximum-number-of-moves-to-kill-all-pawns)【状态压缩博弈；预计算棋盘移动距离后进行最优转移】

### 10. 完整题单索引

以下条目保留 DP 专题原有完整题单。前面的分类用于按模式学习，本节用于确保题单完整可查；题目可以在不同模式下交叉出现。

- [45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii)【线性 DP/贪心；维护到达当前位置的最少跳跃次数】
- [53. 最大子数组和](https://leetcode.cn/problems/maximum-subarray)【Kadane；维护以当前位置结尾的最大子数组和】
- [55. 跳跃游戏](https://leetcode.cn/problems/jump-game)【线性可达性；维护当前能够到达的最远位置】
- [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs)【线性递推；当前状态由前两级转移】
- [152. 乘积最大子数组](https://leetcode.cn/problems/maximum-product-subarray)【维护最大值和最小值，应对负数翻转】
- [264. 丑数 II](https://leetcode.cn/problems/ugly-number-ii)【三指针生成丑数并去重】
- [509. 斐波那契数](https://leetcode.cn/problems/fibonacci-number)【滚动数组；只保留前两项】
- [746. 使用最小花费爬楼梯](https://leetcode.cn/problems/min-cost-climbing-stairs)【线性 DP；到达当前台阶的最小花费只依赖前两阶】
- [1043. 分隔数组以得到最大和](https://leetcode.cn/problems/partition-array-for-maximum-sum)【分段 DP；枚举最后一段长度并维护该段最大值】
- [1137. 第 N 个泰波那契数](https://leetcode.cn/problems/n-th-tribonacci-number)【线性 DP；滚动维护前三项】
- [918. 环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray)【Kadane 变形；比较非环形最大和与总和减最小子数组和】
- [1306. 跳跃游戏 III](https://leetcode.cn/problems/jump-game-iii)【图搜索/记忆化；数组位置作为状态】
- [1345. 跳跃游戏 IV](https://leetcode.cn/problems/jump-game-iv)【BFS；按值分组并及时清空已使用的跳转集合】
- [1480. 一维数组的动态和](https://leetcode.cn/problems/running-sum-of-1d-array)【前缀和递推】
- [1997. 访问完所有房间的第一天](https://leetcode.cn/problems/first-day-where-you-have-been-in-all-the-rooms)【线性 DP；根据前一次访问状态转移】
- [2708. 一个小组的最大实力值](https://leetcode.cn/problems/maximum-strength-of-a-group)【维护正负乘积的最大值与最小值】
- [2830. 销售利润最大化](https://leetcode.cn/problems/maximize-the-profit-as-the-salesman)【按结束位置排序的加权区间 DP】
- [3291. 形成目标字符串需要的最少字符串数 I](https://leetcode.cn/problems/minimum-number-of-valid-strings-to-form-target-i)【Trie + 一维线性 DP】
- [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence)【序列 DP，也可用贪心 + 二分优化】
- [354. 俄罗斯套娃信封问题](https://leetcode.cn/problems/russian-doll-envelopes)【排序 + LIS；宽升序、相同宽度高度降序】
- [673. 最长递增子序列的个数](https://leetcode.cn/problems/number-of-longest-increasing-subsequence)【长度 DP + 方案计数】
- [3144. 分割字符频率相等的最少子字符串](https://leetcode.cn/problems/minimum-substring-partition-of-equal-character-frequenc)【一维区间枚举 DP】
- [198. 打家劫舍](https://leetcode.cn/problems/house-robber)【状态机 DP；当前房屋选择偷或不偷】
> 关联题单：打家劫舍系列包含普通、环形、树形和 DP + 二分【同一决策模型的不同状态空间】
- [213. 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii)【环形拆成两个线性区间分别求解】
- [337. 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii)【树形 DP；父子节点不能同时被选】
- [552. 学生出勤记录 II](https://leetcode.cn/problems/student-attendance-record-ii)【三维状态 DP】
- [689. 三个无重叠子数组的最大和](https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays)【前缀和 + 位置 DP】
> 关联题单：将三个数组排序【分组/序列 DP；原题单保留的模式记录】
> 关联题单：买卖股票的最大利润系列【状态机 DP；区分交易次数、冷冻期和手续费】
- [2560. 打家劫舍 IV](https://leetcode.cn/problems/house-robber-iv)【贪心 + 二分答案】
- [3251. 单调数组对的数目 II](https://leetcode.cn/problems/find-the-count-of-monotonic-pairs-ii)【按结尾值维护前缀方案数】
- [120. 三角形最小路径和](https://leetcode.cn/problems/triangle)【自底向上滚动 DP】
- [221. 最大正方形](https://leetcode.cn/problems/maximal-square)【二维 DP；维护以当前位置为右下角的最大正方形边长】
- [3148. 矩阵中的最大得分](https://leetcode.cn/problems/maximum-difference-score-in-a-grid)【网格 DP；维护后续区域的最优值】
- [5. 最长回文子串](https://leetcode.cn/problems/longest-palindromic-substring)【区间 DP/中心扩展】
- [1143. 最长公共子序列](https://leetcode.cn/problems/longest-common-subsequence)【LCS；相等时取对角线，否则取上/左最大值】
> 关联题单：将一个字符串分割成回文串，最少分割次数【回文预处理 + 区间/前缀 DP】
- [72. 编辑距离](https://leetcode.cn/problems/edit-distance)【双序列 DP；插入、删除、替换对应三种转移】
- [115. 不同的子序列](https://leetcode.cn/problems/distinct-subsequences)【双序列计数 DP】
- [300. 最长递增子序列](https://leetcode.cn/problems/longest-increasing-subsequence)【LIS；维护前驱或牌堆顶部】
- [2901. 最长相邻不相等子序列 II](https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-ii)【带约束的序列 DP】
- [516. 最长回文子序列](https://leetcode.cn/problems/longest-palindromic-subsequence)【区间 DP；两端相等时向内转移】
- [2915. 和为目标值的最长子序列的长度](https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target)【0/1 背包；恰好装满并最大化长度】
- [583. 两个字符串的删除操作](https://leetcode.cn/problems/delete-operation-for-two-strings)【LCS 变形；长度减去公共子序列贡献】
- [646. 最长数对链](https://leetcode.cn/problems/maximum-length-of-pair-chain)【排序 + 贪心/DP；按尾端选择尽早结束的数对】
- [1035. 不相交的线](https://leetcode.cn/problems/uncrossed-lines)【数组版 LCS】
- [3098. 求出所有子序列的能量和](https://leetcode.cn/problems/find-the-sum-of-subsequence-powers)【子序列状态 DP】
- [3130. 找出所有稳定的二进制数组 II](https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-ii)【以 0 或 1 结尾的方案数 DP】
- [416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum)【0/1 背包可达性】
- [494. 目标和](https://leetcode.cn/problems/target-sum)【转化为子集和计数】
- [1049. 最后一块石头的重量 II](https://leetcode.cn/problems/last-stone-weight-ii)【分组后尽量接近的 0/1 背包】
- [322. 零钱兑换](https://leetcode.cn/problems/coin-change)【完全背包最小值】
- [518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-ii)【完全背包组合计数】
- [279. 完全平方数](https://leetcode.cn/problems/perfect-squares)【完全背包最小值】
- [139. 单词拆分](https://leetcode.cn/problems/word-break)【完全背包式可达性】
- [1449. 数位成本和为目标值的最大数字](https://leetcode.cn/problems/form-largest-integer-with-digits-that-add-up-to-target)【先最大化位数，再恢复字典序】
- [2585. 获得分数的方法数](https://leetcode.cn/problems/number-of-ways-to-earn-points)【分组背包计数】
- [1155. 掷骰子等于目标和的方法数](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum)【分组背包计数】
- [2218. 从栈中取出 K 个硬币的最大面值和](https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles)【分组背包；组内取前缀】
- [4040. 构造子集和的最少操作次数 I](https://leetcode.cn/problems/minimum-operations-to-form-subset-sum-i)【分组背包/最小代价】
- [4041. 构造子集和的最少操作次数 II](https://leetcode.cn/problems/minimum-operations-to-form-subset-sum-ii)【组内状态转移 + 恰好装满 DP】
- [474. 一和零](https://leetcode.cn/problems/ones-and-zeroes)【二维 0/1 背包】
- [879. 盈利计划](https://leetcode.cn/problems/profitable-schemes)【人数和利润共同构成状态】
- [312. 戳气球](https://leetcode.cn/problems/burst-balloons)【区间 DP；枚举最后被戳破的气球】
- [375. 猜数字大小 II](https://leetcode.cn/problems/guess-number-higher-or-lower-ii)【区间最坏代价 DP】
- [887. 鸡蛋掉落](https://leetcode.cn/problems/super-egg-drop)【按操作次数计算覆盖楼层数】
- [877. 石子游戏](https://leetcode.cn/problems/stone-game)【区间博弈 DP】
- [1140. 石子游戏 II](https://leetcode.cn/problems/stone-game-ii)【区间 + 状态 DP】
- [526. 优美的排列](https://leetcode.cn/problems/beautiful-arrangement)【位掩码回溯/DP】
- [638. 大礼包](https://leetcode.cn/problems/shopping-offers)【状态压缩记忆化】
- [691. 贴纸拼词](https://leetcode.cn/problems/stickers-to-spell-word)【状态压缩记忆化搜索】
- [698. 划分为 k 个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets)【状态压缩/回溯】
- [2741. 特别的排列](https://leetcode.cn/problems/special-permutations)【位掩码排列 DP】
- [894. 所有可能的真二叉树](https://leetcode.cn/problems/all-possible-full-binary-trees)【区间/树形递归 DP】
- [2646. 最小化旅行的价格总和](https://leetcode.cn/problems/minimize-the-total-price-of-the-trips)【树上差分 + 树形 DP】
- [2920. 收集所有金币可获得的最大积分](https://leetcode.cn/problems/maximum-points-after-collecting-coins-from-all-nodes)【树形 DP】
- [2925. 在树上执行操作以后得到的最大分数](https://leetcode.cn/problems/maximum-score-after-applying-operations-on-a-tree)【树形 DP】
- [3203. 合并两棵树后的最小直径](https://leetcode.cn/problems/find-minimum-diameter-after-merging-two-trees)【树的直径与贪心】
- [124. 二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum)【树形 DP；节点向父节点只贡献单侧最大收益】
- [543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree)【后序 DFS 汇总左右子树深度】
- [687. 最长同值路径](https://leetcode.cn/problems/longest-univalue-path)【树形 DP；维护向下的同值链】
- [2246. 相邻字符不同的最长路径](https://leetcode.cn/problems/longest-path-with-different-adjacent-characters)【树形 DP；保留两条最长合法向下链】
- [834. 树中距离之和](https://leetcode.cn/problems/sum-of-distances-in-tree)【换根 DP】
- [2581. 统计可能的树根数目](https://leetcode.cn/problems/count-number-of-possible-root-nodes)【换根 DP + 计数】
- [2858. 可以到达每一个节点的最少边反转次数](https://leetcode.cn/problems/minimum-edge-reversals-so-every-node-is-reachable)【换根 DP】
- [3241. 标记所有节点需要的时间](https://leetcode.cn/problems/time-taken-to-mark-all-nodes)【树形 DP】
- [233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one)【数位 DP】
- [600. 不含连续 1 的非负整数](https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones)【数位 DP；记录上一位是否为 1】
- [902. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set)【数位 DP；处理上界和前导零】
- [1012. 至少有 1 位重复的数字](https://leetcode.cn/problems/numbers-with-repeated-digits)【数位 DP + 位掩码】
- [2376. 统计特殊整数](https://leetcode.cn/problems/count-special-integers)【数位 DP；统计各位互不相同的数字】
- [2719. 统计整数数目](https://leetcode.cn/problems/count-of-integers)【数位 DP】
- [2801. 统计范围内的步进数字数目](https://leetcode.cn/problems/count-stepping-numbers-in-range)【数位 DP；记录前一位数字和上界状态】
- [2827. 范围中美丽整数的数目](https://leetcode.cn/problems/number-of-beautiful-integers-in-the-range)【数位 DP + 奇偶计数】
- [3791. 给定范围内平衡整数的数目](https://leetcode.cn/problems/number-of-balanced-integers-in-a-range)【数位 DP；维护平衡差值】
- [2407. 最长递增子序列 II](https://leetcode.cn/problems/longest-increasing-subsequence-ii)【线段树优化，区间最大值】
- [2713. 矩阵中严格递增的单元格数](https://leetcode.cn/problems/maximum-strictly-increasing-cells-in-a-matrix)【按值排序 + 行列状态维护】
- [2926. 平衡子序列的最大和](https://leetcode.cn/problems/maximum-balanced-subsequence-sum)【离散化 + 树状数组/线段树】
- [1483. 树节点的第 K 个祖先](https://leetcode.cn/problems/kth-ancestor-of-a-tree-node)【倍增；预处理 `2^j` 级祖先】
- [2836. 在传球游戏中最大化函数值](https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game)【倍增跳转 + 累计贡献】
> 知识点：LCA【树上祖先查询；可用倍增或树链剖分】
- [2846. 边权重均等查询](https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree)【LCA + 路径频次统计】
- [2851. 字符串 K 次转换等于目标串的方案数量](https://leetcode.cn/problems/string-transformation)【KMP/循环结构 + 矩阵快速幂】
- [10. 正则表达式匹配](https://leetcode.cn/problems/regular-expression-matching)【记忆化搜索；处理 `*` 的匹配范围】
- [44. 通配符匹配](https://leetcode.cn/problems/wildcard-matching)【记忆化搜索/贪心；处理 `*`】
- [464. 我能赢吗](https://leetcode.cn/problems/can-i-win)【博弈 + 状态压缩】
- [486. 预测赢家](https://leetcode.cn/problems/predict-the-winner)【区间博弈 DP】
- [1025. 除数博弈](https://leetcode.cn/problems/divisor-game)【博弈 DP，也可用数学结论】
- [913. 猫和老鼠](https://leetcode.cn/problems/cat-and-mouse)【图上博弈；状态包含双方位置与轮次】
- [1140. 石子游戏 II](https://leetcode.cn/problems/stone-game-ii)【区间状态 DP】
- [1406. 石子游戏 III](https://leetcode.cn/problems/stone-game-iii)【区间博弈 DP】
- [1510. 石子游戏 IV](https://leetcode.cn/problems/stone-game-iv)【完全平方数 + 博弈 DP】
- [1563. 石子游戏 V](https://leetcode.cn/problems/stone-game-v)【区间博弈 DP】
- [1690. 石子游戏 VII](https://leetcode.cn/problems/stone-game-vii)【区间博弈 DP】
- [1872. 石子游戏 VIII](https://leetcode.cn/problems/stone-game-viii)【后缀最优值 + 博弈 DP】
- [3283. 吃掉所有兵需要的最多移动次数](https://leetcode.cn/problems/maximum-number-of-moves-to-kill-all-pawns)【状态压缩博弈】
- [2597. 美丽子集的数目](https://leetcode.cn/problems/the-number-of-beautiful-subsets)【状态压缩/记忆化；按数值冲突关系进行选择】
- [2742. 给墙壁刷油漆](https://leetcode.cn/problems/painting-the-walls)【状态优化背包；将付费工人的时间覆盖转化为容量】
- [2811. 判断是否能拆分数组](https://leetcode.cn/problems/check-if-it-is-possible-to-split-array)【区间递推/记忆化；判断区间能否继续拆分】
- [3129. 找出所有稳定的二进制数组 I](https://leetcode.cn/problems/find-all-possible-stable-binary-arrays-i)【二维计数 DP；限制连续相同元素长度】

## 树与图论 (Tree & Graph - 核心模式归类)

树与图论专题负责导航和完整题单；完整的建模、算法模板、复杂度、易错点和 7 天复习闭环见：[图论与树复习手册](../template/4-图论.md)。

### 1. 并查集 (Union Find)
> 模板：[并查集 (Union Find) 模板与应用](https://github.com/wxquare/online-algorithm-coding/blob/master/other/union_find.cc)【路径压缩 + 按大小合并；维护连通块和集合大小】
- [547. 省份的数量](https://leetcode.cn/problems/number-of-provinces)【并查集或 DFS；统计无向图的连通分量】
- [684. 冗余连接](https://leetcode.cn/problems/redundant-connection)【并查集；首次合并失败的边会在当前图中形成环】
- [721. 账户合并](https://leetcode.cn/problems/accounts-merge)【邮箱映射 + 并查集；将共享邮箱的账户连接起来】
- [924. 尽量减少恶意软件的传播](https://leetcode.cn/problems/minimize-malware-spread)【并查集；统计每个连通块的感染源数量和规模】
- [928. 尽量减少恶意软件的传播 II](https://leetcode.cn/problems/minimize-malware-spread-ii)【枚举删除源 + 连通块统计；比较能阻止的感染规模】
- [1998. 数组的最大公因数排序](https://leetcode.cn/problems/gcd-sort-of-an-array)【质因数分解 + 并查集；按公共质因数连接可交换元素】
- [2709. 最大公约数遍历](https://leetcode.cn/problems/greatest-common-divisor-traversal)【质因数分解 + 连通性；判断所有元素是否属于同一连通块】

### 2. 网格搜索与连通性 (DFS/BFS)
- [127. 单词接龙](https://leetcode.cn/problems/word-ladder)【双向 BFS；利用通配中间态减少邻接状态生成成本】
- [130. 被围绕的区域](https://leetcode.cn/problems/surrounded-regions)【逆向搜索；从边界 `'O'` 开始标记，剩余内部 `'O'` 填充】
- [133. 克隆图](https://leetcode.cn/problems/clone-graph)【哈希表 + DFS/BFS；保存原节点到新节点的映射防止死循环】
- [200. 岛屿数量](https://leetcode.cn/problems/number-of-islands)【网格 DFS/BFS；原地沉岛并统计连通分量】
- [305. 岛屿数量 II](https://leetcode.cn/problems/number-of-islands-ii)【动态并查集；每次将新陆地与相邻陆地合并】
- [399. 除法求值](https://leetcode.cn/problems/evaluate-division)【带权图搜索；变量为节点、比值为边权并沿路径相乘】
- [433. 最小基因变化](https://leetcode.cn/problems/minimum-genetic-mutation)【单向/双向 BFS；每次修改一个字符求最少变化次数】
- [909. 蛇梯棋](https://leetcode.cn/problems/snakes-and-ladders)【状态图 BFS；将一维编号映射到棋盘坐标后模拟掷骰】
- [2101. 引爆最多的炸弹](https://leetcode.cn/problems/detonate-the-maximum-bombs)【建有向图 + DFS/BFS；从每个起点统计可达炸弹数量】
- [2258. 逃离火灾](https://leetcode.cn/problems/escape-the-spreading-fire)【多源 BFS + 答案二分；先预处理火势到达时间，再检查逃生可行性】
- [2385. 感染二叉树需要的总时间](https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected)【树转无向图 + BFS；求感染起点到最远节点的距离】
- [310. 最小高度树](https://leetcode.cn/problems/minimum-height-trees)【拓扑剥叶；不断删除叶子，最后剩余节点是树中心】

### 3. 拓扑排序 (有向无环图 DAG)
- [207. 课程表](https://leetcode.cn/problems/course-schedule)【入度统计 + Kahn；判断拓扑序是否覆盖所有课程】
- [210. 课程表 II](https://leetcode.cn/problems/course-schedule-ii)【BFS 拓扑排序；记录入度为 0 的节点弹出顺序】
- [2603. 收集树中金币](https://leetcode.cn/problems/collect-coins-in-a-tree)【分层剥叶；先删除无金币叶子，再处理可往返的边】

### 4. 最小生成树
在带权无向图中，寻找一棵连接所有节点的树，使得所有边的权重之和最小，常用Kruskal或Prim算法。
- [1135. 连接所有城市的最低成本](https://leetcode.cn/problems/connecting-cities-with-minimum-cost)【Kruskal；按边权排序并用并查集合并不同连通块】
- [1168. 水资源分配优化](https://leetcode.cn/problems/optimize-water-distribution-in-a-village)【虚拟源点 + 最小生成树；把每口井的建造成本视为源点边】
- [1584. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points)【Prim；每轮选择距离当前生成树最近的点并松弛】
- [1584. 连接所有点的最小费用](https://leetcode.cn/problems/min-cost-to-connect-all-points)【Kruskal；按曼哈顿距离排序并用并查集选边】

### 5. 最短路径算法 (Dijkstra/Floyd/Bellman)
- [407. 接雨水 II](https://leetcode.cn/problems/trapping-rain-water-ii)【边界优先队列；从最低边界向内扩展并维护当前水位】
- [743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time)【Dijkstra；非负边权单源最短路】
- [1334. 阈值距离内邻居最少的城市](https://leetcode.cn/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance)【Floyd；枚举中间点求全源最短路】
- [1976. 到达目的地的方案数](https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination)【Dijkstra + 方案计数；最短距离相同时累加路径数】
- [2045. 到达目的地的第二短时间](https://leetcode.cn/problems/second-minimum-time-to-reach-destination)【最短/次短距离；结合红绿灯等待时间进行状态更新】
- [2065. 最大化一张图中的路径价值](https://leetcode.cn/problems/maximum-path-quality-of-a-graph)【限时 DFS；允许经过重复节点但边和时间必须满足约束】
- [2642. 设计可以求最短路径的图类](https://leetcode.cn/problems/design-graph-with-shortest-path-calculator)【Dijkstra 封装；动态加边后按查询重新求最短路】
- [2812. 找出最安全路径](https://leetcode.cn/problems/find-the-safest-path-in-a-grid)【多源 BFS 预处理安全距离；二分安全系数或求最大瓶颈路】
- [2959. 关闭分部的可行集合数目](https://leetcode.cn/problems/number-of-possible-sets-of-closing-branche)【子集枚举 + Floyd；检查保留节点之间的距离约束】
- [3112. 访问消失节点的最少时间](https://leetcode.cn/problems/minimum-time-to-visit-disappearing-nodes)【带截止时间的 Dijkstra；只扩展能及时到达的节点】
> 模板：[最短路径和 K 短问题汇总](https://github.com/wxquare/online-algorithm-coding/blob/master/other/graph_short_path.cc)【Dijkstra、Bellman-Ford、Floyd 和 K 短路模板汇总】
> 模板：[A* 八数码问题](https://github.com/wxquare/online-algorithm-coding/blob/master/other/8-puzzle.cc)【A*；用不高估的启发函数优先扩展更有希望的状态】

### 6. 二分图 (Bipartite Graph)
判断一个图是否可以被分成两个独立的集合，且所有边都连接两个集合中的节点。常通过染色法（DFS/BFS）解决。
- [785. 判断二分图](https://leetcode.cn/problems/is-graph-bipartite)【BFS/DFS 染色；相邻节点必须属于不同颜色】
- [886. 可能的二分法](https://leetcode.cn/problems/possible-bipartition)【二分图染色；将互相排斥关系建成冲突边】
- [3373. 连接两棵树后最大目标节点数目 II](https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii)【树的奇偶距离对应二分染色；统计两类节点数量】
- [LCP 04. 覆盖](https://leetcode.cn/problems/broken-board-dominoes)【二分图最大匹配；将可放置骨牌的位置看作左右部节点】

### 7. 欧拉路径/回路 (Eulerian Path/Circuit)
寻找一条经过图中每条边恰好一次的路径（欧拉路径）或回路（欧拉回路），常用Hierholzer算法。
- [332. 重新安排行程](https://leetcode.cn/problems/reconstruct-itinerary)【Hierholzer + 有序边；回溯后序加入答案保证字典序】
- [753. 破解保险箱](https://leetcode.cn/problems/cracking-the-safe)【De Bruijn 图欧拉回路；边表示密码片段转移】

### 8. 桥与低链接值 (Tarjan)
在无向图中寻找删除后会破坏连通性的关键边；核心是 DFS 序 `dfn` 与返祖边低点 `low`，而不是强连通分量。
- [1192. 查找集群内的关键连接](https://leetcode.cn/problems/critical-connections-in-a-network)【Tarjan 桥；用 `dfn` 与 `low` 判断删除后会断开的边】

### 9. 基环树 (Functional Graph / Pseudoforest)
一种特殊的图，每个节点有且只有一条出边（有向）或拥有恰好一个环的结构。（拓扑排序 + 环的处理）
- [684. 冗余连接](https://leetcode.cn/problems/redundant-connection)【无向基环树 + 并查集；寻找形成环的冗余边】
- [685. 冗余连接 II](https://leetcode.cn/problems/redundant-connection-ii)【有向基环树；同时处理入度为 2 和有向环】
- [2127. 参加会议的最多员工数](https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting)【内向基环树；比较最长环与多个二元环加最长入链】
- [2359. 找到离给定两个节点最近的节点](https://leetcode.cn/problems/find-closest-node-to-given-two-nodes)【分别计算两源距离；选择双方都可达时最大距离最小的节点】
- [2360. 图中的最长环](https://leetcode.cn/problems/longest-cycle-in-a-graph)【拓扑剥离或时间戳 DFS；计算每个有向环的长度】

### 10. 高级图论与连通性 (基环树/网络流)
- [1489. 找到最小生成树里的关键边和伪关键边](https://leetcode.cn/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree)【Kruskal 重跑；分别强制加入或禁用边判断关键性】
- [2685. 统计完全连通分量的数量](https://leetcode.cn/problems/count-the-number-of-complete-components)【DFS/BFS + 边数统计；比较边数与完全图理论边数】
- [7rLGCR. 守卫城堡](https://leetcode.cn/problems/7rLGCR)【网络流/最小割；将防守和攻击限制建模为容量】
- [2876. 有向图访问计数](https://leetcode.cn/problems/count-visited-nodes-in-a-directed-graph)【基环树 + 反向拓扑 DP；环上节点继承环长】
- [3786. 树组的交互代价总和](https://leetcode.cn/problems/total-sum-of-interaction-cost-in-tree-groups)【树上边贡献法；后序 DFS 统计各组子树数量】
- [6942. 树中可以形成回文的路径数](https://leetcode.cn/problems/count-paths-that-can-form-a-palindrome-in-a-tree)【树上路径状态；用位掩码表示字符奇偶性并统计可配对路径】

## 路径问题：从状态定义到算法选择

“路径”不是单一算法：先识别路径所在的状态空间，再确定目标是**存在性、最短/最优值、方案数，还是具体路径**。本章是跨章节练习导航；题目在原有的数组、树、搜索、DP 与图论章节中仍保留。

| 看到的题面特征 | 优先考虑 | 代表题目 |
| --- | --- | --- |
| 网格中只能向右/下，或转移方向天然无环 | 动态规划 | 62、63、64、120 |
| 无权图、每一步代价相同，要求最少步数 | BFS | 127、433、909、1293 |
| 有非负边权，要求最小代价 | Dijkstra / 0-1 BFS | 743、1368、1631 |
| 要列出全部可行路线 | DFS + 回溯 | 79、113、797 |
| 树上路径和、最长路径或跨子树路径 | DFS + 树形 DP / 前缀和 | 112、124、437、543 |

### 1. 网格与二维结构：路径计数、最值与约束

先确定移动方向能否形成 DAG：若只能向右、向下或逐层前进，通常写出 `dp[i][j]` 即可；若可以四向移动，应转到图搜索或最短路。

- [62. 不同路径](https://leetcode.cn/problems/unique-paths)【路径计数 DP；`dp[i][j] = dp[i-1][j] + dp[i][j-1]`】
- [63. 不同路径 II](https://leetcode.cn/problems/unique-paths-ii)【障碍物置零；注意起点和首行/首列初始化】
- [64. 最小路径和](https://leetcode.cn/problems/minimum-path-sum)【最值 DP；由上方、左方的最小代价转移】
- [79. 单词搜索](https://leetcode.cn/problems/word-search)【矩阵回溯；原地标记、递归后恢复】
- [120. 三角形最小路径和](https://leetcode.cn/problems/triangle)【自底向上 DP；每层只依赖下一层两个相邻状态】
- [329. 矩阵中的最长递增路径](https://leetcode.cn/problems/longest-increasing-path-in-a-matrix)【记忆化 DFS / 拓扑分层；严格递增保证无环】
- [417. 太平洋大西洋水流问题](https://leetcode.cn/problems/pacific-atlantic-water-flow)【逆向多源 DFS/BFS；从两侧海岸向高处扩展】
- [931. 下降路径最小和](https://leetcode.cn/problems/minimum-falling-path-sum)【三方向转移；处理左右越界】
- [1289. 下降路径最小和 II](https://leetcode.cn/problems/minimum-falling-path-sum-ii)【维护上一行最小值和次小值，避免枚举整行】

### 2. 树上路径：根到叶、任意起终点与贡献度

树没有环，但要区分路径是否必须向下、是否必须从根开始、以及是否允许在某个节点“拐弯”。

- [112. 路径总和](https://leetcode.cn/problems/path-sum)【根到叶存在性；DFS 累减目标值】
- [113. 路径总和 II](https://leetcode.cn/problems/path-sum-ii)【输出全部路径；回溯维护当前节点序列】
- [124. 二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum)【树形 DP；向父节点只贡献单侧最大收益】
- [129. 求根节点到叶节点数字之和](https://leetcode.cn/problems/sum-root-to-leaf-numbers)【路径状态累加；向下传递 `sum * 10 + val`】
- [437. 路径总和 III](https://leetcode.cn/problems/path-sum-iii)【任意起点向下；前缀和计数】
- [543. 二叉树的直径](https://leetcode.cn/problems/diameter-of-binary-tree)【后序 DFS；每个节点汇总左右最大深度】
- [687. 最长同值路径](https://leetcode.cn/problems/longest-univalue-path)【后序合并；只有值相同的边能延伸】
- [2246. 相邻字符不同的最长路径](https://leetcode.cn/problems/longest-path-with-different-adjacent-characters)【树上直径变体；过滤不满足字符约束的子树】
- [2673. 使二叉树所有路径值相等的最小代价](https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree)【自底向上平衡左右子树路径和】

### 3. 图与矩阵：可达性、全部路径与最少步数

无权图的“最短路径”就是 BFS 的层数；若要求所有路径，使用 DFS 并显式维护 `path`。存在环时要明确 `visited` 的作用域。

- [126. 单词接龙 II](https://leetcode.cn/problems/word-ladder-ii)【所有最短变换序列；BFS 分层记录前驱关系，再 DFS 回溯恢复路径】
- [127. 单词接龙](https://leetcode.cn/problems/word-ladder)【最少变换步数；双向 BFS 降低搜索规模】
- [200. 岛屿数量](https://leetcode.cn/problems/number-of-islands)【网格连通分量；DFS/BFS 沉岛标记】
- [433. 最小基因变化](https://leetcode.cn/problems/minimum-genetic-mutation)【隐式图 BFS；每次只改变一个字符】
- [797. 所有可能的路径](https://leetcode.cn/problems/all-paths-from-source-to-target)【DAG 全路径枚举；DFS + 回溯】
- [841. 钥匙和房间](https://leetcode.cn/problems/keys-and-rooms)【图遍历；检查可访问节点数】
- [847. 访问所有节点的最短路径](https://leetcode.cn/problems/shortest-path-visiting-all-nodes)【多源 BFS + 状态压缩；状态为 `(node, mask)`】
- [909. 蛇梯棋](https://leetcode.cn/problems/snakes-and-ladders)【状态图 BFS；注意一维编号到棋盘坐标的转换】
- [1293. 网格中的最短路径](https://leetcode.cn/problems/shortest-path-in-a-grid-with-obstacles-elimination)【BFS 状态含剩余消除次数；按格子去重不足】
- [1971. 寻找图中是否存在路径](https://leetcode.cn/problems/find-if-path-exists-in-graph)【DFS/BFS/并查集；连通性判定】

### 4. 带权、最优与第二目标：最短路模型

边权非负时用 Dijkstra；边权只有 0、1 时可用 0-1 BFS；若目标是“路径上最坏边最小”，常把距离定义改成最大值或配合二分答案。

- [743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time)【单源最短路模板；Dijkstra + 最小堆】
- [1368. 使网格图至少有一条有效路径的最小代价](https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid)【0-1 BFS；沿箭头走的边权为 0】
- [1631. 最小体力消耗路径](https://leetcode.cn/problems/path-with-minimum-effort)【最小化路径最大边权；Dijkstra 或二分 + BFS】
- [1976. 到达目的地的方案数](https://leetcode.cn/problems/number-of-ways-to-arrive-at-destination)【Dijkstra 同时维护最短距离与方案数】
- [2045. 到达目的地的第二短时间](https://leetcode.cn/problems/second-minimum-time-to-reach-destination)【每点维护第一、第二到达时间】
- [2812. 找出最安全路径](https://leetcode.cn/problems/find-the-safest-path-in-a-grid)【多源 BFS 预处理危险距离；二分阈值 + 可达性判定】

### 5. 计数与路径构造：不是“走到终点”就结束

这类题的难点是把“距离”之外的约束编入状态，或按照题目规则输出一条具体路径。

- [332. 重新安排行程](https://leetcode.cn/problems/reconstruct-itinerary)【欧拉路径；Hierholzer 算法 + 字典序选择】
- [1786. 从第一个节点出发到最后一个节点的受限路径数](https://leetcode.cn/problems/number-of-restricted-paths-from-first-to-last-node)【先 Dijkstra 求到终点距离，再按距离递减做记忆化 DP】
- [2065. 最大化一张图中的路径价值](https://leetcode.cn/problems/maximum-path-quality-of-a-graph)【受时间限制的 DFS；访问计数决定节点价值是否重复计算】

### 6. 路径字符串与移动轨迹：栈与坐标模拟

题面中的“路径”若是文件系统字符串或移动指令，通常不需要图搜索：把路径分段、维护栈或坐标集合即可。

- [71. 简化路径](https://leetcode.cn/problems/simplify-path)【栈模拟；忽略 `.`，`..` 弹栈，普通目录入栈】
- [1496. 判断路径是否相交](https://leetcode.cn/problems/path-crossing)【坐标模拟 + 哈希集合；每一步后检查是否已访问】

> **练习顺序建议**：先做 62 → 64 → 112 → 113 → 200 → 909，建立“DP、DFS、BFS”的路径直觉；再做 127、1293、743、1631、1976；最后挑战 847、1786、332、2065 等需要复合状态或构造的题目。


## 工程小技巧 (Engineering Tips)

### 1. 数组快速清零
在 C++ 中，局部变量（栈上分配）默认包含随机垃圾值。使用以下语法可实现极致高效的清零：
```cpp
int arr[9][9] = {0}; // 显式初始化第一个元素为 0，其余元素自动补零
int arr[9][9] = {};  // C++11 简写，全员清零
```
- **注意**：如果不加 `{0}`，数组内容将不可预测，这是初学者最常见的 Bug 来源。
- **性能**：编译器通常会将其优化为内联的 `memset` 或专门的 CPU 指令，比手动 `for` 循环快得多。

### 2. 字符串单词拆分 (stringstream)
在处理以空格分隔的字符串（如“hello world”）时，手动控制指针解析既繁琐又容易出错（需考虑首尾空格、多空格等情况）。
```cpp
#include <sstream>
string s = "  hello   world  ";
stringstream ss(s);
string word;
while (ss >> word) {
    // 自动跳过所有空格，依次提取出 "hello" 和 "world"
}
```
- **优势**：逻辑极简，代码鲁棒性极强，是面试中处理字符串解析的首选方案。

### 3. 字符分类与大小写转换

| 函数名 | 检查内容 | 对应描述 |
| --- | --- | --- |
| `isdigit(c)` | 是否为数字（0–9） | 数字字符 |
| `isalpha(c)` | 是否为字母（a-z、A-Z） | 纯字符/字母 |
| `isalnum(c)` | 是否为字母或数字 | 字母数字混合 |
| `tolower(c)` | 转换为小写 | 小写转换 |
| `toupper(c)` | 转换为大写 | 大写转换 |

### 4. 搜索策略选择指南
在算法竞赛或面试中，面对复杂的搜索问题，快速判断技术路线是节省时间的关键：
- **求最短路径 / 最小步数**：首选 **BFS**（利用其层级遍历的天然最短性）。
- **求所有方案 / 排列组合**：首选 **DFS + 回溯**（全量枚举状态空间）。
- **在单调 / 有序空间找最优值**：首选 **二分答案**（将最优化问题转化为判定问题 `check(mid)`）。
- **状态空间爆炸**：优先考虑 **双向 BFS**（极大减小搜索树规模）或 **记忆化搜索**（DFS + Memo，避免重复计算）。



## 参考
- [leetcode](https://leetcode.cn/)
- [灵茶山艾府](https://leetcode.cn/u/endlesscheng/)
- [宫水三叶](https://github.com/SharingSource/LogicStack-LeetCode)
- [代码随想录](https://github.com/youngyangyang04/leetcode-master)
- https://oi-wiki.org/
- https://zerotrac.github.io/leetcode_problem_rating/
- https://cp-algorithms.com/
- https://leetcode.cn/circle/discuss/tXLS3i/
- https://leetcode.Studyplan/selected-coding-interview/
