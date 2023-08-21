#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
    int calc(int high,int k){
        string s = to_string(high);
        int n = s.length();

        int memo[n][2*n+1][k]; // n,diff,r
        memset(memo,-1,sizeof(memo));
        function<int(int,int,int,bool,bool)> dfs = [&](int i,int diff,int r,bool is_limit,bool is_num) -> int {
            if(i == n){
                return is_num && diff == n && r == 0;
            }
            if(!is_limit && memo[i][diff][r] != -1) return memo[i][diff][r];

            int ans = 0;
            if(!is_num) ans = ans + dfs(i+1,diff,r,false,false);
            int up = is_limit ? s[i] - '0' : 9;
            for(int d=1-is_num;d<=up;d++){
                ans = ans + dfs(i+1,diff+2*(d%2)-1,(r*10+d)%k,is_limit && d == up,true);
            }
            if(!is_limit) memo[i][diff][r] = ans;
            return ans;
        };
        return dfs(0,n,0,true,false);

    }
    int numberOfBeautifulIntegers(int high,int low,int k){
        return calc(high,k) - calc(low-1,k);
    }
};

int main(){
    std::cout << Solution().numberOfBeautifulIntegers(10000,100,7) << std::endl;
}