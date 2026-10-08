/*
力扣数据中心有 n 台服务器，分别按从 0 到 n-1 的方式进行了编号。它们之间以 服务器到服务器 的形式相互连接组成了一个内部集群，连接是无向的。用  connections 表示集群网络，connections[i] = [a, b] 表示服务器 a 和 b 之间形成连接。任何服务器都可以直接或者间接地通过网络到达任何其他服务器。

关键连接 是在该集群中的重要连接，假如我们将它移除，便会导致某些服务器无法访问其他服务器。

请你以任意顺序返回该集群内的所有 关键连接 。


输入：n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
输出：[[1,3]]
解释：[[3,1]] 也是正确的。


解题思路
Tarjan算法可以用于寻找割点和割边，只需要稍微修改条件

先看寻找割点的算法
判断一个点是否是割点可以通过看其子节点能否不通过该节点向上越（到达一个发现时间更早的点）
一个点向上越（最小发现时间）有三种情况
back=discovertime[v]：自己的发现时间
back=min(back,discovertime[v])：自己向上越（一个灰色节点）
back=min(back,wback)：通过子节点向上越
wback为返回值
如果一个点的子节点wback值大于等于父节点，那么该父节点就是一个割点


vector<int>ans;
int times = 0;
vector<int> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>>edges(n);
    vector<int>color(n), discovertime(n);
    for (auto& a : connections)
    {
        edges[a[0]].push_back(a[1]);
        edges[a[1]].push_back(a[0]);
    }
    dfs(edges, 0, color, discovertime,-1);
    ans.pop_back();//初始节点会被额外加入，要删除
    return ans;
}
int dfs(vector<vector<int>>& edges, int n, vector<int>& color, vector<int>& discovertime,int parent)
{
    color[n] = 1;
    discovertime[n] = times;
    times++;
    int back = times;
    for (auto a : edges[n])
    {
        if (color[a] == 1&&a!=parent)//回溯
        {
            back = min(back, discovertime[a]);
        }
        else if(color[a] == 0)
        {
            int wback = dfs(edges, a, color, discovertime,n);
            if (wback >= discovertime[n]&&find(ans.begin(),ans.end(),n)==ans.end())//去重
                ans.push_back(n);
            back = min(back, wback);
        }
    }
    color[n] = 2;
    return back;
}

再看本题，是寻找割边，只需要稍加修改
与割点类似，修改条件为wback >discovertime[n]
ans.push_back(vector<int>{a,n});
不需要额外pop
代码
class Solution {
public:
    vector<vector<int>>ans;
    int time=0;
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>>edges(n);
    vector<int>color(n), discovertime(n);
    for (auto& a : connections)
    {
        edges[a[0]].push_back(a[1]);
        edges[a[1]].push_back(a[0]);
    }
    dfs(edges, 0, color, discovertime,-1);
    return ans;
}
int dfs(vector<vector<int>>& edges, int n, vector<int>& color, vector<int>& discovertime,int parent)
{
    color[n] = 1;
    discovertime[n] = time;
    time++;
    int back = time;
    for (auto a : edges[n])
    {
        if (color[a] == 1&&a!=parent)
        {
            back = min(back, discovertime[a]);
        }
        else if(color[a] == 0)
        {
            int wback = dfs(edges, a, color, discovertime,n);
            if (wback >discovertime[n])
                ans.push_back(vector<int>{a,n});
            back = min(back, wback);
        }
    }
    color[n] = 2;
    return back;
}
};

作者：thdlrt
链接：https://leetcode.cn/problems/critical-connections-in-a-network/solutions/2047434/c-by-thdlrt-4h41/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> g;
        for(auto c : connections){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        vector<int> dfn(n,0);
        vector<int> low(n,0);
        int time = 0;

        vector<vector<int>> ans;
        function<void(int,int)> dfs;
        dfs = [&](int cur,int fa){
            dfn[cur] = low[cur] = ++time;
            for(int v : g[cur]){
                if(!dfn[v]){
                    dfs(v,cur);
                    low[cur] = min(low[cur],low[v]);

                }
            }
        };
        dfs(0,-1);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> ans = Solution().criticalConnections(4,connections);
    for(auto a : ans){
        std::cout << a[0] << '\t' << a[1] << std::endl;
    }
    return 0;
}
