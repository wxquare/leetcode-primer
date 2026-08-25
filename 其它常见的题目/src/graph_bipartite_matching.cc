/*
    1. 二分图判定
    2. 二分图最大匹配

*/

#include <vector>
using namespace std;

int hungarian(int n,vector<vector<int>>& edges) {
    // build graph
    vector<vector<int>> g(n);
    for(auto e : edges){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    vector<int> match(n,-1);// 每个点math的点，匹配的点
    int maxMatch = 0; // ans 最大匹配数量
    bool vis[n];
    function<bool(int)> dfs = [&](int u)->bool{
        for(auto v : g[u]){
            if(vis[v]) continue;
            vis[v] = true;
            if(match[v] == -1 || dfs(v)){
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
    };
    for(int i=0;i<n;i++){
        if(match[i] == -1){
            memset(vis,-1,sizeof(vis));
            vis[i] = true;
            if(dfs(i)){
                maxMatch++;
            }
        }
    } 
    return maxMatch;
}