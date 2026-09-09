# 02 核心模式

[路线入口](00-start-here.md) / [上一阶段](01-foundations.md) / [复习方法](../review-method.md)

核心模式阶段重点训练“题目识别”。每一节先写下识别信号，再做两到四题；如果题目做出来但无法解释模式选择，仍按 `review` 处理，不急着标记为 `mastered`。

<a id="two-pointers"></a>

## 双指针

识别信号：输入是有序数组、链表距离、原地压缩，或需要用左右端点共同维护不变量。

代表题：

- [11. 盛最多水的容器](../../leetcode/基础算法/11_container_with_most_water.cc)
- [27. 移除元素](../../leetcode/模拟/27_remove_element.cc)
- [167. 两数之和 II](../../leetcode/数学/167_two_sum_ii_input_array_is_sorted.cc)
- [283. 移动零](../../leetcode/模拟/283_move_zeroes.cc)

<a id="sliding-windows"></a>

## 滑动窗口

识别信号：题目要求连续子数组或子串，并且窗口扩张、收缩后能单调维护可行性。

代表题：

- [3. 无重复字符的最长子串](../../leetcode/模拟/3_longest_substring_without_repeating_characters.cc)
- [239. 滑动窗口最大值](../../leetcode/数据结构运用/239_sliding_window_maximum.cc)
- [424. 替换后的最长重复字符](../../leetcode/模拟/424_character_replacement.cc)
- [713. 乘积小于 K 的子数组](../../leetcode/基础算法/713_num_subarray_product_less_than_k.cc)

<a id="stacks"></a>

## 栈

识别信号：需要处理最近未匹配元素、嵌套结构、单调边界，或后进先出的状态恢复。

代表题：

- [155. 最小栈](../../leetcode/数据结构运用/155_min_stack.cc)
- [232. 用栈实现队列](../../leetcode/数据结构运用/232_implement_queue_using_stacks.cc)
- [456. 132 模式](../../leetcode/模拟/456_find132pattern.cc)
- [496. 下一个更大元素 I](../../leetcode/数据结构运用/496_next_greater_element.cc)

<a id="queues"></a>

## 队列

识别信号：状态按层推进、需要先进先出处理，或需要用单调队列保留窗口候选最值。

代表题：

- [Offer 5. 用两个栈实现队列](../../剑指offer/src/offer5_queue_with_two_stacks.cc)
- [Offer 22. 从上往下打印二叉树](../../剑指offer/src/offer22_print_tree_from_top_to_bottom.cc)
- [Offer 64. 滑动窗口的最大值](../../剑指offer/src/offer64_sliding_window_maximum.cc)
- [单调队列模板](../../其它常见的题目/src/monotonic_structures.cc)

<a id="bfs"></a>

## 广度优先搜索

识别信号：要求最短步数、层序遍历、从多个起点扩散，或状态转移边权相同。

代表题：

- [Offer 22. 从上往下打印二叉树](../../剑指offer/src/offer22_print_tree_from_top_to_bottom.cc)
- [1306. 跳跃游戏 III](../../leetcode/搜索（非图）/1306_can_reach.cc)
- [1345. 跳跃游戏 IV](../../leetcode/数据结构运用/1345_min_jumps.cc)
- [2045. 到达目的地的第二短时间](../../leetcode/搜索（非图）/2045_second_minimum.cc)

<a id="dfs--backtracking"></a>

## 深度优先搜索 / 回溯

识别信号：需要枚举选择、撤销选择、验证路径，或树和图的深度优先遍历更自然。

代表题：

- [51. N 皇后](../../leetcode/搜索（非图）/51_n_queens.cc)
- [131. 分割回文串](../../leetcode/搜索（非图）/131_palindrome_partitioning.cc)
- [473. 火柴拼正方形](../../leetcode/搜索（非图）/473_makesquare.cc)
- [698. 划分为 k 个相等的子集](../../leetcode/搜索（非图）/698_can_partition_ksubsets.cc)

<a id="greedy-methods"></a>

## 贪心方法

识别信号：局部选择能通过排序、交换论证或边界推进证明不损失全局最优。

代表题：

- [45. 跳跃游戏 II](../../leetcode/动态规划/45_jump_game_ii.cc)
- [55. 跳跃游戏](../../leetcode/基础算法/55_jump_game.cc)
- [402. 移掉 K 位数字](../../leetcode/数学/402_remove_k_digits.cc)
- [452. 用最少数量的箭引爆气球](../../leetcode/基础算法/452_find_min_arrow_shots.cc)

<a id="prefix-sums"></a>

## 前缀和

识别信号：需要频繁求区间和、子数组计数，或把区间问题转化为两个前缀状态之差。

代表题：

- [238. 除自身以外数组的乘积](../../leetcode/基础算法/238_product_of_array_except_self.cc)
- [327. 区间和的个数](../../leetcode/数据结构运用/327_count_of_range_sum.cc)
- [560. 和为 K 的子数组](../../leetcode/基础算法/560_subarray_sum.cc)
- [724. 寻找数组的中心下标](../../leetcode/模拟/724_pivot_index.cc)

<a id="basic-dynamic-programming"></a>

## 基础动态规划

识别信号：当前答案依赖较小子问题，且状态能描述“到当前位置、使用前若干元素、或选择/不选择”的结果。

代表题：

- [198. 打家劫舍](../../leetcode/动态规划/198_house_robber.cc)
- [213. 打家劫舍 II](../../leetcode/动态规划/213_house_robber_ii.cc)
- [300. 最长递增子序列](../../leetcode/动态规划/300_longest_increasing_subsequence.cc)
- [746. 使用最小花费爬楼梯](../../leetcode/动态规划/746_min_cost_climbing_stairs.cc)
