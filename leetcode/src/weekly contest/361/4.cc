#include <iostream>
#include <vector>
using namespace std;



class Solution{
public:
    vector<int> minOperationsQueries(int n,vector<vector<int>>& edges,vector<vector<int>>& queries){
        /*
            1. 建图
            2. dfs，存储节点的
                  depth
                  pa[i][j] 节点i的2^j祖先节点
                  cnt[i][j][w]
            3. query(x,y) = depth[x] + depth[y] - 2 * depth[lca] - max(cnt[x][lca][w]+cnt[y][local][w])
        */

        // 无向权重图
        vector<vector<vector<int>>> g(n);
        for(auto e : edges){
            int u = e[0],v = e[1], w = e[2];
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

        // 对于n个节点，最大倍增为
        int m = [&]()->int {
            for(int i=30;i>=0;i--){
                if(((1 << i) & n) > 0){
                    return i + 1;
                }
            }
            return 0;
        }();

        vector<int> depth(n);
        vector<vector<int>> pa(n,vector<int>(m,-1)); // 节点i的2^j的祖先节点
        int cnt[n][m][27]; // 节点i到2^j祖先节点路径上各权重值的数量
        memset(cnt,0,sizeof(cnt));
        function<void(int,int)> dfs = [&](int x,int fa){
            pa[x][0] = fa;
            for(auto yw : g[x]){
                int y = yw[0], w = yw[1];
                if(y != fa){
                    depth[y] = depth[x] + 1;
                    cnt[y][0][w] = 1;
                    dfs(y,x);
                }
            }
        };

        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(pa[j][i-1] != -1){
                    pa[j][i] = pa[pa[j][i-1]][i-1]; 
                    for(int k=1;k<=26;k++){
                        cnt[j][i][k] = cnt[j][i-1][k] + cnt[pa[j][i-1]][i-1][k];
                    }
                }
            }
        }
        vector<int> ans;
        
        for(auto & q : queries){
            int x = q[0], y = q[1];
            if(depth[x] > depth[y]) swap(x,y);
            vector<int> cw(27,0);
            for(int k=depth[y]-depth[x];k;k&=k-1){
                int j = __builtin_ctz(k);
                for(int w=1;w<=26;w++){
                    cw[w] += cnt[y][j][w];
                }
                y = pa[y][j];
            }
            for(int i=m-1;i>=0;i--){
                int px = pa[x][i],py = pa[y][i];
                if(px != py){
                    for(int w=1;w<=26;w++){
                        cw[w] += cnt[x][i][w] + cnt[y][i][w];
                    }
                    x = px;
                    y = py;
                }
            }
            int lca = x;
            int res = depth[x] + depth[y] - 2 * depth[lca] - *max_element(cw.begin(),cw.end());
            ans.push_back(res);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
