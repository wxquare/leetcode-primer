# 02 核心模式

[路线入口](00-start-here.md) / [上一阶段](01-foundations.md) / [复习方法](../review-method.md)

核心模式阶段重点训练“题目识别”。每一节先写下识别信号，再做两到四题；如果题目做出来但无法解释模式选择，仍按 `review` 处理，不急着标记为 `mastered`。

<a id="two-pointers"></a>

## 双指针

识别信号：输入是有序数组、链表距离、原地压缩，或需要用左右端点共同维护不变量。

代表题：

- [11. 盛最多水的容器](../../leetcode/src/leetcode11.cc)
- [27. 移除元素](../../leetcode/src/leetcode27.cc)
- [167. 两数之和 II](../../leetcode/src/leetcode167.cc)
- [283. 移动零](../../leetcode/src/leetcode283.cc)

<a id="sliding-windows"></a>

## 滑动窗口

识别信号：题目要求连续子数组或子串，并且窗口扩张、收缩后能单调维护可行性。

代表题：

- [3. 无重复字符的最长子串](../../leetcode/src/leetcode3.cc)
- [239. 滑动窗口最大值](../../leetcode/src/leetcode239.cc)
- [424. 替换后的最长重复字符](../../leetcode/src/leetcode424.cc)
- [713. 乘积小于 K 的子数组](../../leetcode/src/leetcode713.cc)

<a id="stacks"></a>

## 栈

识别信号：需要处理最近未匹配元素、嵌套结构、单调边界，或后进先出的状态恢复。

代表题：

- [155. 最小栈](../../leetcode/src/leetcode155.cc)
- [232. 用栈实现队列](../../leetcode/src/leetcode232.cc)
- [456. 132 模式](../../leetcode/src/leetcode456.cc)
- [496. 下一个更大元素 I](../../leetcode/src/leetcode496.cc)

<a id="queues"></a>

## 队列

识别信号：状态按层推进、需要先进先出处理，或需要用单调队列保留窗口候选最值。

代表题：

- [Offer 5. 用两个栈实现队列](../../剑指offer/src/offer5.cc)
- [Offer 22. 从上往下打印二叉树](../../剑指offer/src/offer22.cc)
- [Offer 64. 滑动窗口的最大值](../../剑指offer/src/offer64.cc)
- [单调队列模板](../../其它常见的题目/src/monotonic_structures.cc)

<a id="bfs"></a>

## 广度优先搜索

识别信号：要求最短步数、层序遍历、从多个起点扩散，或状态转移边权相同。

代表题：

- [Offer 22. 从上往下打印二叉树](../../剑指offer/src/offer22.cc)
- [1306. 跳跃游戏 III](../../leetcode/src/leetcode1306.cc)
- [1345. 跳跃游戏 IV](../../leetcode/src/leetcode1345.cc)
- [2045. 到达目的地的第二短时间](../../leetcode/src/leetcode2045.cc)

<a id="dfs--backtracking"></a>

## 深度优先搜索 / 回溯

识别信号：需要枚举选择、撤销选择、验证路径，或树和图的深度优先遍历更自然。

代表题：

- [51. N 皇后](../../leetcode/搜索（非图）/深度搜索/51.N皇后.cc)
- [131. 分割回文串](../../leetcode/src/leetcode131.cc)
- [473. 火柴拼正方形](../../leetcode/src/leetcode473.cc)
- [698. 划分为 k 个相等的子集](../../leetcode/src/leetcode698.cc)

<a id="greedy-methods"></a>

## 贪心方法

识别信号：局部选择能通过排序、交换论证或边界推进证明不损失全局最优。

代表题：

- [45. 跳跃游戏 II](../../leetcode/src/leetcode45.cc)
- [55. 跳跃游戏](../../leetcode/src/leetcode55.cc)
- [402. 移掉 K 位数字](../../leetcode/src/leetcode402.cc)
- [452. 用最少数量的箭引爆气球](../../leetcode/src/leetcode452.cc)

<a id="prefix-sums"></a>

## 前缀和

识别信号：需要频繁求区间和、子数组计数，或把区间问题转化为两个前缀状态之差。

代表题：

- [238. 除自身以外数组的乘积](../../leetcode/src/leetcode238.cc)
- [327. 区间和的个数](../../leetcode/src/leetcode327.cc)
- [560. 和为 K 的子数组](../../leetcode/src/leetcode560.cc)
- [724. 寻找数组的中心下标](../../leetcode/src/leetcode724.cc)

<a id="basic-dynamic-programming"></a>

## 基础动态规划

识别信号：当前答案依赖较小子问题，且状态能描述“到当前位置、使用前若干元素、或选择/不选择”的结果。

代表题：

- [198. 打家劫舍](../../leetcode/src/leetcode198.cc)
- [213. 打家劫舍 II](../../leetcode/src/leetcode213.cc)
- [300. 最长递增子序列](../../leetcode/src/leetcode300.cc)
- [746. 使用最小花费爬楼梯](../../leetcode/src/leetcode746.cc)
