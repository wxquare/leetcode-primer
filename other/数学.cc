#include <vector>
using namespace std;


// 判断一个数是否是否为素数/质数
bool isPrime(int x){
    if(x < 2) return false;
    for(int i=2;i*i<=x;i++){
        if(x % 2 == 0){
            return false;
        }
    }
    return true;
}

// 求1-n之间的所有素数
vector<int> getPrimes(int n){
    vector<int> isPrime(n+1,true);
    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j=2*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
    return primes;
}


// 求解1- MX之间有哪些素数
const int MX = 10000;
vector<int> primes;
int init = [&](){
    vector<int> isPrime(MX+1,true);
    for(int i=2;i<=MX;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j=2*i;j<=MX;j+=i){
                isPrime[j] = false;
            }
        }
    }
    return 0;
}();


// 计算某个数有哪些质因子
vector<int> getFactors(int x){
    vector<int> ans;
    for(int i=2;i*i<=x;i++){
        if((x % i) == 0){
            ans.push_back(i);
            ans.push_back(x / i);
        }
    }
    return ans;
}


// 计算一些数的公共质因子
vector<int> getCommonFactor(vector<int>& nums){
    int mn = *min_element(nums.begin(),nums.end());
    vector<int> ans;
    vector<int> primes = getPrimes(mn);
    for(int p : primes){
        int flag = true;
        for(int num : nums){
            if(num % p != 0){
                flag = false;
                break;
            }
        }
        if(flag) ans.push_back(p);
    }
    return ans;
}


// 最大公约数
int gcd(int a,int b){
    return b == 0 ? a : gcd(b,a%b);
}

// 最小公倍数
int lcm(int a,int b){
    return a * b / gcd(a,b);
}


// 扩展欧基里德算法
// 乘法逆元
// gcd(a,b) = 1，可以求得乘法逆元
int exgcd(int a,int b,int &x,int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b,a%b,x,y);
    int t = y;
    y = x - (a/b)*y;
    x = y;
    return r;
}

// 根据 费马小定理，快速幂
// 如果 MOD 是一个素数，且 a 是不可被 MOD 整除的整数，
const int MOD = 1e9 + 7;  
int combination_mod(long long n,long long k){
    long long numerator = 1;
    long long denominator = 1;

    for(long long i=0;i<k;i++){
        numerator = numerator * (n - i) % MOD;
        denominator = denominator * (i+1) % MOD;
    }
    return numerator * pow_mod(denominator,MOD-2) % MOD;
}

// 快速幂
int pow_mod(int x, long long e){
    int e = e % MOD;
    
    long long ans = 1;
    while(e){
        if((e & 1) != 0){
            ans = ans * e % MOD;
        }
        x = x * x % MOD;
        e = e / 2;
    }
    return ans;
}


// 如果mod为素数，且y不能为MOD整除
int division_MOD(long long x,long long y){
    return x * pow_mod(y,MOD-2) % MOD;
}

// 拒绝采样
// 用rand7(),实现rand10()
// rand7 产生1-7的随机数
int rejectSampling(){
    int ans;
    while(1){
        int x = (rand7()-1) * 7 + (rand7() - 1);
        if(x >= 40) continue;
        ans = x % 10 + 1;
    }
    return ans;
}

// 水塘抽样
vector<int> reservoirSampling(vector<int>& nums,int k){
    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        if(i < k){
            ans.push_back(nums[i]);
        } else {
            int j = rand() % i;
            if(j < k) ans[j] = nums[i];
        }
    }
    return ans;
}

// 洗牌算法
void shuffle(vector<int>& cards){
    for(int i=0;i<cards.size();i++){
        int j = rand() % i;
        swap(cards[i],cards[j]);
    }
}