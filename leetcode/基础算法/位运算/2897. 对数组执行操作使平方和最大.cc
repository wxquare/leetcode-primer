class Solution {
public:
    const int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> d(32,0);
        for(int num : nums){
            for(int i=0;i<31;i++){
                if((num & (1 <<i)) != 0){
                    d[i]++;
                }
            }
        }
        int t = 0;
        long long ans = 0;
        while(k > 0){
            t = 0;
            for(int i=0;i<32;i++){
                if(d[i] > 0){
                    d[i]--;
                    t = t + (1 << i);
                }
            }
            ans = (ans + 1LL * t * t) % MOD;
            k--;
        }
        return ans;  
    }
};