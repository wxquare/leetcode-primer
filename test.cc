const int MOD = 1e9 + 7;

class Solution {
public:

    int numberOfStableArrays(int zero, int one, int limit) {

        int memo[zero+1][one+1][2*limit+1];
        memset(memo,-1,sizeof(memo));

        function<int(int,int,int)> dfs = [&](int z,int o,int l)->int{
            if(z == 0 && o == 0){
                return 1;
            }

            if(memo[z][o][l] != -1){
                return memo[z][o][l];
            }

            long long res = 0;
            // 取1
            if(o > 0 && l + 1 <= 2*limit){
                if(l < limit){
                    res += dfs(z,o-1,limit+1);
                } else {
                    res += dfs(z,o-1,l + 1);
                }
            }

            if(z > 0 && l - 1 >= 0){
                if(l < limit){
                    res += dfs(z-1,o,l-1);
                } else {
                    res += dfs(z-1,o,limit - 1);
                }
            }
            memo[z][o][l] = res % MOD;
            return memo[z][o][l];
        };

        return dfs(zero,one,limit);
    }
};