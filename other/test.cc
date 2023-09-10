#include <vector>
using namespace std;

// 求无向图的割边
// leetcode 1192. 查找集群内的关键连接
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    // 建图
    vector<vector<int>> g(n);
    for(auto & c : connections){
        g[c[0]].push_back(c[1]);
        g[c[1]].push_back(c[0]);
    }

    vector<int> dfn(n,-1); // 搜索树的时间戳
    vector<int> low(n); // 不经过父节点能追溯到的最早节点
    vector<int> fa(n);
    vector<vector<int>> ans;
    int currentTime = 0;
    function<void(int)> dfs = [&](int u){
        dfn[u] = low[u] = currentTime++;
        for(int v : g[u]){
            if(dfn[v] == -1){ // 未访问的节点，搜索树中的边
                fa[v] = u;
                dfs(v);
                low[u] = min(low[u],low[v]); 
                // 字节点v无法不通过u-v边，追溯到u或者u以前的节点  
                if(dfn[u] < low[v]){
                    ans.push_back({u,v});
                }
            }else if(v != fa[u]){
                low[u] = min(low[u],dfn[v]);
            }
        }
    };
    for(int i=0;i<n;i++){
        if(dfn[i] == -1){
            dfs(i);
        }
    }
    return ans;
}


// 求无向图的割点
vector<int> criticalVetex(int n, vector<vector<int>>& connections) {
    // 建图
    vector<vector<int>> g(n);
    for(auto & c : connections){
        g[c[0]].push_back(c[1]);
        g[c[1]].push_back(c[0]);
    }

    vector<int> dfn(n,-1); // 搜索树的时间戳
    vector<int> low(n); // 不经过父节点能追溯到的最早节点
    vector<int> pa(n);
    vector<int> ans;

    int currentTime = 0;
    function<void(int)> dfs = [&](int u){
        dfn[u] = low[u] = currentTime++;
        int children = 0;
        for(int v : g[u]){
            if(dfn[v] == -1){ // 未访问的节点，搜索树中的边
                children++;
                pa[v] = u;
                dfs(v);
                low[u] = min(low[u],low[v]); 

                if(pa[u] == -1 && children > 1){
                    ans.push_back(u);
                }
                // 字节点v无法不通过u-v边，追溯到u或者u以前的节点  
                if(pa[u] != -1 && dfn[u] <= low[v]){
                    ans.push_back(u);
                }
            }else if(v != pa[u]){
                low[u] = min(low[u],dfn[v]);
            }
        }
    };
    for(int i=0;i<n;i++){
        if(dfn[i] == -1){
            dfs(i);
        }
    }
    return ans;
}






