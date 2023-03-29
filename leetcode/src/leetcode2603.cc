/*
给你一个 n 个节点的无向无根树，节点编号从 0 到 n - 1 。给你整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间有一条边。再给你一个长度为 n 的数组 coins ，其中 coins[i] 可能为 0 也可能为 1 ，1 表示节点 i 处有一个金币。

一开始，你需要选择树中任意一个节点出发。你可以执行下述操作任意次：

收集距离当前节点距离为 2 以内的所有金币，或者
移动到树中一个相邻节点。
你需要收集树中所有的金币，并且回到出发节点，请你返回最少经过的边数。

如果你多次经过一条边，每一次经过都会给答案加一。
*/

#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
        int n = coins.size();
        vector<vector<int>> g(n);
        int deg[n]; memset(deg, 0, sizeof(deg));
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建图
            ++deg[x];
            ++deg[y];
        }

        // 用拓扑排序「剪枝」：去掉没有金币的子树
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (deg[i] == 1 && coins[i] == 0) // 无金币叶子
                q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y: g[x])
                if (--deg[y] == 1 && coins[y] == 0)
                    q.push(y);
        }

        // 再次拓扑排序
        for (int i = 0; i < n; ++i)
            if (deg[i] == 1 && coins[i]) // 有金币叶子
                q.push(i);
        if (q.size() <= 1) return 0; // 至多一个有金币的叶子，直接收集
        int time[n]; memset(time, 0, sizeof(time));
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y: g[x])
                if (--deg[y] == 1) {
                    time[y] = time[x] + 1; // 记录入队时间
                    q.push(y);
                }
        }

        // 统计答案
        int ans = 0;
        for (auto &e: edges)
            if (time[e[0]] >= 2 && time[e[1]] >= 2)
                ans += 2;
        return ans;
    }
};