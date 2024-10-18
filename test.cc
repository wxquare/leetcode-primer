#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        /*

                vbcca

                abc

        */
        unordered_map<char,vector<int>> m;
        for(int i=0;i<word1.size();i++){
            m[word1[i]].push_back(i);
        }
        vector<int> pos(26,0);


        int n = word2.size();
        vector<vector<int>> dp(n,vector<int>(2,INT_MAX));


        if(m.count(word2[0])){
            dp[0][0] = m[word2[0]][0];
            pos[word2[0] - 'a']++;
        } else {
            dp[0][0] = word1.size();
        }
        dp[0][1] = 0;

        std::cout << "=====" << dp[0][0] << '\t' << dp[0][1] << std::endl;
        for(int i=1;i<word2.size();i++){
            if(dp[i-1][0] == word1.size()){
                dp[i][0] = word1.size();
            } else {
                // dp[i][0] 
                char pre = word2[i-1];
                char c = word2[i];
                for(int p = pos[c - 'a'];p < m[c].size();p++){
                    if(m[c][p] <= dp[i-1][0]){
                        continue;
                    } else {
                        dp[i][0] = p;
                        pos[c - 'a'] = p + 1;
                    }
                }
                if(dp[i][0] == INT_MAX){
                    dp[i][0] = n;
                }
            }

            if(dp[i-1][0] != word1.size()){
                dp[i][1] = dp[i-1][0] + 1;
            } else {
                char c = word2[i];
                for(int p = pos[c - 'a'];p < m[c].size();p++){
                    if(m[c][p] <= dp[i-1][1]){
                        continue;
                    } else {
                        dp[i][1] = p;
                        pos[c] = p + 1;
                    }
                }
                if(dp[i][1] == INT_MAX){
                    return {};
                }
            }
            std::cout << "====" << i << std::endl;
            std::cout << dp[i][0] << '\t' << dp[i][1] << std::endl;
        }

        std::cout << dp[n-1][0] << '\t' << dp[n-1][1] << std::endl;

        bool replace = false;
        vector<int> ans;
        for(int i=word2.size()-1;i--;i>=0){
            if(replace){
                ans.push_back(dp[i][0]);
                continue;
            }
            int j = min(dp[i][0],dp[i][1]);
            ans.push_back(j);
            if(word1[j] != word2[i]){
                replace = true;
            } 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    string word1 = "vbcca";
    string word2 = "abc";
    Solution().validSequence(word1,word2);
}