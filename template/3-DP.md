---
title: 算法面试：动态规划复习手册
date: 2026-08-25
categories:
  - 系统设计基础
tags:
  - 算法
  - LeetCode
  - 动态规划
  - 面试
toc: true
---

> DP 的核心不是背公式，而是回答四件事：**状态是什么？最后一步怎样来？初始状态是什么？计算顺序为何保证依赖已求出？**

## 1. DP 选型决策表

| 题目特征 | 首选状态 | 关键点 |
| --- | --- | --- |
| 只和当前位置前面有关 | `dp[i]` | 线性 DP / 滚动变量 |
| 选或不选、容量限制 | `dp[c]` | 背包，循环方向决定次数 |
| 两字符串/两数组 | `dp[i][j]` | LCS、编辑距离、匹配 |
| 连续子数组/子串 | 以 `i` 结尾 | 与“子序列”区分连续性 |
| 两端向中间合并 | `dp[l][r]` | 区间长度从小到大 |
| 树上选点/路径 | `dp[u][state]` | 后序 DFS，父子关系 |
| 子集、位掩码 | `dp[mask]` | 枚举子集或最后一个元素 |
| 数字范围、每位约束 | `dfs(pos, state, limit, started)` | 数位 DP 的前导零与上界 |

### 写 DP 前检查清单

1. `dp` 表示“恰好”还是“至多/至少”？
2. 不可达状态初始化 `-INF`、`INF` 还是 `0`？
3. 转移依赖同一层还是上一层？这决定容量循环正序/倒序。
4. 能否滚动数组？滚动后是否覆盖了仍要读取的状态？

## 2. 线性 DP：爬楼梯、打家劫舍、最大子数组

**触发词**：第 `i` 个位置、相邻不能同时选、以 `i` 结尾、最少/最多方案。

```cpp
// 以 i 结尾的最大子数组和；dp 只依赖前一项
int maxSubArray(vector<int>& nums) {
  int cur = nums[0], ans = nums[0];
  for (int i = 1; i < (int)nums.size(); ++i) {
    cur = max(nums[i], cur + nums[i]);
    ans = max(ans, cur);
  }
  return ans;
}

// 打家劫舍：dp[i] 表示前 i 个房屋的最大值
int rob(vector<int>& nums) {
  int pre2 = 0, pre1 = 0;
  for (int x : nums) {
    int cur = max(pre1, pre2 + x);
    pre2 = pre1; pre1 = cur;
  }
  return pre1;
}
```

**常见坑**：最大子数组初始值不能是 `0`（全负数组）；环形数组拆成“选首不选尾”和“选尾不选首”；`dp[i]` 的语义要始终一致。

题单：53 最大子数组和、198 打家劫舍、213 打家劫舍 II、70 爬楼梯、746 使用最小花费爬楼梯、91 解码方法。

## 3. 背包 DP

背包题先确定四件事：**什么是物品、什么是容量、每件物品能选几次、`dp` 求可达性/最值/方案数中的哪一种**。循环方向只是这些约束在一维滚动数组中的结果，不能脱离状态定义死记。

| 分类维度 | 要回答的问题 | 常见类型 |
| --- | --- | --- |
| 使用次数 | 同一件物品最多选几次？ | 0/1、完全、多重、混合背包 |
| 物品关系 | 不同选项能否同时选择？ | 分组、依赖、树形背包 |
| 容量维度 | 同时受几个资源限制？ | 一维、二维、多维背包 |
| 求解目标 | 要判断、优化还是计数？ | 可达性、最大/最小值、方案数 |

### 3.1 0/1 背包：每件最多选择一次

`dp[c]` 表示容量不超过 `c` 时的最大价值。物品放在外层时，容量必须**倒序**，确保转移读取的是加入当前物品之前的状态。

```cpp
int zeroOneKnapsack(const vector<int>& weight, const vector<int>& value, int cap) {
  vector<int> dp(cap + 1, 0);
  for (int i = 0; i < (int)weight.size(); ++i) {
    for (int c = cap; c >= weight[i]; --c) {
      dp[c] = max(dp[c], dp[c - weight[i]] + value[i]);
    }
  }
  return dp[cap];
}
```

若正序遍历容量，刚更新的 `dp[c-weight[i]]` 会再次使用当前物品，模型就错误地变成完全背包。

