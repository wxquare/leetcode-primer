const int MOD = 1e9 + 7;
const int MX = 1e5 + 1;
// 预处理
vector<int> primes;
int init = [](){
    primes = vector<int>(MX,0);
    for (int i = 2; i < MX; i++){
        if (primes[i] == 0) // i 是质数
            for (int j = i; j < MX; j += i)
                primes[j]++; // i 是 j 的一个质因子
    }
    return 0;
}();

class Solution{
public:
    long long pow(long long x, int n) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) res = res * x % MOD;
            x = x * x % MOD;
        }
        return res;
    }



    int maximumScore(vector<int>& nums,int k){
        int n = nums.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int> st; // 单调递减栈，下标
        for(int i=0;i<n;i++){
            while(!st.empty() && primes[nums[st.top()]] < primes[nums[i]]){
                right[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }

        vector<int> ids(n);
        iota(ids.begin(),ids.end(),0);

        sort(ids.begin(),ids.end(),[&](int i,int j){
            return nums[i] > nums[j];
        });

        long long ans = 1;
        for(int id : ids){
            long long total = 1LL * (id - left[id]) * (right[id] - id);
            if(total >= k){
                ans = ans * pow(nums[id],k) % MOD;
                break;
            }
            ans  = ans * pow(nums[id],total) % MOD;
            k -=total;
        }
        return ans;
    }
};
