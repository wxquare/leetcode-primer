# 按主题分类的题目

[完整 LeetCode 题单](leetcode-problems.md) / [复盘方法](../review-method.md) / [题目笔记模板](../problem-note-template.md)

## 基础算法

| Problem | Difficulty | Pattern | Key idea | Source |
| --- | --- | --- | --- | --- |
| 11. 盛最多水的容器 | Medium | 双指针 | 移动短板；短板不动无法得到更优解 | [11_container_with_most_water.cc](../../leetcode/基础算法/11_container_with_most_water.cc) |
| 26. 删除有序数组中的重复项 | Easy | 双指针 | 同向快慢指针；读指针扫描，写指针维护去重结果的尾部 | [26_remove_duplicates_from_sorted_array.cc](../../leetcode/基础算法/26_remove_duplicates_from_sorted_array.cc) |
| 42. 接雨水 | Hard | 双指针 | 处理较低边界；其蓄水上界已被确定 | [42_trapping_rain_water.cc](../../leetcode/基础算法/模拟/42_trapping_rain_water.cc) |
| 45. 跳跃游戏 II | Medium | 有序集合 | 维护当前层可达边界与下一层最远位置，维护当前cur_max_dis,全局 max_dis | [45_jump_game_ii.cc](../../leetcode/动态规划/45_jump_game_ii.cc) |
| 50. x 的 n 次幂 | Medium | 快速幂 | 模式：快速幂；将大指数拆分为一半计算，实现 $O(\log n)$ | [50_pow_x_n.cc](../../leetcode/基础算法/模拟/50_pow_x_n.cc) |
| 55. 跳跃游戏 | Medium | 贪心 | 维护最远可达位置 | [55_jump_game.cc](../../leetcode/基础算法/55_jump_game.cc) |
| 66. 加一 | Easy | 模拟 | 模拟进位；从最低位向前传播进位 | [66_plus_one.cc](../../leetcode/数学/66_plus_one.cc) |
| 135. 分发糖果 | Hard | 贪心 | 左右各扫一次，分别满足单侧局部约束 | [135_candy.cc](../../leetcode/搜索/135_candy.cc) |
| 179. 最大数 | Medium | 贪心 | 自定义逆序排序 + 贪心 | [179_largest_number.cc](../../leetcode/数学/179_largest_number.cc) |
| 402. 移掉 K 位数字 | Medium | 单调栈 | 最小字典序数值；在删除次数允许时，弹出大于当前数字的栈顶 | [402_remove_k_digits.cc](../../leetcode/数学/402_remove_k_digits.cc) |
| 438. 找到字符串中所有字母异位词 | Medium | 滑动窗口 | 固定窗口 + 字符频次；窗口长度等于模式串长度 | [438_find_all_anagrams_in_a_string.cc](../../leetcode/基础算法/模拟/438_find_all_anagrams_in_a_string.cc) |
| 455. 分发饼干 | Easy | 贪心 | 排序 + 双指针；优先用最小可满足的饼干匹配当前胃口 | [455_find_content_children.cc](../../leetcode/基础算法/455_find_content_children.cc) |
| 466. 统计重复个数 | Hard | 循环检测 | 实现采用循环检测，详见本地源码。 | [466_get_max_repetitions.cc](../../leetcode/基础算法/模拟/466_get_max_repetitions.cc) |
| 2560. 打家劫舍 IV | Medium | 二分答案 | 固定能力值后尽早选择不相邻房屋 | [2560_min_capability.cc](../../leetcode/基础算法/模拟/2560_min_capability.cc) |

## 数据结构

