class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        function<void(int,int)> dfs = [&](int p,int cur){
            if(p == 9){
                ans = min(ans,cur);
                return;
            }
            int x = p / 3;
            int y = p % 3;
            if(grid[x][y] > 0){
                dfs(p+1,cur);
                return;
            }

            for(int i=0;i<9;i++){
                int a = i / 3;
                int b = i % 3;
                if(grid[a][b] > 1){
                    grid[a][b]--;
                    dfs(p+1,cur + abs(a-x) + abs(b-y));
                    grid[a][b]++;
                }
            } 
        };
        dfs(0,0);
        return ans;
    }
};