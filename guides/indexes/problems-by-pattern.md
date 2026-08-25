# 按模式分类的题目

[完整 LeetCode 题单](leetcode-problems.md) / [核心模式](../roadmap/02-core-patterns.md) / [高级专题](../roadmap/03-advanced-topics.md) / [复盘方法](../review-method.md)

## 哈希查找

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 1. 两数之和 | Easy | 哈希查找 | 哈希表记录已遍历元素 | [leetcode1.cc](../../leetcode/src/leetcode1.cc) | `new` |
| 128. 最长连续序列 | Medium | 哈希查找 | 哈希集合；仅从连续段起点扩展 | [leetcode128.cc](../../leetcode/src/leetcode128.cc) | `new` |
| 149. 直线上最多的点数 | Hard | 哈希查找 | 斜率哈希；对每个起点规范化斜率并统计同一直线点数 | [leetcode149.cc](../../leetcode/src/leetcode149.cc) | `new` |
| 217. 存在重复元素 | Easy | 哈希查找 | 哈希集合判重 | [leetcode217.cc](../../leetcode/src/leetcode217.cc) | `new` |
| 290. 单词规律 | Easy | 哈希查找 | 单词与字符双向映射 | [leetcode290.cc](../../leetcode/src/leetcode290.cc) | `new` |
| 387. 字符串中的第一个唯一字符 | Easy | 哈希查找 | 频次统计 + 二次遍历 | [leetcode387.cc](../../leetcode/src/leetcode387.cc) | `new` |
| 454. 四数相加 II | Medium | 哈希查找 | 两两配对和 + 哈希表 | [leetcode454.cc](../../leetcode/src/leetcode454.cc) | `new` |

## 双指针

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 11. 盛最多水的容器 | Medium | 双指针 | 移动短板；短板不动无法得到更优解 | [leetcode11.cc](../../leetcode/src/leetcode11.cc) | `new` |
| 19. 删除链表的倒数第 N 个结点 | Medium | 双指针 | 模式：快慢指针；核心：利用 $n$ 步位移差定位倒数第 $n+1$ 个节点（前驱节点） | [leetcode19.cc](../../leetcode/src/leetcode19.cc) | `new` |
| 26. 删除有序数组中的重复项 | Easy | 双指针 | 同向快慢指针；读指针扫描，写指针维护去重结果的尾部 | [leetcode26.cc](../../leetcode/src/leetcode26.cc) | `new` |
| 27. 移除元素 | Easy | 双指针 | 读指针扫描，写指针覆盖保留元素。 | [leetcode27.cc](../../leetcode/src/leetcode27.cc) | `new` |
| 42. 接雨水 | Hard | 双指针 | 处理较低边界；其蓄水上界已被确定 | [leetcode42.cc](../../leetcode/src/leetcode42.cc) | `new` |
| 167. 两数之和 II - 输入有序数组 | Medium | 双指针 | 有序数组对撞双指针 | [leetcode167.cc](../../leetcode/src/leetcode167.cc) | `new` |
| 283. 移动零 | Easy | 双指针 | 快慢指针原地压缩 | [leetcode283.cc](../../leetcode/src/leetcode283.cc) | `new` |

## 滑动窗口

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 3. 无重复字符的最长子串 | Medium | 滑动窗口 | 滑动窗口 + 哈希表 | [leetcode3.cc](../../leetcode/src/leetcode3.cc) | `new` |
| 219. 存在重复元素 II | Easy | 滑动窗口 | 固定窗口哈希 | [leetcode219.cc](../../leetcode/src/leetcode219.cc) | `new` |
| 438. 找到字符串中所有字母异位词 | Medium | 滑动窗口 | 固定窗口 + 字符频次；窗口长度等于模式串长度 | [leetcode438.cc](../../leetcode/src/leetcode438.cc) | `new` |
| 713. 乘积小于 K 的子数组 | Medium | 滑动窗口 | 乘积合法时扩张，不合法时收缩左边界。 | [leetcode713.cc](../../leetcode/src/leetcode713.cc) | `new` |
| 2747. 统计没有收到请求的服务器数目 | Medium | 滑动窗口 | 离线排序 + 滑动窗口；按查询时间维护活跃服务器 | [leetcode2747.cc](../../leetcode/src/leetcode2747.cc) | `new` |

