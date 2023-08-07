#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
    int maximumSafenessFactor(vector<vector<int>>& grid){
        int n = grid.size();
        bool ban[n][n];
        bool vis[n][n];

        function<bool(int)> check = [&](int x)->bool {
            memset(ban,false,sizeof(ban));
            queue<pair<int,int>> q;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    q.push({i,j});
                    ban[i][j] = true;
                }
            }
            while(!q.empty() && x--> 0){
                int size = q.size();
                for(int i=0;i<size;i++){
                    int j = q.front().first;
                    int k = q.front().second;
                    q.pop();
                    for(auto d : dirs){
                        int nj = j + d[0];
                        int nk = j + d[1];
                        if(nj < 0 || nj >= n || nk < 0 || nj >=n) continue;
                        if(ban[nj][nk] == true) continue;
                        q.push({nj,nk});
                        ban[nj][nk] = true;
                    }
                }
            }
            memset(vis,false,sizeof(vis));
            function<bool(int,int)> dfs = [&](int i,int j)->bool {
                if(ban[i][j]) return false;
                if(i == n-1 && j == n-1) return true;
                vis[i][j] = true;
                for(auto d : dirs){
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if(ni < 0 || ni >= n || nj < 0 || nj >=n) continue;
                    if(vis[ni][nj]) continue;
                    if(ban[ni][nj]) continue;
                    if(dfs(ni,nj)) return true; 
                }
                return false;
            };
            return dfs(0,0);
        };
        int left = 1,right = n,ans = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid)){
                ans = max(ans,mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}