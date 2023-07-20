
#include <vector>
#include <random>
#include <iostream>
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



// 求一个范围内的prime number.
const int MX = 10000;
vector<int> primes;
int init = [](){
    vector<bool> isPrime(MX+1,true);
    for(int i=2;i<=MX;i++){
        if(isPrime[i]){
            primes.push_back(i);
            // j may out of bounds.
            for(long long j=i*i;j<=MX;j+=i){
                isPrime[j] = false;
            }
        }
    }
    return 0;
}();

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


    100 12
    12,100%12= 4;
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


// 水塘抽样
vector<int> reservoirSampling(vector<int>& data,int k){
    std::random_device rd;
    std::mt19937 gen(rd());
    int n = data.size();
    vector<int> reservoir;
    for(int i=0;i<n;i++){
        if(i < k){
            reservoir.push_back(data[i]);
        } else {
            // 生成一个0到i-1的随机数
            std::uniform_int_distribution<> dis(0, i);//[0,i]
            int j = dis(gen);
            if(j < k) reservoir[j] = data[i];
        }
    }
    return reservoir;
}

// 洗牌算法
void shuffle(vector<int>& nums){
    random_device rd;
    mt19937 gen(rd());
    int n = nums.size();
    for (int i = nums.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<> dis(0, i);
        int j = dis(gen);
        std::swap(nums[i], nums[j]);
    }
}


// 分解质因数
vector<int> primeFactorization(int n){
    vector<int> ans;
    for(int i=2;i*i<=n;i++){
        if((n  % i) == 0){
            ans.push_back(i);
            while(n % i == 0){
                n /= i;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> ans = primeFactorization(600);
    for(auto f : ans){
        std::cout << f << std::endl;
    }
}