#include <iostream>
#include <vector>
using namespace std;

// 节点数量为n
// 无向图
vector<int> lca(int n,vector<vector<int>>& edges,vector<vector<int>>& queries){
    // build graph
    vector<vector<int>> g(n);
    for(auto e : edges){
        int v = e[0],u = e[1];
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int m = 32 - __builtin_clz(n); // log2(n)
    // traverse
    vector<int> depth(n,0); // 每个点的深度

    vector<vector<int>> pa(n,vector<int>(m)); // 节点2^m次方的parent

    function<void(int,int)> dfs = [&](int u,int fa){
        // update pa 信息
        pa[u][0] = fa;
        for(int i=1;i<m;i++){
            if(pa[u][i-1] != -1){
                pa[u][i] = pa[pa[u][i-1]][i-1];
            }
        }
        for(int v : g[u]){
            if(v != fa){
                depth[v] = depth[u] + 1;
                dfs(v,u);
            }
        }
    };
    dfs(0,-1);

    function<int(int,int)> get_k_ancestor = [&](int x,int k) -> int {
        for(;k != 0; k&=(k-1)){
            x = pa[x][__builtin_ctz(k)];
        }
        return x;
    };

    function<int(int,int)> get_lca = [&](int x,int y) -> int {
        if(depth[x] < depth[y]){
            swap(x,y);
        }
        // x > y 深度高的先向上跳depth[x] - depth[y]
        x = get_k_ancestor(x,depth[x] - depth[y]);
        if(x == y) return x;
        for(int i = m - 1;i>=0;i--){
            if(pa[x][i] != -1 && pa[x][i] != pa[y][i]){
                x = pa[x][i];
                y = pa[y][i];
            }
        }
        return pa[x][0];
    };

    vector<int> ans;
    for(auto q : queries){
        ans.push_back(get_lca(q[0],q[1]));
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}



#include <iostream>
#include <vector>
using namespace std;

// 节点数量为n
// 无向图
vector<int> lca(int n,vector<vector<int>>& edges,vector<vector<int>>& queries){
    // build graph
    vector<vector<int>> g(n);
    for(auto e : edges){
        int v = e[0],u = e[1];
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int m = 32 - __builtin_clz(n); // log2(n)
    // traverse
    vector<int> depth(n,0); // 每个点的深度
    vector<vector<int>> pa(n,vector<int>(m)); // 节点2^m次方的parent
    int cnt[n][m][27];
    memset(cnt,0,sizeof(cnt))
    function<void(int,int)> dfs = [&](int u,int fa){
        // update pa 信息
        pa[u][0] = fa;
        for(int i=1;i<m;i++){
            if(pa[u][i-1] != -1){
                pa[u][i] = pa[pa[u][i-1]][i-1];
                for(int w=1;w<=26;w++){
                    cnt[u][i][w] = cnt[u][i-1][w] + cnt[pa[u][i-1]][i-1][w];
                }
            }
        }
        for(int v : g[u]){
            if(v != fa){
                depth[v] = depth[u] + 1;
                dfs(v,u);
            }
        }
    };
    dfs(0,-1);

    function<int(int,int)> get_k_ancestor = [&](int x,int k) -> int {
        for(;k != 0; k&=(k-1)){
            x = pa[x][__builtin_ctz(k)];
        }
        return x;
    };

    function<int(int,int)> get_lca = [&](int x,int y) -> int {
        if(depth[x] < depth[y]){
            swap(x,y);
        }
        // x > y 深度高的先向上跳depth[x] - depth[y]
        x = get_k_ancestor(x,depth[x] - depth[y]);
        if(x == y) return x;
        for(int i = m - 1;i>=0;i--){
            if(pa[x][i] != -1 && pa[x][i] != pa[y][i]){
                x = pa[x][i];
                y = pa[y][i];
            }
        }
        return pa[x][0];
    };

    vector<int> ans;
    for(auto q : queries){
        int x = q[0],int y = q[1];
        int ca = get_lca(x,y);
        


        ans.push_back(get_lca(q[0],q[1]));
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
