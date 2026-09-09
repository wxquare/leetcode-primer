#include <vector>
using namespace std;

class Solution{
public:
    int maxSum(vector<int>& nums){
        vector<int> m(10,-1);
        int ans = 0;
        for(int & num : nums){
            int k = 0;
            int t = num;
            while(t > 0){
                k = max(k,t % 10);
                t = t / 10;
            }
            if(m[k] > 0){
                ans = max(ans,m[k]+num);
                m[k] = max(m[k],num);
            }
        }
        return ans;
    }
};