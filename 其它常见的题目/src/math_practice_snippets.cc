#include <vector>
using namespace std;

bool isPrime(int x){
    if(x < 2) return false;
    for(int i=2;i*i<=x;i++){
        if(x % 2 == 0){
            return false;
        }
    }
    return true;
}


// 求1-MX之间存在哪些质数
vector<int> primes;
const int MX = 10000;
int init = [](){
    vector<bool> is_prime(MX+1,true);
    for(int i=2;i<=MX;i++){
        primes.push_back(i);
        for(int j=2*i;j<=MX;j+=i){
            is_prime[j] = false;
        }
    }
    return 0;
}();

// 求一个数有哪些因子，哪些质因子


// 最大公约数
int gcd(int x,int y){
    return y == 0 ? x : gcd(y,x % y);
}

int lcm(int x,int y){
    return x * y / gcd(x,y);
}


int quick_pow(int x,int e){
    int ans = 1;
    while(e){
        if(e % 2 == 1){
            ans = ans * x;
        } else {
            x = x * x;
            e = e / 2;
        }
    }
    return ans;
}


// 拒绝采样
class Solution {
public:
    int rand10() {
        while(1){
            int x = (rand7() - 1) * 7 + rand7();
            if(x <= 40){
                return x % 10 +1;
            }
        }
        return 0;
    }
};


vector<int> reservoirSampling(vector<int> &nums,int k){
    int n = nums.size();
    vector<int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(ans[i]);
    }
    for(int i=k;i<n;i++){
        int a = rand() % (i + 1);
        if(a < k){
            ans[a] = ans[i];
        } 
    }
}