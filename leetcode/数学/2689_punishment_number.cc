#include <string>
using namespace std;

bool check(int number){
    string s = to_string(number * number);
    function<bool(int,int)> dfs = [&](int i,int sum) -> bool {
        if(i == s.length()){
            return sum == number * number;
        }
        int x = 0;
        for(int j=i;j<s.length();j++){
            x = x * 10 + s[j] - '0';
            if(dfs(i+1,sum + x)){
                return true;
            }
        }
    };
    return dfs(0,0);
}

int preSum[1001];
int init = [](){
    for(int i=1;i<1001;i++){
        preSum[i] = preSum[i-1] + (check(i) ? i * i : 0);
    }
    return 0;
}();

class Solution{
public:
    int punishmentNumber(int n){
        return preSum[n];
    }
};