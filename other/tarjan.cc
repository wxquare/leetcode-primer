#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


/*
    1. 求有向图的强连通分量
    2. stack<int> st;
*/
vector<vector<int>> tarjan(vector<vector<int>>& edges,int n){
    vector<int> dfn(n);
    vector<int> low(n);

    vector<bool> vis(n,false);
    stack<int> st;
    int sccCnt = 0; // 连通分量的数量
    vector<int> scc(n,0);

    unordered_map<int,vector<int>> g;
    for(auto e : edges){
        g[e[0]].push_back(e[1]);
    }
    int time = 0;


    function<void(int)> dfs;
    dfs = [&](int u){
        std::cout << "u  " << u << std::endl;
        dfn[u] = low[u] = ++time;
        st.push(u);
        vis[u] = true;
        for(int v : g[u]){
            std::cout << u << '\t' << v << std::endl;
            if(!dfn[v]){
                dfs(v);
                low[u] = min(low[u],low[v]);
            } else if(vis[v]) {
                low[u] = min(low[u],dfn[v]);  // 区别是什么
            }
        }
        if(dfn[u] == low[u]){
            std::cout << "=========" << std::endl;
            sccCnt++;
            while (true) {
                int v = st.top();
                st.pop();
                vis[v] = false;
                scc[v] = sccCnt;  // 节点属于第几个连通分量
                if (u == v) {
                    break;
                }
            }
        }
    };

    for(int i=1;i<=n;i++){
        if(dfn[i] == 0){
            dfs(i);
        }
    }

    vector<vector<int>> ans(sccCnt);
    for(int i=1;i<=n;i++){
        ans[scc[i]].push_back(i);
    }
    return ans;
}


int main() {
    vector<vector<int>> edges = {{1,3},{1,2},{2,4},{3,4},{3,5},{4,6},{5,6}};
    tarjan(edges,7);
    return 0;
}
