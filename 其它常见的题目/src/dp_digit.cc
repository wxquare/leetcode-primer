/*
    1. 通常用于求解整数计数问题
    2. 前导零
*/


#include <string>
using namespace std;
class Solution{
public:
    int calc(string& s){
        int n = s.length();
        int memo[n][10];
        memset(memo,-1,sizeof(memo));
        function<int(int,int,bool,bool)> dfs = [&](int i,int pre,bool is_limit,bool is_num)->int {
            if(i == n) return is_num;
            if(is_num && !is_limit && memo[i][pre]!=-1) return memo[i][pre];
            int ans = 0;
            if(i!s_num) ans = (ans + dfs(i+1,pre,false,false)) % MOD;
            int up = is_limit ? s[i] - '0' : 9;
            for(int d=1-is_num;d<=up;d++){
                ans = (ans + dfs(i+1,d,is_limit && d == up,true)) % MOD;
            }
            if(!is_limit && is_num) memo[i][pre] = ans;
            return ans;
        };
        return dfs(0,0,true,false);
    }

    bool valid(string s){
        for(int i=1;i<s.length();i++){
        }
    }
    int countSteppingNumbers(string low,string high){

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