| Problem | Difficulty | Pattern | Key idea | Source |
| --- | --- | --- | --- | --- |
| 1. 两数之和 | Easy | 哈希查找 | 哈希表记录已遍历元素 | [1_two_sum.cc](../../leetcode/数据结构/1_two_sum.cc) |
| 3. 无重复字符的最长子串 | Medium | 滑动窗口 | 滑动窗口 + 哈希表 | [3_longest_substring_without_repeating_characters.cc](../../leetcode/基础算法/模拟/3_longest_substring_without_repeating_characters.cc) |
| 5. 最长回文子串 | Medium | 马拉车算法 | 中心扩展或 Manacher | [5_longest_palindromic_substring.cc](../../leetcode/数学/5_longest_palindromic_substring.cc) |
| 9. 回文数 | Easy | 数学 | 反转后一半数字，避免整数溢出 | [9_palindrome_number.cc](../../leetcode/数学/9_palindrome_number.cc) |
| 19. 删除链表的倒数第 N 个结点 | Medium | 双指针 | 模式：快慢指针；核心：利用 $n$ 步位移差定位倒数第 $n+1$ 个节点（前驱节点） | [19_remove_nth_node_from_end_of_list.cc](../../leetcode/基础算法/模拟/19_remove_nth_node_from_end_of_list.cc) |
| 25. K 个一组翻转链表 | Hard | 链表反转 | 模式：分段翻转；核心：先求长度确定组数，利用“头插法”在 $O(n)$ 时间 $O(1)$ 空间内完成翻转 | [25_reverse_nodes_in_k_group.cc](../../leetcode/基础算法/模拟/25_reverse_nodes_in_k_group.cc) |
| 48. 旋转图像 | Medium | 矩阵操作 | 转置 + 水平翻转 | [48_rotate_image.cc](../../leetcode/基础算法/48_rotate_image.cc) |
| 61. 旋转链表 | Medium | 链表操作 | 成环解环；先连成环再在 $n-(k\%n)$ 处断开 | [61_rotate_list.cc](../../leetcode/基础算法/61_rotate_list.cc) |
| 73. 矩阵置零 | Medium | 矩阵操作 | 首行首列复用为标记位 | [73_set_matrix_zeroes.cc](../../leetcode/基础算法/模拟/73_set_matrix_zeroes.cc) |
| 74. 搜索二维矩阵 | Medium | 二分查找 | 二分查找 | [74_search_a_2_d_matrix.cc](../../leetcode/基础算法/74_search_a_2_d_matrix.cc) |
| 91. 解码方法 | Medium | 动态规划 | 线性 DP；按一位和两位数字的合法性转移 | [91_decode_ways.cc](../../leetcode/动态规划/91_decode_ways.cc) |
| 120. 三角形最小路径和 | Medium | 动态规划 | 二维动态规划 | [120_triangle.cc](../../leetcode/动态规划/120_triangle.cc) |
| 128. 最长连续序列 | Medium | 哈希查找 | 哈希集合；仅从连续段起点扩展 | [128_longest_consecutive_sequence.cc](../../leetcode/基础算法/模拟/128_longest_consecutive_sequence.cc) |
| 136. 只出现一次的数字 | Easy | 位运算 | 异或抵消 | [136_single_number.cc](../../leetcode/数学/136_single_number.cc) |
| 137. 只出现一次的数字 II | Medium | 位运算 | 位运算；逐位统计出现次数并对 3 取模恢复唯一数字 | [137_single_number_ii.cc](../../leetcode/数学/137_single_number_ii.cc) |
| 138. 随机链表的复制 | Medium | 链表操作 | 模式：原地克隆；核心：`A->A'->B->B'` 插入法，实现 $O(1)$ 空间拷贝随机指针 | [138_copy_list_with_random_pointer.cc](../../leetcode/基础算法/模拟/138_copy_list_with_random_pointer.cc) |
| 155. 最小栈 | Medium | 栈 | 模式：双栈/辅助栈；核心：同步维护一个“当前的最小值”栈 | [155_min_stack.cc](../../leetcode/数据结构/155_min_stack.cc) |
| 167. 两数之和 II - 输入有序数组 | Medium | 双指针 | 有序数组对撞双指针 | [167_two_sum_ii_input_array_is_sorted.cc](../../leetcode/数学/167_two_sum_ii_input_array_is_sorted.cc) |
| 173. 二叉搜索树迭代器 | Medium | 栈 | 模式：栈模拟中序遍历；核心：利用显式栈实现懒加载，确保 $O(h)$ 空间与均摊 $O(1)$ 时间 | [173_binary_search_tree_iterator.cc](../../leetcode/图论/173_binary_search_tree_iterator.cc) |
| 217. 存在重复元素 | Easy | 哈希查找 | 哈希集合判重 | [217_contains_duplicate.cc](../../leetcode/基础算法/模拟/217_contains_duplicate.cc) |
| 218. 天际线问题 | Hard | 线段树 | 离散化建筑边界后维护各段最大高度。 | [218_the_skyline_problem.cc](../../leetcode/数据结构/218_the_skyline_problem.cc) |
| 219. 存在重复元素 II | Easy | 滑动窗口 | 固定窗口哈希 | [219_contains_duplicate_ii.cc](../../leetcode/数据结构/219_contains_duplicate_ii.cc) |
| 220. 存在重复元素 III | Medium | 有序集合 | 滑动窗口 + 有序集合 | [220_contains_duplicate_iii.cc](../../leetcode/基础算法/模拟/220_contains_duplicate_iii.cc) |
| 232. 用栈实现队列 | Easy | 栈 | 模式：双栈翻转；核心：利用入栈和出栈两个容器实现 FIFO | [232_implement_queue_using_stacks.cc](../../leetcode/数据结构/232_implement_queue_using_stacks.cc) |
| 236. 二叉树的最近公共祖先 | Medium | 树深度优先搜索 | 模式：DFS 递归；核心：利用返回值上传状态（自底向上聚合），实现无副作用的纯函数设计 | [236_lowest_common_ancestor_of_a_binary_tree.cc](../../leetcode/图论/236_lowest_common_ancestor_of_a_binary_tree.cc) |
| 238. 除了自身以外数组的乘积 | Medium | 前后缀 | 前缀积 + 后缀积；两次扫描避免使用除法 | [238_product_of_array_except_self.cc](../../leetcode/基础算法/238_product_of_array_except_self.cc) |
| 239. 滑动窗口最大值 | Hard | 单调队列 | 双端单调递减队列 | [239_sliding_window_maximum.cc](../../leetcode/数据结构/239_sliding_window_maximum.cc) |
| 260. 只出现一次的数字 III | Medium | 位运算 | 整体异或后按 lowbit 分组 | [260_single_number_iii.cc](../../leetcode/数学/260_single_number_iii.cc) |
| 283. 移动零 | Easy | 双指针 | 快慢指针原地压缩 | [283_move_zeroes.cc](../../leetcode/基础算法/模拟/283_move_zeroes.cc) |
| 287. 寻找重复数 | Medium | 快慢指针 | 快慢指针找环 | [287_find_the_duplicate_number.cc](../../leetcode/数学/287_find_the_duplicate_number.cc) |
| 289. 生命游戏 | Medium | 矩阵操作 | 位编码同时保存旧状态和新状态 | [289_game_of_life.cc](../../leetcode/基础算法/模拟/289_game_of_life.cc) |
| 290. 单词规律 | Easy | 哈希查找 | 单词与字符双向映射 | [290_word_pattern.cc](../../leetcode/数据结构/290_word_pattern.cc) |
| 295. 数据流的中位数 | Hard | 堆 | 最大堆 + 最小堆 | [295_find_median_from_data_stream.cc](../../leetcode/数据结构/295_find_median_from_data_stream.cc) |
| 300. 最长递增子序列 | Medium | 动态规划 | 二分 + 贪心 | [300_longest_increasing_subsequence.cc](../../leetcode/动态规划/300_longest_increasing_subsequence.cc) |
| 307. 区域和检索 - 数组可修改 | Medium | 线段树 | 线段树维护区间和，支持单点更新和区间查询 | [307_range_sum_query_mutable.cc](../../leetcode/图论/307_range_sum_query_mutable.cc) |
| 327. 区间和的个数 | Hard | 有序集合 | 维护有序前缀和，统计目标区间内的历史前缀。 | [327_count_of_range_sum.cc](../../leetcode/数据结构/327_count_of_range_sum.cc) |
| 380. O(1) 时间插入、删除和获取随机元素 | Medium | 哈希表与数组 | 模式：哈希表 + 动态数组；利用数组末尾交换实现 $O(1)$ 删除 | [380_insert_delete_get_random_o_1.cc](../../leetcode/数据结构/380_insert_delete_get_random_o_1.cc) |
| 382. 链表随机节点 | Medium | 水塘抽样 | 模式：水塘抽样；核心：从未知长度流中等概率采样，确保概率为 $1/i$ | [382_linked_list_random_node.cc](../../leetcode/基础算法/模拟/382_linked_list_random_node.cc) |
| 387. 字符串中的第一个唯一字符 | Easy | 哈希查找 | 频次统计 + 二次遍历 | [387_first_unique_character_in_a_string.cc](../../leetcode/数据结构/387_first_unique_character_in_a_string.cc) |
| 409. 最长回文串 | Easy | 贪心 | 贪心使用成对字符 | [409_longest_palindrome.cc](../../leetcode/数学/409_longest_palindrome.cc) |
| 415. 字符串相加 | Easy | 模拟 | 模拟竖式加法 | [415_add_strings.cc](../../leetcode/基础算法/模拟/415_add_strings.cc) |
| 421. 数组中两个数的最大异或值 | Hard | 位运算 | 模式：0-1 Trie；利用二进制前缀树实现 $O(n \log C)$ 的异或极值查找 | [421_find_maximum_xor.cc](../../leetcode/数学/421_find_maximum_xor.cc) |
| 448. 找到所有数组中消失的数字 | Easy | 原地标记 | 原地负号标记 | [448_find_disappeared_numbers.cc](../../leetcode/数学/448_find_disappeared_numbers.cc) |
| 452. 用最少数量的箭引爆气球 | Medium | 贪心 | 模式：区间交集；核心：按终点排序，贪心选择重叠区域的边缘 | [452_find_min_arrow_shots.cc](../../leetcode/基础算法/452_find_min_arrow_shots.cc) |
| 454. 四数相加 II | Medium | 哈希查找 | 两两配对和 + 哈希表 | [454_four_sum_count.cc](../../leetcode/数据结构/454_four_sum_count.cc) |
| 480. 滑动窗口中位数 | Hard | 堆 | 双堆 + 延迟删除；维护窗口两半元素数量平衡 | [480_median_sliding_window.cc](../../leetcode/数据结构/480_median_sliding_window.cc) |
| 560. 和为 K 的子数组 | Medium | 前缀和 | 前缀和 + 哈希表 | [560_subarray_sum.cc](../../leetcode/基础算法/560_subarray_sum.cc) |
| 689. 三个无重叠子数组的最大和 | Hard | 动态规划 | 动态规划 | [689_do_subarrays.cc](../../leetcode/基础算法/689_do_subarrays.cc) |
| 729. 我的日程安排表 I | Medium | 有序集合 | 在有序区间中检查相邻预订是否重叠。 | [729_my_calendar.cc](../../leetcode/基础算法/模拟/729_my_calendar.cc) |
| 768. 最多能完成排序的块 II | Hard | 单调栈 | 模式：单调栈维护块极值；核心：栈中每个元素代表一个“块”的最大值，重叠则合并 | [768_max_chunks_to_sorted.cc](../../leetcode/动态规划/768_max_chunks_to_sorted.cc) |
| 769. 最多能完成排序的块 | Medium | 前缀最大值 | 模式：贪心模拟；核心：维护当前最大值，若 `max == index` 则可分块 | [769_max_chunks_to_sorted.cc](../../leetcode/基础算法/769_max_chunks_to_sorted.cc) |
| 2407. 最长递增子序列 II | Hard | 线段树 | 线段树优化 | [2407_pushdown.cc](../../leetcode/动态规划/2407_pushdown.cc) |
| 2707. 字符串中的额外字符 | Medium | 动态规划 | 动态规划 | [2707_min_extra_char.cc](../../leetcode/动态规划/2707_min_extra_char.cc) |
| 2713. 矩阵中严格递增的单元格数 | Hard | 动态规划 | 动态规划 | [2713_max_increasing_cells.cc](../../leetcode/基础算法/模拟/2713_max_increasing_cells.cc) |
| 2747. 统计没有收到请求的服务器数目 | Medium | 滑动窗口 | 离线排序 + 滑动窗口；按查询时间维护活跃服务器 | [2747_count_servers.cc](../../leetcode/数据结构/2747_count_servers.cc) |
| 2812. 找出最安全路径 | Hard | 二分答案 | 网格多源 BFS | [2812_maximum_safeness_factor.cc](../../leetcode/搜索/2812_maximum_safeness_factor.cc) |
| 2916. 子数组不同元素数目的平方和 II | Hard | 线段树 | 线段树 | [2916_subarray_distinct_elements_sum_of_squares.cc](../../leetcode/数据结构/2916_subarray_distinct_elements_sum_of_squares.cc) |

