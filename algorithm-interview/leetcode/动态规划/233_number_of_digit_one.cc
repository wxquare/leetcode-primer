#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.length();
        // 从高位到地位遍历，从i位到结束包含1的个数
        int memo[m][m];
        memset(memo,-1,sizeof(memo));
        function<int(int,int,bool)> dfs = [&](int i,int cnt,bool same){
            if(i == s.length()){
                return cnt;
            }
            if(!same && memo[i][cnt] != -1){
                return memo[i][cnt];
            }
            int res = 0;
            int up = same ? s[i] - '0' : 9;
            for(int d=0;d<=up;d++){
                res += dfs(i+1,cnt + (d == 1),same && d == up);
            }
            if(!same){
                memo[i][cnt] = res;
            }
            return res;
        };
        return dfs(0,0,true);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    std::cout << Solution().countDigitOne(20) << std::endl;
    return 0;
}
