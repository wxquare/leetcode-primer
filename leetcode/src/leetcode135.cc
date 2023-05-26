#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool isPalindrome(string& s,int left,int right){
    int l = left,r = right;
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

class Solution {
public:
    vector<vector<string>> partition(string s){
        vector<vector<string>> ans;
        int n = s.length();
        vector<string> path;
        function<void(int)> dfs = [&](int i){
            if(i == n) {
                ans.push_back(path);
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

int main(){
    vector<vector<string>> ans = Solution().partition("aab");
    for(auto m : ans){
        for(auto s : m){
            std::cout << s << ",";
        }
        std::cout << '\n';
    }
    return 0;
}