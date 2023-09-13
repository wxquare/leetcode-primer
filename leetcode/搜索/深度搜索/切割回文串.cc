class Solution {
public:
    vector<vector<string>> partition(string s) {

        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i] == s[j]){
                    dp[i][j] = j-1 > i+1 ? dp[i+1][j-1] : true;
                }
            }
        }
        vector<vector<string>> ans;
        vector<string> path;
        function<void(int,int)> dfs = [&](int start,int i){
            if(start >= n){
                ans.push_back(path);
                return;
            }
            if(i >=n) return;
            if(dp[start][i]){
                path.push_back(s.substr(start,i-start+1));
                dfs(i+1,i+1);
                path.pop_back();
            }
            dfs(start,i+1);
        };
        dfs(0,0);
        return ans;
    }
};