## 二分查找

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 33. 搜索旋转排序数组 | Medium | 二分查找 | 二分查找；每轮至少一侧区间保持有序 | [leetcode33.cc](../../leetcode/src/leetcode33.cc) | `new` |
| 69. x 的平方根 | Easy | 二分查找 | 二分答案；比较 `mid * mid` 与目标值时避免溢出 | [leetcode69.cc](../../leetcode/src/leetcode69.cc) | `new` |
| 74. 搜索二维矩阵 | Medium | 二分查找 | 二分查找 | [leetcode74.cc](../../leetcode/src/leetcode74.cc) | `new` |
| 81. 搜索旋转排序数组 II | Medium | 二分查找 | 二分查找；相等边界无法判断时收缩边界 | [leetcode81.cc](../../leetcode/src/leetcode81.cc) | `new` |
| 278. 第一个错误的版本 | Easy | 二分查找 | 在失败位置收缩右边界，保留首个 true。 | [leetcode278.cc](../../leetcode/src/leetcode278.cc) | `new` |

## 单调栈

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 402. 移掉 K 位数字 | Medium | 单调栈 | 最小字典序数值；在删除次数允许时，弹出大于当前数字的栈顶 | [leetcode402.cc](../../leetcode/src/leetcode402.cc) | `new` |
| 456. 132 模式 | Medium | 单调栈 | 从右向左维护候选的中间值。 | [leetcode456.cc](../../leetcode/src/leetcode456.cc) | `new` |
| 496. 下一个更大元素 I | Easy | 单调栈 | 弹出较小元素并记录其下一个更大值。 | [leetcode496.cc](../../leetcode/src/leetcode496.cc) | `new` |
| 768. 最多能完成排序的块 II | Hard | 单调栈 | 模式：单调栈维护块极值；核心：栈中每个元素代表一个“块”的最大值，重叠则合并 | [leetcode768.cc](../../leetcode/src/leetcode768.cc) | `new` |
| 901. 股票价格跨度 | Medium | 单调栈 | 合并价格不高于当前值的连续跨度。 | [901. 股票价格跨度.cc](../../leetcode/数据结构运用/单调栈/901. 股票价格跨度.cc) | `new` |

## 深度优先搜索 / 回溯

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 51. N 皇后 | Hard | 深度优先搜索 / 回溯 | 逐行放置皇后，并记录已占用的列和对角线。 | [51.N皇后.cc](../../leetcode/搜索（非图）/深度搜索/51.N皇后.cc) | `new` |
| 131. 分割回文串 | Medium | 深度优先搜索 / 回溯 | 枚举切分位置，只接受回文子串。 | [leetcode131.cc](../../leetcode/src/leetcode131.cc) | `new` |
| 526. 优美的排列 | Medium | 深度优先搜索 / 回溯 | 实现采用深度优先搜索 / 回溯，详见本地源码。 | [leetcode526.cc](../../leetcode/src/leetcode526.cc) | `new` |
| 698. 划分为 k 个相等的子集 | Medium | 深度优先搜索 / 回溯 | 回溯填充目标和桶，并剪去对称选择。 | [leetcode698.cc](../../leetcode/src/leetcode698.cc) | `new` |
| 2597. 美丽子集的数目 | Medium | 深度优先搜索 / 回溯 | 排序后递归选或不选；仅当不存在 `nums[i] - k` 时选择当前数 | [leetcode2597.cc](../../leetcode/src/leetcode2597.cc) | `new` |

