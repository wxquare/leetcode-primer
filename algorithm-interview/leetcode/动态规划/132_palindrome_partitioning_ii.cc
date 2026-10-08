#include <string>
#include <iostream>
using namespace std;


bool isPalindrome(string& s,int left,int right){
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

class Solution{
public:
    /*
        1. 从i开始最少的次数
    */
    int minCut(string s){
        int n = s.length();
        int memo[n];
        memset(memo,-1,sizeof(memo));
        function<int(int)> dfs = [&](int i){
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = n;
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    ans = min(ans,1+dfs(j+1));
                }
            }
            memo[i] = ans;
            return ans;
        };
        return dfs(0) - 1;
    }
};

int main(int argc, char const *argv[])
{
    string s = "aaabaa";
    std::cout << Solution().minCut(s) << std::endl;
    return 0;
}
