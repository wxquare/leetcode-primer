/*
    给定一个正整数 n ，请你统计在 [0, n] 范围的非负整数中，有多少个整数的二进制表示中不存在 连续的 1 。

    输入: n = 5
    输出: 5
    解释: 
    下面列出范围在 [0, 5] 的非负整数与其对应的二进制表示：
    0 : 0
    1 : 1
    2 : 10
    3 : 11
    4 : 100
    5 : 101
    其中，只有整数 3 违反规则（有两个连续的 1 ），其他 5 个满足规则。
*/

#include <string>
#include <iostream>
using namespace std;

string decimalToBinary(int x){
    if(x == 0) return "0";
    string b;
    while(x){
        b = to_string(x % 2) + b;
        x = x / 2;
    }
    return b;
}

class Solution {
public:
    int findIntegers(int n) {
        /*
            1. 直接求不连续比较简单
        */
        string s = "0"+decimalToBinary(n);
        int l = s.length();
        int memo[l][2];
        memset(memo,-1,sizeof(memo));
        function<int(int,int,bool)> dfs = [&](int i,int pre,int same){
            if(i == s.length()){
                return 1;
            }
            if(!same && memo[i][pre] != -1) return memo[i][pre];
            
            int res = 0;
            int up = same ? s[i] - '0' : 1;
            for(int d=0;d<=up;d++){
                if(d == 1 && pre == 1) {
                    continue;
                }
                res += dfs(i+1,d,same & (d == up));
            }
            if(!same) memo[i][pre] = res;
            return res;
        };
       return dfs(1,0,true);
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().findIntegers(5) << std::endl;
    return 0;
}