题单：[416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum)、[1049. 最后一块石头的重量 II](https://leetcode.cn/problems/last-stone-weight-ii)、[494. 目标和](https://leetcode.cn/problems/target-sum)。

### 3.2 完全背包：每种物品可以选择无限次

容量必须**正序**。更新 `dp[c]` 时，`dp[c-weight[i]]` 可以已经选过当前物品，从而允许继续选择它。

```cpp
int completeKnapsack(const vector<int>& weight, const vector<int>& value, int cap) {
  vector<int> dp(cap + 1, 0);
  for (int i = 0; i < (int)weight.size(); ++i) {
    for (int c = weight[i]; c <= cap; ++c) {
      dp[c] = max(dp[c], dp[c - weight[i]] + value[i]);
    }
  }
  return dp[cap];
}
```

题单：[322. 零钱兑换](https://leetcode.cn/problems/coin-change)、[518. 零钱兑换 II](https://leetcode.cn/problems/coin-change-ii)、[279. 完全平方数](https://leetcode.cn/problems/perfect-squares)、[139. 单词拆分](https://leetcode.cn/problems/word-break)。

### 3.3 多重背包：每种物品有有限数量

第 `i` 种物品最多选择 `count[i]` 次。数量较小时可以枚举次数；一般将数量按 `1, 2, 4, ..., 剩余` 二进制拆分，每一份作为一件 0/1 物品；容量和数量都很大时可考虑单调队列优化。

```cpp
int boundedKnapsack(const vector<int>& weight, const vector<int>& value,
                    const vector<int>& count, int cap) {
  vector<int> dp(cap + 1, 0);
  for (int i = 0; i < (int)weight.size(); ++i) {
    for (int k = 1, left = count[i]; left > 0; k <<= 1) {
      int take = min(k, left);
      left -= take;
      int w = take * weight[i], v = take * value[i];
      for (int c = cap; c >= w; --c) {
        dp[c] = max(dp[c], dp[c - w] + v);
      }
    }
  }
  return dp[cap];
}
```

**易混点**：多重背包表示“一种物品有多份”；分组背包表示“一组候选互斥，只能选其中一个”。

### 3.4 分组背包：每组最多选择一个选项

分组背包也称多选择背包（Multiple-choice Knapsack）。物品被划分成若干组，每组可以不选，也可以选择其中一个选项。为避免同组多个选项互相转移，最稳妥的写法是从上一组的 `dp` 生成 `next`。

```cpp
// 每个选项是 {对目标和的贡献, 选择该选项的代价}。
int groupedMinCost(const vector<vector<pair<int, int>>>& groups, int target) {
  const int INF = 1e9;
  vector<int> dp(target + 1, INF);
  dp[0] = 0;

  for (const auto& group : groups) {
    vector<int> next = dp;  // 保留“不选择本组”的状态
    for (int sum = 0; sum <= target; ++sum) {
      if (dp[sum] == INF) continue;
      for (auto [weight, cost] : group) {
        if (sum + weight <= target) {
          next[sum + weight] = min(next[sum + weight], dp[sum] + cost);
        }
      }
    }
    dp.swap(next);
  }
  return dp[target] == INF ? -1 : dp[target];
}
```

4040 和 4041 的映射如下：

| 背包概念 | 题目中的含义 |
| --- | --- |
| 一个分组 | 一个原始数组元素 |
| 组内选项 | 该元素经过操作后能够得到的不同数值 |
| 选项重量 | 变换后的数值，即对子集和的贡献 |
| 选项代价 | 得到该数值的最少操作次数 |
| 不选择本组 | 不把该元素放入最终子集 |

- [4040. 构造子集和的最少操作次数 I](https://leetcode.cn/problems/minimum-operations-to-form-subset-sum-i/)：先枚举每个元素在“先乘后除”限制下的可达值，再做分组最小代价背包。
- [4041. 构造子集和的最少操作次数 II](https://leetcode.cn/problems/minimum-operations-to-form-subset-sum-ii/)：二进制下除以二是删除末位、乘以二是补 `0`，可达正整数形如 `(x >> d) << k`，再做同样的分组背包。

### 3.5 混合背包：多种使用次数同时出现

同一道题中，有些物品只能选择一次，有些可以无限选择，有些有数量上限。通常逐类套用对应转移：

| 物品类型 | 处理方式 |
| --- | --- |
| 0/1 物品 | 容量倒序 |
| 完全物品 | 容量正序 |
| 有限数量物品 | 二进制拆分后按 0/1 物品处理 |

如果 `count[i] * weight[i] >= cap`，在容量 `cap` 内该物品的数量实际上不构成限制，可以直接按完全背包处理。

### 3.6 多维背包：同时消耗多种容量

当选择一个物品会同时消耗多种资源时，状态增加相应的容量维度。二维 0/1 背包仍需让每个容量维度倒序遍历。

```cpp
// item = {第一维消耗, 第二维消耗, 价值}
int twoDimensionalKnapsack(const vector<array<int, 3>>& items,
                           int cap1, int cap2) {
  vector<vector<int>> dp(cap1 + 1, vector<int>(cap2 + 1));
  for (auto [w1, w2, value] : items) {
    for (int c1 = cap1; c1 >= w1; --c1) {
      for (int c2 = cap2; c2 >= w2; --c2) {
        dp[c1][c2] = max(dp[c1][c2], dp[c1 - w1][c2 - w2] + value);
      }
    }
  }
  return dp[cap1][cap2];
}
```

题单：[474. 一和零](https://leetcode.cn/problems/ones-and-zeroes/)，容量分别是可使用的 `0` 和 `1` 的数量。

### 3.7 依赖背包 / 树形背包

某件物品只有在其依赖项被选择后才能选择，例如“主件—附件”；当依赖关系形成树时，就得到树形背包。

基本做法是：

1. 用后序 DFS 先求出每棵子树的状态；
2. `dp[u][c]` 表示选择节点 `u` 的前提下，在其子树中使用容量 `c` 的最优值；
3. 逐个合并孩子 `v`，枚举分给孩子的容量 `k`：

```cpp
next[c] = max(next[c], dp[u][c - k] + dp[v][k]);
```

每次合并一个孩子，本质上都是一次分组背包。朴素合并通常为 `O(n * cap^2)`，需要结合子树大小缩小枚举范围。

### 3.8 背包的可达性、最值与计数

背包类型决定“物品如何选择”，求解目标决定 `dp` 的含义、初始值和聚合方式。这两个维度彼此独立。

| 目标 | `dp[c]` 的含义 | 初始化 | 转移聚合 |
| --- | --- | --- | --- |
| 可达性 | 是否能恰好得到 `c` | `dp[0]=true`，其余 `false` | 逻辑或 |
| 不超过容量的最大价值 | 容量不超过 `c` 的最大价值 | 全部为 `0` | `max` |
| 恰好装满的最大价值 | 恰好得到 `c` 的最大价值 | `dp[0]=0`，其余 `-INF` | `max` |
| 恰好装满的最小代价 | 恰好得到 `c` 的最小代价 | `dp[0]=0`，其余 `INF` | `min` |
| 方案数 | 恰好得到 `c` 的方案数量 | `dp[0]=1`，其余 `0` | 求和 |

```cpp
// 完全背包：恰好凑成 target 的最少硬币数。
int coinChange(vector<int>& coins, int target) {
  const int INF = target + 1;
  vector<int> dp(target + 1, INF);
  dp[0] = 0;
  for (int coin : coins) {
    for (int sum = coin; sum <= target; ++sum) {
      dp[sum] = min(dp[sum], dp[sum - coin] + 1);
    }
  }
  return dp[target] == INF ? -1 : dp[target];
}
```

计数问题还要区分顺序：

- 求组合数：物品在外层、容量在内层，同一组物品的不同排列只计算一次；
- 求排列数：容量在外层、物品在内层，不同选择顺序分别计数；
- 求最值或可达性：循环顺序主要由物品能否重复使用决定。

**总口诀**：0/1 倒序、完全正序、多重先拆分、分组读上一层；恰好装满先设不可达，计数先判断组合还是排列。

复杂度速查：0/1 与完全背包通常为 `O(n * cap)`；二进制优化的多重背包为 $O(cap \cdot \sum_i \log(count[i]+1))$；分组背包为 `O(cap * 组内选项总数)`；二维背包为 `O(n * cap1 * cap2)`。

## 4. 双序列 DP：LCS、编辑距离、匹配

**状态**：`dp[i][j]` 通常表示 `a` 前 `i` 个字符和 `b` 前 `j` 个字符的答案；这样空前缀自然是第 `0` 行/列。

```cpp
int longestCommonSubsequence(string a, string b) {
  int m=a.size(), n=b.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1));
  for (int i=1;i<=m;++i) for (int j=1;j<=n;++j)
    dp[i][j] = a[i-1]==b[j-1] ? dp[i-1][j-1]+1 : max(dp[i-1][j],dp[i][j-1]);
  return dp[m][n];
}

int minDistance(string a, string b) { // 编辑距离
  int m=a.size(), n=b.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1));
  for(int i=0;i<=m;++i) dp[i][0]=i;
  for(int j=0;j<=n;++j) dp[0][j]=j;
  for(int i=1;i<=m;++i) for(int j=1;j<=n;++j)
    dp[i][j] = a[i-1]==b[j-1] ? dp[i-1][j-1] : 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
  return dp[m][n];
}
```

题单：1143 最长公共子序列、72 编辑距离、583 两个字符串的删除操作、97 交错字符串、115 不同的子序列、1035 不相交的线。

## 5. 子序列、区间与树形 DP

### LIS：贪心 + 二分优先

`tails[len-1]` 为长度为 `len` 的递增子序列的最小结尾；它不直接保存答案序列，但长度正确。复杂度 `O(n log n)`。

题单：300 最长递增子序列、354 俄罗斯套娃信封（第一维升序、相同第一维第二维降序）、673 最长递增子序列的个数（DP 维护长度和数量）。

### 区间 DP

`dp[l][r]` 依赖更短区间，按区间长度递增枚举。常见“最后一次合并/最后一个气球”转移，把外层边界固定后枚举最后动作。

题单：5 最长回文子串、516 最长回文子序列、312 戳气球、1039 多边形三角剖分的最低得分、664 奇怪的打印机。

### 树形 DP

后序 DFS。经典状态是“选/不选当前点”：`dp[u][0/1]`，选 `u` 时孩子不能选；不选 `u` 时孩子取最大。

题单：337 打家劫舍 III、968 监控二叉树、124 二叉树中的最大路径和。

## 6. 状态压缩与数位 DP

### 状态压缩 DP

`mask` 表示已选集合；常见转移是从 `mask` 删除最后选的元素，或枚举 `sub=(sub-1)&mask`。

题单：698 划分为 k 个相等的子集、847 访问所有节点的最短路径、1125 最小的必要团队、526 优美的排列。

### 数位 DP：范围内满足数字约束的个数

状态通常为 `dfs(pos, pre, isLimit, isNum)`：

- `pos`：处理到第几位；
- `pre`：上一位或题目所需状态；
- `isLimit`：前缀是否仍贴着上界；
- `isNum`：前面是否已经填过有效数字，负责处理前导零。

```cpp
// 统计 [1,n] 中相邻数字不相等的正整数个数
int countNoAdjacentEqual(int n) {
  string s=to_string(n); int memo[20][11]; memset(memo,-1,sizeof(memo));
  function<int(int,int,bool,bool)> dfs = [&](int pos,int pre,bool limit,bool started) {
    if(pos==(int)s.size()) return started ? 1 : 0;
    if(!limit && started && memo[pos][pre]!=-1) return memo[pos][pre];
    int up=limit?s[pos]-'0':9, ans=0;
    if(!started) ans += dfs(pos+1,10,false,false); // 跳过本位，保持前导零
    for(int d=started?0:1; d<=up; ++d) {
      if(started && d==pre) continue;
      ans += dfs(pos+1,d,limit && d==up,true);
    }
    if(!limit && started) memo[pos][pre]=ans;
    return ans;
  };
  return dfs(0,10,true,false);
}
```

**常见坑**：跳过本位后 `isLimit` 仍应为 `false`（此处上界首位不为零）；缓存不能包含 `isLimit=true` 的状态；计数题注意取模与 `long long`。

题单：233 数字 1 的个数、600 不含连续 1 的非负整数、902 最大为 N 的数字组合、1012 至少有 1 位重复的数字、2376 统计特殊整数。

## 7. 高频错误与 14 天复习

| 错误 | 修正 |
| --- | --- |
| 01 背包正序循环 | 改为倒序，否则同一物品被重复使用 |
| 完全背包倒序循环 | 改为正序，否则每种只用一次 |
| 分组背包读取本组刚更新的状态 | 每组从上一层 `dp` 生成 `next`，避免同组选多个 |
| 恰好凑满初始化为 0 | 不可达初始化 `INF/-INF`，仅 `dp[0]` 为 0 |
| 组合数与排列数使用相同循环顺序 | 组合数物品在外，排列数容量在外 |
| 子数组和子序列混淆 | 子数组必须连续，状态转移不同 |
| 区间 DP 从大到小 | 按区间长度从小到大 |
| 数位 DP 缓存 `limit=true` | 上界不同，不能复用 |

| 天数 | 内容 |
| --- | --- |
| 1–2 | 线性 DP、最大子数组、打家劫舍 |
| 3–5 | 0/1、完全、多重、分组背包与恰好装满 |
| 6–7 | 双序列、LCS、编辑距离 |
| 8–9 | LIS、区间、树形 DP |
| 10–11 | 状压 DP、数位 DP |
| 12–14 | 混合题、盲写模板、错题复盘 |

复盘模板：

```text
题目：
状态定义：
最后一步/转移：
初始化：
循环顺序及原因：
不可达状态与边界：
复杂度：
24 小时后能否盲写：是 / 否
```
