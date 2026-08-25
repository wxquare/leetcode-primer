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

## 3. 背包：循环方向就是物品数量

### 01 背包：每件最多一次

`dp[c]` 表示容量不超过 `c` 的最大价值。容量必须**倒序**，确保当前物品不会重复使用。

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

### 完全背包：每种无限次

容量必须**正序**，`dp[c-weight]` 已经包含当前物品，故可以继续选。

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

### 多重背包：二进制拆分为 01 背包

把数量 `s` 拆为 `1,2,4,...,剩余`，每一组当作一件 01 物品。

```cpp
int boundedKnapsack(const vector<int>& w, const vector<int>& v,
                    const vector<int>& count, int cap) {
  vector<int> dp(cap + 1);
  for (int i = 0; i < (int)w.size(); ++i) {
    for (int k = 1, left = count[i]; left > 0; k <<= 1) {
      int take = min(k, left); left -= take;
      int ww = take * w[i], vv = take * v[i];
      for (int c = cap; c >= ww; --c) dp[c] = max(dp[c], dp[c - ww] + vv);
    }
  }
  return dp[cap];
}
```

### “恰好装满”与方案数

```cpp
// 恰好凑成 target 的最少硬币数：不可达应为 INF，不能初始化为 0
int coinChange(vector<int>& coins, int target) {
  const int INF = target + 1;
  vector<int> dp(target + 1, INF); dp[0] = 0;
  for (int coin : coins)
    for (int x = coin; x <= target; ++x)
      dp[x] = min(dp[x], dp[x - coin] + 1);
  return dp[target] == INF ? -1 : dp[target];
}
```

**口诀**：01 倒序、完全正序；组合数“物品在外、容量在内”，排列数反过来。

题单：416 分割等和子集、474 一和零、322 零钱兑换、518 零钱兑换 II、279 完全平方数、139 单词拆分、1049 最后一块石头 II、494 目标和。

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
| 恰好凑满初始化为 0 | 不可达初始化 `INF/-INF`，仅 `dp[0]` 为 0 |
| 子数组和子序列混淆 | 子数组必须连续，状态转移不同 |
| 区间 DP 从大到小 | 按区间长度从小到大 |
| 数位 DP 缓存 `limit=true` | 上界不同，不能复用 |

| 天数 | 内容 |
| --- | --- |
| 1–2 | 线性 DP、最大子数组、打家劫舍 |
| 3–5 | 01/完全/多重背包与恰好装满 |
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