## 数学

| Problem | Difficulty | Pattern | Key idea | Source |
| --- | --- | --- | --- | --- |
| 149. 直线上最多的点数 | Hard | 哈希查找 | 斜率哈希；对每个起点规范化斜率并统计同一直线点数 | [149_max_points_on_a_line.cc](../../leetcode/基础算法/模拟/149_max_points_on_a_line.cc) |
| 172. 阶乘后的零 | Medium | 数论 | 数论；统计因子 5 的总数量 | [172_factorial_trailing_zeroes.cc](../../leetcode/数学/172_factorial_trailing_zeroes.cc) |
| 190. 颠倒二进制位 | Easy | 位运算 | 逐位构造；依次取最低位并左移累积结果 | [190_reverse_bits.cc](../../leetcode/基础算法/模拟/190_reverse_bits.cc) |
| 191. 位1的个数 | Easy | 位运算 | __builtin_popcount 手动实现 | [191_number_of_1_bits.cc](../../leetcode/数学/191_number_of_1_bits.cc) |
| 231. 判断一个数是否是 2 的幂 | Easy | 位运算 | 有且仅有一个置位位1， n & (n - 1)  消除最低位1 | [231_power_of_two.cc](../../leetcode/数学/231_power_of_two.cc) |
| 258. 各位相加 | Easy | 数学 | 利用数根的模 9 规律处理非零数字。 | [258_add_digits.cc](../../leetcode/数学/258_add_digits.cc) |
| 398. 随机数索引 | Medium | 水塘抽样 | 实现采用水塘抽样，详见本地源码。 | [398_random_pick_index.cc](../../leetcode/数据结构/398_random_pick_index.cc) |
| 400. 第 N 位数字 | Medium | 数学 | 实现采用数学，详见本地源码。 | [400_nth_digit.cc](../../leetcode/数学/400_nth_digit.cc) |
| 2579. 统计染色单元格总数 | Medium | 数学 | 把每层新增单元格化为等差增长公式。 | [2579_beautiful_subsets.cc](../../leetcode/动态规划/2579_beautiful_subsets.cc) |

