#include <vector>
#include <string>
#include <iostream>
using namespace std;


bool isPalindrome(string& s,int left,int right){
    while(left <= right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 回溯 + 保留路径
class Solution {
public:
    vector<vector<string>> partition(string s){
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;
        function<void(int)> dfs = [&](int i){
            if(i == n){
                ans.push_back(path); // 递归结束的标志
                return;
            }
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    path.push_back(s.substr(i,j-i+1));
                    dfs(j+1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s = "aaab";
    vector<vector<string>> ans = Solution().partition(s);
    for(auto as : ans){
        for(auto a : as){
            std::cout << a << '\t';
        }
        std::cout << std::endl;
    }
    return 0;
}
