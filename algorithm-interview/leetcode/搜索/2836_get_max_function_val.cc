#include <vector>
using namespace std;

class Solution {
public:
    // 循环数组
    long long calc(vector<int>& arr,long long k){
        int n = arr.size();
        int a = k / n;
        int b = k % n;
        int curSum = 0;
        for(int i=0;i<b;i++){
            curSum += arr[i];
        }
        int maxSum = curSum;
        int j = b;
        for(int i=0;i<n;i++){
            curSum = curSum + arr[(j+1)%n] - arr[i];
            maxSum = max(curSum,maxSum);
        }
        return 1LL * a * n + maxSum;
    }

    long long getMaxFunctionVal(vector<int>& receiver,long long k){
        vector<vector<int>> groups;
        function<void(int,int)> dfs = [&](int i,int j){
            if(i == -1) return;
            groups[j].push_back(i);
            dfs(receiver[i],j);
            receiver[i] = -1;
        };

        int n = receiver.size();
        int j = 0;
        for(int i=0;i<n;i++){
            if(receiver[i]!= -1){
                groups.push_back(vector<int>());
                dfs(i,j);
            }
        }
        long long ans = 0;
        for(auto &  group : groups){
            ans = max(ans,calc(group,k));
        }
        return ans;
    }
};