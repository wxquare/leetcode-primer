class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            子问题，从0到i最大的金额
        */
        // x 表示不选 i,y 表示选 i
        int x = 0, y = 0;
        int t;// 临时变量，用于存储前一次不选i地最大金额
        for(int i=0;i<nums.size();i++){
            t = x;
            x = max(x,y);
            y = t + nums[i];
        }
        return max(x,y);
    }
};