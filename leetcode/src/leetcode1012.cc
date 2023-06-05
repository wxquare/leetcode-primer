#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);

        //从i开始到n不包含重复数字
        int memo[s.length()][1<<10][2];
        //从i开始到n包含重复数字
        memset(memo,-1,sizeof(memo));
        function<int(int,int,bool)> dfs = [&](int i,int mask,int same){
            if(i == s.length()){
                return 1;
            }
            if(memo[i][mask][same] != -1){
                return memo[i][mask][same];
            }
            int res = 0;
            int up = same ? s[i] - '0' : 9;
            for(int d=0;d<=up;d++){
                if(mask & (1 << d)) continue;
                int m = (mask == 0 && d == 0) ? mask : (mask | (1<<d));
                res = res + dfs(i+1,m,same && d==up);
            }
            memo[i][mask][same] = res;
            return res;
        };
        return n - dfs(0,0,true) +1;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().numDupDigitsAtMostN(1000) << std::endl;
    return 0;
}