## 广度优先搜索

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 126. 单词接龙 II | Hard | 广度优先搜索 | 所有最短变换序列；BFS 分层记录前驱关系，再 DFS 回溯恢复路径 | [leetcode126.cc](../../leetcode/src/leetcode126.cc) | `new` |
| 1306. 跳跃游戏 III | Medium | 广度优先搜索 | 实现采用广度优先搜索，详见本地源码。 | [leetcode1306.cc](../../leetcode/src/leetcode1306.cc) | `new` |
| 1345. 跳跃游戏 IV | Hard | 广度优先搜索 | 实现采用广度优先搜索，详见本地源码。 | [leetcode1345.cc](../../leetcode/src/leetcode1345.cc) | `new` |

## 动态规划

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 91. 解码方法 | Medium | 动态规划 | 线性 DP；按一位和两位数字的合法性转移 | [leetcode91.cc](../../leetcode/src/leetcode91.cc) | `new` |
| 120. 三角形最小路径和 | Medium | 动态规划 | 二维动态规划 | [leetcode120.cc](../../leetcode/src/leetcode120.cc) | `new` |
| 198. 打家劫舍 | Medium | 动态规划 | DP[i][2] | [leetcode198.cc](../../leetcode/src/leetcode198.cc) | `new` |
| 300. 最长递增子序列 | Medium | 动态规划 | 二分 + 贪心 | [leetcode300.cc](../../leetcode/src/leetcode300.cc) | `new` |
| 494. 目标和 | Medium | 递归 | 递归为每个数字枚举正负号，统计和为 `target` 的方案数 | [leetcode494.cc](../../leetcode/src/leetcode494.cc) | `new` |
| 509. 斐波那契数 | Easy | 动态规划 | 实现采用动态规划，详见本地源码。 | [leetcode509.cc](../../leetcode/src/leetcode509.cc) | `new` |
| 689. 三个无重叠子数组的最大和 | Hard | 动态规划 | 动态规划 | [leetcode689.cc](../../leetcode/src/leetcode689.cc) | `new` |
| 746. 使用最小花费爬楼梯 | Easy | 动态规划 | 线性 DP；到达当前台阶的最小花费只依赖前两阶 | [leetcode746.cc](../../leetcode/src/leetcode746.cc) | `new` |
| 2707. 字符串中的额外字符 | Medium | 动态规划 | 动态规划 | [leetcode2707.cc](../../leetcode/src/leetcode2707.cc) | `new` |
| 2713. 矩阵中严格递增的单元格数 | Hard | 动态规划 | 动态规划 | [leetcode2713.cc](../../leetcode/src/leetcode2713.cc) | `new` |
| 2742. 给墙壁刷油漆 | Hard | 动态规划 | 实现采用动态规划，详见本地源码。 | [leetcode2742.cc](../../leetcode/src/leetcode2742.cc) | `new` |

## 贪心

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 55. 跳跃游戏 | Medium | 贪心 | 维护最远可达位置 | [leetcode55.cc](../../leetcode/src/leetcode55.cc) | `new` |
| 135. 分发糖果 | Hard | 贪心 | 左右各扫一次，分别满足单侧局部约束 | [leetcode135.cc](../../leetcode/src/leetcode135.cc) | `new` |
| 179. 最大数 | Medium | 贪心 | 自定义逆序排序 + 贪心 | [leetcode179.cc](../../leetcode/src/leetcode179.cc) | `new` |
| 409. 最长回文串 | Easy | 贪心 | 贪心使用成对字符 | [leetcode409.cc](../../leetcode/src/leetcode409.cc) | `new` |
| 452. 用最少数量的箭引爆气球 | Medium | 贪心 | 模式：区间交集；核心：按终点排序，贪心选择重叠区域的边缘 | [leetcode452.cc](../../leetcode/src/leetcode452.cc) | `new` |
| 455. 分发饼干 | Easy | 贪心 | 排序 + 双指针；优先用最小可满足的饼干匹配当前胃口 | [leetcode455.cc](../../leetcode/src/leetcode455.cc) | `new` |

