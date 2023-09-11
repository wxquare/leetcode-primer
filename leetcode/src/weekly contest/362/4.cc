#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
class Solution{
public:
    int solution(string& s,string& t,long long k){
        /*
            1. 方案数
            dp[i][0] = dp[i-1][0] * (c-1) + dp[i-1][1] * c    // 经过i步转化成t的方案数
            dp[i][1] = dp[i-1][0] * (n - c) + dp[i-1][1] * (n- c - 1) // 经过i步无法转发成t的方案数
            dp[0][0] = s==t;
            dp[0][1] = s!=t;
        */
        int n = s.length();
        int c = kmp(s+s.substr(0,n-1),t);
        vector<vector<long long>> m = {
            {c-1,c},
            {n-c,n-c-1}
        };
        m = pow(m,k);
        return (m[0][0]*(s==t) + m[0][1])*(s!=t) % MOD;
    }

    // 矩阵乘法运算
    vector<vector<long long>> matrixMultiply(vector<vector<long long>>& m1,vector<vector<long long>>& m2){
        int r = m1.size(),c = m2[0].size();
        vector<vector<long long>> ans(r,vector<long long>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                for(int k=0;k<m1[0].size();k++){
                    ans[i][j] = (ans[i][j] + m1[i][k] * m2[k][j]) % MOD;
                }
            }
        }
        return ans;
    }

    vector<vector<long long>> pow(vector<vector<long long>>& m,long long k){
        vector<vector<long long>> ans = {{1,0},{0,1}};
        for(long long i=k;i>0;i/=2){
            if(i % 2 == 1){
                i--;
                ans = matrixMultiply(ans,m);
            }
            m = matrixMultiply(m,m);
        }
        return ans;
    }
    // 双指针和lps,longest common prefix and suffix
    int kmp(string text,string pattern){
        int n = pattern.length();
        vector<int> lps(n);
        int len = 0;
        for(int i=1;i<pattern.length();){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len > 0){
                    len = lps[len];
                } else {
                    i++;
                }
            }
        }
        int p = 0;
        int ans = 0;
        for(int i=0;i<text.length();){
            if(text[i] == pattern[p]){
                p++;
                i++;
            } else {
                if(p > 0){
                    p = lps[p];
                } else {
                    i++;
                }
            }
            if(p == pattern.length()){
                ans++;
                p--;
            }
        }
        return ans;
    }
};