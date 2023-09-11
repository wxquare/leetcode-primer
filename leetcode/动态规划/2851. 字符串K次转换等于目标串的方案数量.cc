const int MOD = 1e9 + 7;

class Solution {
public:
    // 求pattern在text中出现的次数
    int kmp(string text,string pattern){
        int n = pattern.length();
        vector<int> lps(n,0); // longest common prefix and suffix
        
        //双指针求lps
        int len = 0;
        for(int i=1;i<pattern.length();){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len > 0){
                    len = lps[len-1];
                } else {
                    i++;
                }
            }
        }

        int ans = 0;
        int j = 0;
        for(int i=0;i<text.length();){
            if(text[i] == pattern[j]){
                i++;
                j++;
            } else {
                if(j > 0){
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
            if(j == pattern.length()){
                ans++;
                // 特别注意
                // i++; // 前面已经加过1了，这里不能再加了
                j = lps[j-1];
            }
        }
        return ans;
    }

    vector<vector<long long>> matrixMultiply(vector<vector<long long>>& m1,vector<vector<long long>>& m2){
        int r = m1.size();
        int c = m2[0].size();
        vector<vector<long long>> ans(r,vector<long long>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int k=0;k<m1[0].size();k++){
                    ans[i][j] = (ans[i][j] + m1[i][k] * m2[k][j]) % MOD;
                }
            }
        } 
        return ans;
    }
    
    vector<vector<long long>> pow(vector<vector<long long>> m,long long k){
        vector<vector<long long>> ans = {{1,0},{0,1}};

        for(;k>0;k/=2){
            if(k % 2 == 1){
                ans = matrixMultiply(ans,m);
            }
            m = matrixMultiply(m,m);
        }
        return ans;
    }

    int numberOfWays(string s, string t, long long k) {
        int n = s.length();
        int c = kmp(s+s.substr(0,n-1),t);

        /*
            dp[i][0] = dp[i-1][0] * (c - 1) + dp[i-1][1] * c
            dp[i][1] = dp[i-1][0] * (n - c) + dp[i-1][1] * (n - c - 1)

            dp[0][0] = (s == t);
            dp[0][1] = (s != t);
        */

        vector<vector<long long>> m = {
            {c-1,c},
            {n-c,n-c-1},
        };
        m = pow(m,k);
        // dp[0][0] = s==t
        return m[0][0] * (s == t) + m[0][1] * (s != t);
    }
};