## 并查集

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 547. 省份数量 | Medium | 并查集 | 并查集合并相邻城市，最后统计连通分量。 | [leetcode547.cc](../../leetcode/src/leetcode547.cc) | `new` |
| 684. 冗余连接 | Medium | 并查集 | 首条连接同一集合两端点的边即成环边。 | [684. 冗余连接.cc](../../leetcode/数据结构运用/并查集/684. 冗余连接.cc) | `new` |
| 1489. 找到最小生成树里的关键边和伪关键边 | Hard | 并查集 | 实现采用并查集，详见本地源码。 | [leetcode1489.cc](../../leetcode/src/leetcode1489.cc) | `new` |
| 1584. 连接所有点的最小费用 | Medium | 并查集 | 按边权排序，只加入连接不同分量的边。 | [leetcode1584.cc](../../leetcode/src/leetcode1584.cc) | `new` |

## 最短路

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 743. 网络延迟时间 | Medium | 最短路 | Dijkstra 模板 | [leetcode743.cc](../../leetcode/src/leetcode743.cc) | `new` |
| 1334. 阈值距离内邻居最少的城市 | Medium | 最短路 | Floyd 全源最短路支持每个城市的阈值计数。 | [1334. 阈值距离内邻居最少的城市.cc](../../leetcode/图论/最短路/1334. 阈值距离内邻居最少的城市.cc) | `new` |
| 2045. 到达目的地的第二短时间 | Hard | 最短路 | 实现采用最短路，详见本地源码。 | [leetcode2045.cc](../../leetcode/src/leetcode2045.cc) | `new` |

## 前缀和

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 437. 路径总和 III | Medium | 前缀和 | 实现采用前缀和，详见本地源码。 | [leetcode437.cc](../../leetcode/src/leetcode437.cc) | `new` |
| 560. 和为 K 的子数组 | Medium | 前缀和 | 前缀和 + 哈希表 | [leetcode560.cc](../../leetcode/src/leetcode560.cc) | `new` |
| 724. 寻找数组的中心下标 | Easy | 前缀和 | 左侧和等于右侧和时即为中心下标。 | [leetcode724.cc](../../leetcode/src/leetcode724.cc) | `new` |

## 归并

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 4. 寻找两个正序数组的中位数 | Hard | 归并 | 二分划分；寻找切割点平衡左右数量 | [leetcode4.cc](../../leetcode/src/leetcode4.cc) | `new` |

## 马拉车算法

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 5. 最长回文子串 | Medium | 马拉车算法 | 中心扩展或 Manacher | [leetcode5.cc](../../leetcode/src/leetcode5.cc) | `new` |

## 递归

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 10. 正则表达式匹配 | Hard | 递归 | 递归逐字符匹配；`*` 分支尝试跳过或消费当前字符 | [leetcode10.cc](../../leetcode/src/leetcode10.cc) | `new` |

## 链表反转

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 25. K 个一组翻转链表 | Hard | 链表反转 | 模式：分段翻转；核心：先求长度确定组数，利用“头插法”在 $O(n)$ 时间 $O(1)$ 空间内完成翻转 | [leetcode25.cc](../../leetcode/src/leetcode25.cc) | `new` |

## 链表操作

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 61. 旋转链表 | Medium | 链表操作 | 成环解环；先连成环再在 $n-(k\%n)$ 处断开 | [leetcode61.cc](../../leetcode/src/leetcode61.cc) | `new` |
| 138. 随机链表的复制 | Medium | 链表操作 | 模式：原地克隆；核心：`A->A'->B->B'` 插入法，实现 $O(1)$ 空间拷贝随机指针 | [leetcode138.cc](../../leetcode/src/leetcode138.cc) | `new` |

## 矩阵操作

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 48. 旋转图像 | Medium | 矩阵操作 | 转置 + 水平翻转 | [leetcode48.cc](../../leetcode/src/leetcode48.cc) | `new` |
| 73. 矩阵置零 | Medium | 矩阵操作 | 首行首列复用为标记位 | [leetcode73.cc](../../leetcode/src/leetcode73.cc) | `new` |
| 289. 生命游戏 | Medium | 矩阵操作 | 位编码同时保存旧状态和新状态 | [leetcode289.cc](../../leetcode/src/leetcode289.cc) | `new` |

