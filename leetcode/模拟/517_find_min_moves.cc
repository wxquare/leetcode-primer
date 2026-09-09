class Solution {
public:
    int findMinMoves(vector<int>& machines) {

        int sum = accumulate(machines.begin(),machines.end(),0);
        int n = machines.size();
        if((sum % n) != 0) return -1;

        int avg = sum / n;

        int ans = 0;
        sum = 0;
        for(int i=0;i<n;i++){
            sum += machines[i] -avg;
            ans = max(ans,max(abs(sum),machines[i] -avg));
        }
        return ans;
    }
};