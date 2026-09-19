const vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {  
        vector<vector<bool>> g(8,vector<bool>(8,false));
        for(auto q : queens){
            g[q[0]][q[1]] = true;
        }
        vector<bool> exist(8,0);
        vector<vector<int>> ans;
        int x = king[0],y = king[1];
        for(int i=1;i<8;i++){
            for(int j=0;j<8;j++){
                if(exist[j]) continue;
                int nx = x + dirs[j][0] * i;
                int ny = y + dirs[j][1] * i;
                if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
                if(g[nx][ny]){
                    ans.push_back({nx,ny});
                    exist[j] = true;
                }
            }
        }
        return ans;
    }
};