## 模拟

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 66. 加一 | Easy | 模拟 | 模拟进位；从最低位向前传播进位 | [leetcode66.cc](../../leetcode/src/leetcode66.cc) | `new` |
| 415. 字符串相加 | Easy | 模拟 | 模拟竖式加法 | [leetcode415.cc](../../leetcode/src/leetcode415.cc) | `new` |

## 快速幂

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 50. x 的 n 次幂 | Medium | 快速幂 | 模式：快速幂；将大指数拆分为一半计算，实现 $O(\log n)$ | [leetcode50.cc](../../leetcode/src/leetcode50.cc) | `new` |

## 数学

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 9. 回文数 | Easy | 数学 | 反转后一半数字，避免整数溢出 | [leetcode9.cc](../../leetcode/src/leetcode9.cc) | `new` |
| 400. 第 N 位数字 | Medium | 数学 | 实现采用数学，详见本地源码。 | [leetcode400.cc](../../leetcode/src/leetcode400.cc) | `new` |

## 数论

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 172. 阶乘后的零 | Medium | 数论 | 数论；统计因子 5 的总数量 | [leetcode172.cc](../../leetcode/src/leetcode172.cc) | `new` |

## 位运算

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 136. 只出现一次的数字 | Easy | 位运算 | 异或抵消 | [leetcode136.cc](../../leetcode/src/leetcode136.cc) | `new` |
| 137. 只出现一次的数字 II | Medium | 位运算 | 位运算；逐位统计出现次数并对 3 取模恢复唯一数字 | [leetcode137.cc](../../leetcode/src/leetcode137.cc) | `new` |
| 190. 颠倒二进制位 | Easy | 位运算 | 逐位构造；依次取最低位并左移累积结果 | [leetcode190.cc](../../leetcode/src/leetcode190.cc) | `new` |
| 191. 位1的个数 | Easy | 位运算 | __builtin_popcount 手动实现 | [leetcode191.cc](../../leetcode/src/leetcode191.cc) | `new` |
| 231. 判断一个数是否是 2 的幂 | Easy | 位运算 | 有且仅有一个置位位1， n & (n - 1)  消除最低位1 | [leetcode231.cc](../../leetcode/src/leetcode231.cc) | `new` |
| 260. 只出现一次的数字 III | Medium | 位运算 | 整体异或后按 lowbit 分组 | [leetcode260.cc](../../leetcode/src/leetcode260.cc) | `new` |
| 421. 数组中两个数的最大异或值 | Hard | 位运算 | 模式：0-1 Trie；利用二进制前缀树实现 $O(n \log C)$ 的异或极值查找 | [leetcode421.cc](../../leetcode/src/leetcode421.cc) | `new` |

## 栈

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 155. 最小栈 | Medium | 栈 | 模式：双栈/辅助栈；核心：同步维护一个“当前的最小值”栈 | [leetcode155.cc](../../leetcode/src/leetcode155.cc) | `new` |
| 173. 二叉搜索树迭代器 | Medium | 栈 | 模式：栈模拟中序遍历；核心：利用显式栈实现懒加载，确保 $O(h)$ 空间与均摊 $O(1)$ 时间 | [leetcode173.cc](../../leetcode/src/leetcode173.cc) | `new` |
| 232. 用栈实现队列 | Easy | 栈 | 模式：双栈翻转；核心：利用入栈和出栈两个容器实现 FIFO | [leetcode232.cc](../../leetcode/src/leetcode232.cc) | `new` |

## 堆

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 295. 数据流的中位数 | Hard | 堆 | 最大堆 + 最小堆 | [leetcode295.cc](../../leetcode/src/leetcode295.cc) | `new` |
| 480. 滑动窗口中位数 | Hard | 堆 | 双堆 + 延迟删除；维护窗口两半元素数量平衡 | [leetcode480.cc](../../leetcode/src/leetcode480.cc) | `new` |

