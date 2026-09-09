class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> p(n);
        function<bool(int,int)> check = [&](int x,int y)->bool {
            for(int i=0;i<x;i++){
                if(p[i] == y) return false;
                if(p[i] - i == y - x) return false;
                if(p[i] + i == y + x) return false; 
            }
            return true;
        };
        vector<string> s(n,string(n,'.'));
        vector<vector<string>> ans;
        function<void(int)> dfs = [&](int x){
            if(x == n){
                ans.push_back(s);
                return;
            }
            for(int i=0;i<n;i++){
                if(check(x,i)){
                    p[x] = i;
                    s[x][i] = 'Q';
                    dfs(x+1);
                    p[x] = -1;
                    s[x][i] = '.';
                }
            }
        };
        dfs(0);
        return ans;
    }
};