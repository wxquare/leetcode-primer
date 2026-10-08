#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    long long atMost(const vector<int>& a, int limit) {
        unordered_map<int, int> freq;
        long long total = 0;
        int left = 0;
        for (int right = 0; right < (int)a.size(); ++right) {
            ++freq[a[right]];
            while ((int)freq.size() > limit) {
                if (--freq[a[left]] == 0) freq.erase(a[left]);
                ++left;
            }
            total += right - left + 1;
        }
        return total;
    }

public:
    int medianOfUniquenessArray(vector<int>& nums) {
        long long need = (1LL * nums.size() * (nums.size() + 1) / 2 + 1) / 2;
        int l = 1, r = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (atMost(nums, m) >= need) r = m;
            else l = m + 1;
        }
        return l;
    }
};
