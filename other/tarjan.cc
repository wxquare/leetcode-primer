#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


/*
    1. 求有向图的强连通分量
    2. stack<int> st;


    1...n 个节点
*/
vector<vector<int>> tarjan(vector<vector<int>>& edges,int n){
    vector<int> dfn(n+1); // 深度优先搜索遍历时结点 u 被搜索的次序。
    vector<int> low(n+1); // 在 u 的子树中能够回溯到的最早的已经在栈中的结点

    // 存储dfs中遍历过的点
    stack<int> st;
    vector<bool> inst(n,false);

    int sccCnt = 0; // 连通分量的数量
    vector<int> scc(n,0); // 记录每个点属于第几个连通分量

    unordered_map<int,vector<int>> g;
    for(auto e : edges){
        g[e[0]].push_back(e[1]);
    }
    int time = 0;

    function<void(int)> dfs;
    dfs = [&](int u){
        dfn[u] = low[u] = ++time;
        st.push(u);
        inst[u] = true;
        for(int v : g[u]){
            if(!dfn[v]){
                dfs(v);
                low[u] = min(low[u],low[v]);
            } else if(inst[v]) {
                low[u] = min(low[u],dfn[v]);  // 区别是什么
            }
        }
        if(dfn[u] == low[u]){
            sccCnt++;
            while (true) {
                int v = st.top();
                st.pop();
                inst[v] = false;
                scc[v] = sccCnt;  // 节点属于第几个连通分量
                if (u == v) {
                    break;
                }
            }
        }
    };

    for(int i=1;i<n;i++){
        if(dfn[i] == 0){
            dfs(i);
        }
    }

    vector<vector<int>> ans(sccCnt);
    for(int i=1;i<n;i++){
        ans[scc[i]-1].push_back(i);
    }
    return ans;
}

int main() {
    vector<vector<int>> edges = {{1,3},{1,2},{2,4},{3,4},{5,3},{4,6},{6,5}};
    vector<vector<int>> sccs = tarjan(edges,7);
    for(auto sc : sccs){
        for(auto node : sc){
            std::cout << node << '\t';
        }
        std::cout << std::endl;
    }
    return 0;
}
