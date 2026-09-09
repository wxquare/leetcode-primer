#include <vector>
#include <stack>
using namespace std;


const int MX = 1e5 + 1;
const int MOD = 1e9 + 7;

// 预处理
vector<int> primes;
int init = [](){
    primes = vector<int>(MX);
    for(int i=2;i<MX;i++){
        if(primes[i] == 0){
            for(int j=i;j<MX;j+=i){
                primes[j]++;
            }
        }
    }
    return 0;
}();

class Solution{
public:

    long long pow(int b,int e){
        long long ans = 1;
        while(e){
            if(e % 2 ==1){
                ans = ans * b % MOD;
            }
            b = (1LL * b * b) % MOD;
            b = b / 2;
        }
        return (ans * b) % MOD;
    }


    int maximumScore(vector<int>& nums,int k){

        stack<int> st; // 单调栈找到左边比它大的下标
        int n = nums.size();
        vector<int> left(n,-1);
        vector<int> right(n,n);

        for(int i=0;i<n;i++){
            int cnt = primes[nums[i]];
            while(!st.empty() && primes[nums[st.top()]] < primes[nums[i]]){
                right[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }

        vector<int> ids(n,0);
        sort(ids.begin(),ids.end(),[&](int i,int j){
            return nums[i] > nums[j];
        });

        int ans = 1;
        for(int i : ids){
            long long total = 1LL * (i - left[i]) * (right[i] - i);
            if(k <= total){
                ans = 1LL * ans * pow(nums[i],k) % MOD;
                break;
            }
            ans = 1LL * ans * pow(nums[i],total) % MOD;
            k -= total;
        }
        return ans;
    }
};
