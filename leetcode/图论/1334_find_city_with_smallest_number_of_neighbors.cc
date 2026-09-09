class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        for(auto e : edges){
            dis[e[0]][e[1]] = min(dis[e[0]][e[1]],e[2]);
            dis[e[1]][e[0]] = min(dis[e[1]][e[0]],e[2]);
        }
        for(int i=0;i<n;i++){
            dis[i][i] = 0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k] == INT_MAX || dis[k][j] == INT_MAX) continue;
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                }
            }
        }
        int mn = n;
        int ans;
        for(int i=0;i<n;i++){
            int t = 0;
            for(int j=0;j<n;j++){
                if(dis[i][j] <= distanceThreshold) t++;
            }
            if(t <= mn){
                mn = t;
                ans = i;
            }
        }
        return ans;
    }
};