## 树深度优先搜索

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 236. 二叉树的最近公共祖先 | Medium | 树深度优先搜索 | 模式：DFS 递归；核心：利用返回值上传状态（自底向上聚合），实现无副作用的纯函数设计 | [leetcode236.cc](../../leetcode/src/leetcode236.cc) | `new` |

## 拓扑排序

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 210. 课程表 II | Medium | 拓扑排序 | 模式：BFS 拓扑序列；核心：记录入度为 0 的节点弹出顺序 | [leetcode210.cc](../../leetcode/src/leetcode210.cc) | `new` |
| 310. 最小高度树 | Medium | 拓扑排序 | 拓扑剥叶；不断删除叶子节点，最后剩余中心即最小高度树根 | [leetcode310.cc](../../leetcode/src/leetcode310.cc) | `new` |
| 2127. 参加会议的最多员工数 | Hard | 拓扑排序 | 基环树内向树，基环森林 | [leetcode2127.cc](../../leetcode/src/leetcode2127.cc) | `new` |
| 2360. 图中的最长环 | Hard | 拓扑排序 | 拓扑排序 + 环的处理 或者 时间戳DFS | [leetcode2360.cc](../../leetcode/src/leetcode2360.cc) | `new` |
| 2603. 收集树中金币 | Hard | 拓扑排序 | 模式：剥层法；通过度数反复删除叶子节点 | [leetcode2603.cc](../../leetcode/src/leetcode2603.cc) | `new` |

## 前后缀

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 238. 除了自身以外数组的乘积 | Medium | 前后缀 | 前缀积 + 后缀积；两次扫描避免使用除法 | [leetcode238.cc](../../leetcode/src/leetcode238.cc) | `new` |

## 单调队列

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 239. 滑动窗口最大值 | Hard | 单调队列 | 双端单调递减队列 | [leetcode239.cc](../../leetcode/src/leetcode239.cc) | `new` |

## 快慢指针

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 287. 寻找重复数 | Medium | 快慢指针 | 快慢指针找环 | [leetcode287.cc](../../leetcode/src/leetcode287.cc) | `new` |

## 树形动态规划

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 337. 打家劫舍 III | Medium | 树形动态规划 | 二叉树父子节点不同同时被偷 | [leetcode337.cc](../../leetcode/src/leetcode337.cc) | `new` |
| 2646. 最小化旅行的价格总和 | Hard | 树形动态规划 | 实现采用树形动态规划，详见本地源码。 | [leetcode2646.cc](../../leetcode/src/leetcode2646.cc) | `new` |

## 有序集合

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 45. 跳跃游戏 II | Medium | 有序集合 | 维护当前层可达边界与下一层最远位置，维护当前cur_max_dis,全局 max_dis | [leetcode45.cc](../../leetcode/src/leetcode45.cc) | `new` |
| 220. 存在重复元素 III | Medium | 有序集合 | 滑动窗口 + 有序集合 | [leetcode220.cc](../../leetcode/src/leetcode220.cc) | `new` |
| 327. 区间和的个数 | Hard | 有序集合 | 维护有序前缀和，统计目标区间内的历史前缀。 | [leetcode327.cc](../../leetcode/src/leetcode327.cc) | `new` |

## 水塘抽样

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 382. 链表随机节点 | Medium | 水塘抽样 | 模式：水塘抽样；核心：从未知长度流中等概率采样，确保概率为 $1/i$ | [leetcode382.cc](../../leetcode/src/leetcode382.cc) | `new` |
| 398. 随机数索引 | Medium | 水塘抽样 | 实现采用水塘抽样，详见本地源码。 | [leetcode398.cc](../../leetcode/src/leetcode398.cc) | `new` |

