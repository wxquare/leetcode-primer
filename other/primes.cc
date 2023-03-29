
#include <vector>
using namespace std;


bool isPrime(int n){
    if(n < 2) return false;
    for(int i=2;i*i<=n;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

/*
    埃氏筛法求素数
    求[1,n] 之间包含哪些素数
*/
vector<int> getPrimes(int n){
    vector<bool> isPrimes(n+1,true);
    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(isPrimes[i]){
            primes.push_back(i);
            for(int j=i*i;j<=n;j+=i){
                isPrimes[j] = false;
            }
        }
    }
    return primes;
}   

/*
    1. 1 - n 之间每个数包含哪些素数
    2. n表示上限
*/
vector<vector<int>> getSomePrimes(int n){
    vector<vector<int>> primes(n+1);
    for(int i=2;i<=n;i++){
        if(primes[i].empty()){
            for(int j=i;j<n;j+=i){
                primes[i].push_back(i);
            }
        }
    }
    return primes;
}


vector<int> getCommonPrimes(vector<int>& nums){
    int n = *max_element(nums.begin(),nums.end());
    vector<int> primes = getPrimes(n);  
    vector<int> ans;
    for(auto p : primes){
        bool f = true;
        for(int num : nums){
            if(num % f){
                f = false;
            }
        }
        if(f) ans.push_back(p);
    }
    return ans;
}

/*

    对于 C++14，我们可以使用自带的 __gcd(a,b) 函数来求最大公约数。
    而对于 C++ 17，我们可以使用 <numeric> 头中的 std::gcd 与 std::lcm 来求最大公约数和最小公倍数。
    1. 最大公约数 (Greatest Common Divisor),Least Common Multiple, LCM
    2. O(log min(a, b))
*/
int gcd(int x,int y){
    if(y == 0) return x;
    return gcd(y,x % y);
}

int lcm(int x,int y){
    return x / gcd(x,y) * y;
}

int gcdMultiple(vector<int>& nums){
    int res = nums[0];
    for(int i=1;i<nums.size();i++){
        res = gcd(res,nums[i]);
    }
    return res;
}

int lcmMultiple(vector<int>& nums){
    // 注意可能超过数的表示范围
    int m = gcdMultiple(nums);
    int res = 1;
    for(int i=0;i<nums.size();i++){
        res = nums[i] / m * res;
    }
    return res * m;
}

