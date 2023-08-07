#include <vector>
#include <numeric>
using namespace std;

class Solution{
public:
    int minimumTime(vector<int>& nums1,vector<int>& nums2,int x){
        int n = nums1.size();
        vector<int> ids(n);
        iota(ids.begin(),ids.end(),0);
        sort(ids.begin(),ids.end(),[&](int i,int j){
            return nums2[i] < nums2[j];
        });

        /*
            从n个数据选在k个数据
            dp[i][j],表示从前i个数据选择j个数据，减小量的最大值
        */
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]+nums1[ids[i-1]]+j*nums2[ids[i-1]]);
            }
        }
        int sum1 = accumulate(nums1.begin(),nums1.end(),0);
        int sum2 = accumulate(nums2.begin(),nums2.begin(),0);
        for(int i=0;i<n;i++){
            if(sum1 + i * sum2 - dp[n][i] <= x){
                return i;
            }
        }
        return -1;
    }
};