## 搜索

| Problem | Difficulty | Pattern | Key idea | Source |
| --- | --- | --- | --- | --- |
| 4. 寻找两个正序数组的中位数 | Hard | 归并 | 二分划分；寻找切割点平衡左右数量 | [4_median_of_two_sorted_arrays.cc](../../leetcode/数据结构/4_median_of_two_sorted_arrays.cc) |
| 33. 搜索旋转排序数组 | Medium | 二分查找 | 二分查找；每轮至少一侧区间保持有序 | [33_search_in_rotated_sorted_array.cc](../../leetcode/基础算法/33_search_in_rotated_sorted_array.cc) |
| 69. x 的平方根 | Easy | 二分查找 | 二分答案；比较 `mid * mid` 与目标值时避免溢出 | [69_sqrt_x.cc](../../leetcode/数学/69_sqrt_x.cc) |
| 81. 搜索旋转排序数组 II | Medium | 二分查找 | 二分查找；相等边界无法判断时收缩边界 | [81_search_in_rotated_sorted_array_ii.cc](../../leetcode/基础算法/81_search_in_rotated_sorted_array_ii.cc) |
| 437. 路径总和 III | Medium | 前缀和 | 实现采用前缀和，详见本地源码。 | [437_path_sum_iii.cc](../../leetcode/图论/437_path_sum_iii.cc) |
| 494. 目标和 | Medium | 递归 | 递归为每个数字枚举正负号，统计和为 `target` 的方案数 | [494_target_sum.cc](../../leetcode/动态规划/494_target_sum.cc) |
| 526. 优美的排列 | Medium | 深度优先搜索 / 回溯 | 实现采用深度优先搜索 / 回溯，详见本地源码。 | [526_count_arrangement.cc](../../leetcode/动态规划/526_count_arrangement.cc) |
| 996. 正方形数组的数目 | Hard | 状态压缩 | 预处理/重复数字全排列 | [996_num_squareful_perms.cc](../../leetcode/动态规划/996_num_squareful_perms.cc) |
| 2597. 美丽子集的数目 | Medium | 深度优先搜索 / 回溯 | 排序后递归选或不选；仅当不存在 `nums[i] - k` 时选择当前数 | [2597_beautiful_subsets.cc](../../leetcode/搜索/2597_beautiful_subsets.cc) |

