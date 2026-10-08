/*
现有一棵无向、无根的树，树中有 n 个节点，按从 0 到 n - 1 编号。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。

每个节点都关联一个价格。给你一个整数数组 price ，其中 price[i] 是第 i 个节点的价格。

给定路径的 价格总和 是该路径上所有节点的价格之和。

另给你一个二维整数数组 trips ，其中 trips[i] = [starti, endi] 表示您从节点 starti 开始第 i 次旅行，并通过任何你喜欢的路径前往节点 endi 。

在执行第一次旅行之前，你可以选择一些 非相邻节点 并将价格减半。

返回执行所有旅行的最小价格总和。


题解：

如果知道每个点总共被经过多少次，就可以仿照 337. 打家劫舍 III 计算答案了（下面会细说）。

注意到数据范围比较小，可以对每个 trips[i]\textit{trips}[i]trips[i] 都跑一遍 DFS，把从 start\textit{start}start 到 end\textit{end}end 的路径上的点 xxx 的经过次数 cnt[x]\textit{cnt}[x]cnt[x] 都加一。这一技巧在之前的双周赛中出现过，见 2467. 树上最大得分和路径。

提示 2
既然知道了每个点会被经过多少次，把 price[i]\textit{price}[i]price[i] 更新成 price[i]⋅cnt[i]\textit{price}[i]\cdot \textit{cnt}[i]price[i]⋅cnt[i]，问题就变成计算减半后的 price[i]\textit{price}[i]price[i] 之和的最小值。

随便选一个节点出发 DFS，比如节点 000。对于节点 xxx 及其儿子 yyy，分类讨论：

如果 price[x]\textit{price}[x]price[x] 不变，那么 price[y]\textit{price}[y]price[y] 可以减半，也可以不变，取这两种情况的最小值；
如果 price[x]\textit{price}[x]price[x] 减半，那么 price[y]\textit{price}[y]price[y] 只能不变。
因此子树 xxx 需要返回两个值：

price[x]\textit{price}[x]price[x] 不变时的子树 xxx 的最小价值总和；
price[x]\textit{price}[x]price[x] 减半时的子树 xxx 的最小价值总和。
答案就是根节点不变/减半的最小值。



输入：n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips = [[0,3],[2,1],[2,3]]
输出：23
解释：
上图表示将节点 2 视为根之后的树结构。第一个图表示初始树，第二个图表示选择节点 0 、2 和 3 并使其价格减半后的树。
第 1 次旅行，选择路径 [0,1,3] 。路径的价格总和为 1 + 2 + 3 = 6 。
第 2 次旅行，选择路径 [2,1] 。路径的价格总和为 2 + 5 = 7 。
第 3 次旅行，选择路径 [2,1,3] 。路径的价格总和为 5 + 2 + 3 = 10 。
所有旅行的价格总和为 6 + 7 + 10 = 23 。可以证明，23 是可以实现的最小答案。


*/
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }


        //dfs 寻路
        int cnt[n]; memset(cnt, 0, sizeof(cnt));
        function<bool(int, int, int)> dfs = [&](int x, int fa,int end) -> bool {
            if (x == end) { // 到达终点（注意树只有唯一的一条简单路径）
                ++cnt[x]; // 统计从 start 到 end 的路径上的点经过了多少次
                return true; // 找到终点
            }
            for (int y: g[x])
                if (y != fa && dfs(y, x, end)) {
                    ++cnt[x]; // 统计从 start 到 end 的路径上的点经过了多少次
                    return true; // 找到终点
                }
            return false; // 未找到终点
        };


        for (auto &t: trips) {
            int end = t[1];
            dfs(t[0], -1, t[1]);
        }

        // 类似 337. 打家劫舍 III https://leetcode.cn/problems/house-robber-iii/
        function<pair<int, int>(int, int)> dfs2 = [&](int x, int fa) -> pair<int, int> {
            int not_halve = price[x] * cnt[x]; // x 不变
            int halve = not_halve / 2; // x 减半
            for (int y: g[x])
                if (y != fa) {
                    auto [nh, h] = dfs2(y, x); // 计算 y 不变/减半的最小价值总和
                    not_halve += min(nh, h); // x 不变，那么 y 可以不变，可以减半，取这两种情况的最小值
                    halve += nh; // x 减半，那么 y 只能不变
                }
            return {not_halve, halve};
        };
        auto [nh, h] = dfs2(0, -1);
        return min(nh, h);
    }
};