## 原地标记

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 448. 找到所有数组中消失的数字 | Easy | 原地标记 | 原地负号标记 | [leetcode448.cc](../../leetcode/src/leetcode448.cc) | `new` |

## 循环检测

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 466. 统计重复个数 | Hard | 循环检测 | 实现采用循环检测，详见本地源码。 | [leetcode466.cc](../../leetcode/src/leetcode466.cc) | `new` |

## 0-1 广度优先搜索

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 1368. 使网格图至少有一条有效路径的最小代价 | Hard | 0-1 广度优先搜索 | 0-1 BFS；沿箭头走的边权为 0 | [leetcode1368.cc](../../leetcode/src/leetcode1368.cc) | `new` |

## 状态压缩

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 996. 正方形数组的数目 | Hard | 状态压缩 | 预处理/重复数字全排列 | [leetcode996.cc](../../leetcode/src/leetcode996.cc) | `new` |

## 区间动态规划

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 877. 石子游戏 | Medium | 区间动态规划 | 实现采用区间动态规划，详见本地源码。 | [leetcode877.cc](../../leetcode/src/leetcode877.cc) | `new` |

## Tarjan

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 1192. 查找集群内的关键连接 | Hard | Tarjan | 实现采用Tarjan，详见本地源码。 | [leetcode1192.cc](../../leetcode/src/leetcode1192.cc) | `new` |

## 树状数组

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 307. 区域和检索 - 数组可修改 | Medium | 线段树 | 线段树维护区间和，支持单点更新和区间查询 | [leetcode307.cc](../../leetcode/src/leetcode307.cc) | `new` |

## 线段树

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 2407. 最长递增子序列 II | Hard | 线段树 | 线段树优化 | [leetcode2407.cc](../../leetcode/src/leetcode2407.cc) | `new` |
| 2916. 子数组不同元素数目的平方和 II | Hard | 线段树 | 线段树 | [leetcode2916.cc](../../leetcode/数据结构运用/线段树/leetcode2916.cc) | `new` |

## 二分答案

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 2560. 打家劫舍 IV | Medium | 二分答案 | 固定能力值后尽早选择不相邻房屋 | [leetcode2560.cc](../../leetcode/src/leetcode2560.cc) | `new` |
| 2812. 找出最安全路径 | Hard | 二分答案 | 网格多源 BFS | [leetcode2812.cc](../../leetcode/src/leetcode2812.cc) | `new` |

## 前缀最大值

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 769. 最多能完成排序的块 | Medium | 前缀最大值 | 模式：贪心模拟；核心：维护当前最大值，若 `max == index` 则可分块 | [leetcode769.cc](../../leetcode/src/leetcode769.cc) | `new` |

## 哈希表与数组

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 380. O(1) 时间插入、删除和获取随机元素 | Medium | 哈希表与数组 | 模式：哈希表 + 动态数组；利用数组末尾交换实现 $O(1)$ 删除 | [leetcode380.cc](../../leetcode/src/leetcode380.cc) | `new` |

## 数位动态规划

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| 233. 数字 1 的个数 | Hard | 数位动态规划 | 数位 DFS 记录当前位置、数字 1 的累计数量和上界约束。 | [leetcode233.cc](../../leetcode/src/leetcode233.cc) | `new` |
| 600. 二进制不含连续1的非负整数 | Hard | 数位动态规划 | 数位DP | [leetcode600.cc](../../leetcode/src/leetcode600.cc) | `new` |
| 1012. 至少有 1 位重复的数字 | Hard | 数位动态规划 | 数位 DP 用掩码记录已使用数字和上界约束。 | [leetcode1012.cc](../../leetcode/src/leetcode1012.cc) | `new` |

## 其它来源

| Problem | Difficulty | Pattern | Key idea | Source | Review |
| --- | --- | --- | --- | --- | --- |
| Offer 22. 层序遍历 | Easy | 广度优先搜索 | 按 FIFO 顺序逐层处理树结点。 | [offer22.cc](../../剑指offer/src/offer22.cc) | `new` |
