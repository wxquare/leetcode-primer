class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumDistance(vector<int>& nums, string s, int d) { 
        int n = nums.size();
        long long a[n];
        for(int i=0;i<nums.size();i++){
            a[i] = nums[i] + 1LL * d * (s[i] == 'L' ? -1 : 1);
        }
        sort(a,a+n);
        long long sum = 0;
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans + i * a[i] - sum) % MOD;
            sum += a[i];
        }
        return ans;
    }
};