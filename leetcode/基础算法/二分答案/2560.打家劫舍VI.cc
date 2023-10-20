class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        /*
            从数组中选择k个数，满足不相邻，求最大值最小的情况
            二分
        */
        int n = nums.size();
        function<bool(int)> check = [&](int x){
            int f0 = 0; // 没选前一个
            int f1 = 0; // 选了前一个
            int t;
            for(int i=0;i<n;i++){
                if(nums[i] > x) {
                    f0 = max(f0,f1);
                    f1 = max(f0,f1);
                    continue;
                }
                t = f1;
                f1 = f0 + 1;
                if(f1 >=k) return true;
                f0 = max(f0,t);
            }
            return false;
        };

        int low = 1, high = *max_element(nums.begin(),nums.end());

        int ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(mid)){
                ans = min(ans,mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};