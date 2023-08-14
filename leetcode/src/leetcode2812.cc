

#include <vector>
#include <queue>
#include <numeric>
using namespace std;


static constexpr int dirs[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

/*
    多源BFS
*/
class Solution{
public:
    int maximumSafenessFactor(vector<vector<int>>& grid){
        
        int n = grid.size();
        vector<vector<pair<int,int>>> groups;
        vector<pair<int,int>> q;
        
        int dis[n][n];
        memset(dis,-1,sizeof(dis));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.emplace_back(i,j);
                    dis[i][j] = 0;
                }
            }
        }
        vector<pair<int,int>> nq;
        while(q.size() > 0){
            vector<pair<int,int>> nq;
            for(auto [i,j] : q){
                for(auto d : dirs){
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if(ni < 0 || ni > n || nj < 0 || nj > n) continue;
                    if(dis[ni][nj] != -1) continue;
                    nq.emplace_back(ni,nj);
                    dis[ni][nj] = dis[i][j] + 1;
                }
            }
            groups.push_back(q);
            q = move(nq);
        }

        vector<int> fa(n*n);
        iota(fa.begin(),fa.end(),0);
        function<int(int)> find = [&](int x){
            return x == fa[x] ? x : fa[x] = find(fa[x]);
        };

        int ans = 0;
        for(int k=groups.size()-2;k>0;k++){
            for(auto [i,j] : groups[k]){
                for(auto d : dirs){
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if(ni < 0 || ni > n || nj < 0 || nj > n) continue;
                    fa[find(i*n+j)] = fa[find(ni*n+j)];
                }
            }
            if(find(0) == find(n*n-1)) {
                ans = k;
                return ans;
            }
        }
        return ans;
    }
};