## 动态规划

| Problem | Difficulty | Pattern | Key idea | Source |
| --- | --- | --- | --- | --- |
| 10. 正则表达式匹配 | Hard | 递归 | 递归逐字符匹配；`*` 分支尝试跳过或消费当前字符 | [10_regular_expression_matching.cc](../../leetcode/基础算法/模拟/10_regular_expression_matching.cc) |
| 198. 打家劫舍 | Medium | 动态规划 | DP[i][2] | [198_house_robber.cc](../../leetcode/动态规划/198_house_robber.cc) |
| 213. 打家劫舍 II | Medium | 动态规划 | 拆成首尾互斥的两段线性打家劫舍，取较大值。 | [213_house_robber_ii.cc](../../leetcode/动态规划/213_house_robber_ii.cc) |
| 233. 数字 1 的个数 | Hard | 数位动态规划 | 数位 DFS 记录当前位置、数字 1 的累计数量和上界约束。 | [233_number_of_digit_one.cc](../../leetcode/动态规划/233_number_of_digit_one.cc) |
| 337. 打家劫舍 III | Medium | 树形动态规划 | 二叉树父子节点不同同时被偷 | [337_house_robber_iii.cc](../../leetcode/动态规划/337_house_robber_iii.cc) |
| 509. 斐波那契数 | Easy | 动态规划 | 实现采用动态规划，详见本地源码。 | [509_fibonacci_number.cc](../../leetcode/数学/509_fibonacci_number.cc) |
| 600. 二进制不含连续1的非负整数 | Hard | 数位动态规划 | 数位DP | [600_decimal_to_binary.cc](../../leetcode/动态规划/600_decimal_to_binary.cc) |
| 746. 使用最小花费爬楼梯 | Easy | 动态规划 | 线性 DP；到达当前台阶的最小花费只依赖前两阶 | [746_min_cost_climbing_stairs.cc](../../leetcode/动态规划/746_min_cost_climbing_stairs.cc) |
| 877. 石子游戏 | Medium | 区间动态规划 | 实现采用区间动态规划，详见本地源码。 | [877_stone_game.cc](../../leetcode/动态规划/877_stone_game.cc) |
| 1012. 至少有 1 位重复的数字 | Hard | 数位动态规划 | 数位 DP 用掩码记录已使用数字和上界约束。 | [1012_num_dup_digits_at_most_n.cc](../../leetcode/动态规划/1012_num_dup_digits_at_most_n.cc) |
| 1306. 跳跃游戏 III | Medium | 广度优先搜索 | 实现采用广度优先搜索，详见本地源码。 | [1306_can_reach.cc](../../leetcode/搜索/1306_can_reach.cc) |
| 1345. 跳跃游戏 IV | Hard | 广度优先搜索 | 实现采用广度优先搜索，详见本地源码。 | [1345_min_jumps.cc](../../leetcode/数据结构/1345_min_jumps.cc) |
| 2646. 最小化旅行的价格总和 | Hard | 树形动态规划 | 实现采用树形动态规划，详见本地源码。 | [2646_minimum_total_price.cc](../../leetcode/搜索/2646_minimum_total_price.cc) |
| 2742. 给墙壁刷油漆 | Hard | 动态规划 | 实现采用动态规划，详见本地源码。 | [2742_paint_walls.cc](../../leetcode/动态规划/2742_paint_walls.cc) |

