#include <vector>
#include <queue>
using namespace std;


namespace undirected_graph{
    /*
        1. 无向图的最短环
        2. 枚举每个点跑BFS
    */

int findShortestCycle(int n,vector<vector<int>>& edges){
    vector<vector<int>> g(n);
    for(auto e : edges){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    int dis[n]; // start 到每个点的距离
    function<int(int)> bfs = [&](int start)->int {
        int ans = -1;
        memset(dis,-1,sizeof(dis));
        dis[start] = 0;

        queue<pair<int,int>> q;
        q.push({start,-1});
        while(!q.empty()){
            auto [u,fa] = q.front();
            q.pop();

            for(int v : g[u]){
                if(dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    q.push({v,u});
                } else { // 第二次遇到且不是father节点
                    if(v != fa){
                        int t = dis[u] + dis[v] + 1;
                        ans = ans == -1 ? t : min(t,ans);
                    }
                }
            }
        }
    };
    int ans = -1;
    for(int i=0;i<n;i++){
        int t = bfs(i);
        if(t == -1) continue;
        ans = ans == -1 ? t : min(ans,t);
    }
    return ans;
}
}

namespace directed_graph {
int findlo
};


