#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        //从i开始到n不包含重复数字
        int memo[n][1<<10];
        //从i开始到n包含重复数字
        memset(memo,-1,sizeof(memo));
        function<int(int,int,bool)> dfs = [&](int i,int mask,bool is_limit){
            if(i == s.length()){
                return 1;
            }
            if(!is_limit && memo[i][mask] != -1){
                std::cout << "====" << std::endl;
                return memo[i][mask];
            }

            int res = 0;
            int up = is_limit ? s[i] - '0' : 9;
            for(int d=0;d<=up;d++){
                if(mask & (1 << d)) continue;
                int m = (mask == 0 && d == 0) ? mask : (mask | (1<<d));
                res = res + dfs(i+1,m,is_limit && d==up);
            }
            if(!is_limit) {
                std::cout << "====31 " << i << '\t' << mask << std::endl;
                memo[i][mask] = res;
            }
            return res;
        };
        return n - dfs(0,0,true) +1;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().numDupDigitsAtMostN(37) << std::endl;
    return 0;
}