## 图论

| Problem | Difficulty | Pattern | Key idea | Source |
| --- | --- | --- | --- | --- |
| 210. 课程表 II | Medium | 拓扑排序 | 模式：BFS 拓扑序列；核心：记录入度为 0 的节点弹出顺序 | [210_course_schedule_ii.cc](../../leetcode/图论/210_course_schedule_ii.cc) |
| 310. 最小高度树 | Medium | 拓扑排序 | 拓扑剥叶；不断删除叶子节点，最后剩余中心即最小高度树根 | [310_minimum_height_trees.cc](../../leetcode/图论/310_minimum_height_trees.cc) |
| 547. 省份数量 | Medium | 并查集 | 并查集合并相邻城市，最后统计连通分量。 | [547_friend_circles.cc](../../leetcode/图论/547_friend_circles.cc) |
| 684. 冗余连接 | Medium | 并查集 | 首条连接同一集合两端点的边即成环边。 | [684_redundant_connection.cc](../../leetcode/图论/684_redundant_connection.cc) |
| 743. 网络延迟时间 | Medium | 最短路 | Dijkstra 模板 | [743_network_delay_time.cc](../../leetcode/数据结构/743_network_delay_time.cc) |
| 1192. 查找集群内的关键连接 | Hard | Tarjan | 实现采用Tarjan，详见本地源码。 | [1192_critical_connections.cc](../../leetcode/搜索/1192_critical_connections.cc) |
| 1489. 找到最小生成树里的关键边和伪关键边 | Hard | 并查集 | 实现采用并查集，详见本地源码。 | [1489_find.cc](../../leetcode/图论/1489_find.cc) |
| 2045. 到达目的地的第二短时间 | Hard | 最短路 | 实现采用最短路，详见本地源码。 | [2045_second_minimum.cc](../../leetcode/搜索/2045_second_minimum.cc) |
| 2127. 参加会议的最多员工数 | Hard | 拓扑排序 | 基环树内向树，基环森林 | [2127_maximum_invitations.cc](../../leetcode/数据结构/2127_maximum_invitations.cc) |
| 2360. 图中的最长环 | Hard | 拓扑排序 | 拓扑排序 + 环的处理 或者 时间戳DFS | [2360_longest_cycle.cc](../../leetcode/数据结构/2360_longest_cycle.cc) |
| 2603. 收集树中金币 | Hard | 拓扑排序 | 模式：剥层法；通过度数反复删除叶子节点 | [2603_collect_the_coins.cc](../../leetcode/数据结构/2603_collect_the_coins.cc) |

## 专题：路径问题

| Problem | Difficulty | Pattern | Key idea | Source |
| --- | --- | --- | --- | --- |
| 126. 单词接龙 II | Hard | 广度优先搜索 | 所有最短变换序列；BFS 分层记录前驱关系，再 DFS 回溯恢复路径 | [126_word_ladder_ii.cc](../../leetcode/搜索/126_word_ladder_ii.cc) |
| 1368. 使网格图至少有一条有效路径的最小代价 | Hard | 0-1 广度优先搜索 | 0-1 BFS；沿箭头走的边权为 0 | [1368_min_cost.cc](../../leetcode/数据结构/1368_min_cost.cc) |

## 其它来源

| Problem | Difficulty | Pattern | Key idea | Source |
| --- | --- | --- | --- | --- |
| Offer 22. 层序遍历 | Easy | 广度优先搜索 | 按 FIFO 顺序入队子结点，并逐层消费队列。 | [offer22_print_tree_from_top_to_bottom.cc](../../剑指offer/src/offer22_print_tree_from_top_to_bottom.cc) |
