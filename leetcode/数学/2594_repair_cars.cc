class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = 1e17;

        function<bool(long long)> check = [&](long long x){
            int sum = 0;
            for(int i=0;i<ranks.size();i++){
                sum += int(sqrt(x / ranks[i]));
                if(sum >= cars) return true;
            }
            return false;
        };

        long long ans = right;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(check(mid)){
                ans = min(ans,mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;   
    }
};