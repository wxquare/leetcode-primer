#include <cstring>
#include <string>
using namespace std;

class Solution {
    string digits;
    long long memo[17][289];

    long long dfs(int position, int difference, bool limited) {
        if (position == static_cast<int>(digits.size())) {
            return difference == 0 ? 1 : 0;
        }
        long long& cached = memo[position][difference + 144];
        if (!limited && cached != -1) return cached;

        int upper = limited ? digits[position] - '0' : 9;
        long long result = 0;
        for (int digit = 0; digit <= upper; ++digit) {
            int nextDifference = difference +
                (position % 2 == 0 ? digit : -digit);
            result += dfs(position + 1, nextDifference,
                          limited && digit == upper);
        }
        if (!limited) cached = result;
        return result;
    }

    long long countUpTo(long long value) {
        if (value < 11) return 0;
        digits = to_string(value);
        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, true) - 1;
    }

public:
    long long countBalanced(long long low, long long high) {
        return countUpTo(high) - countUpTo(low - 1);
    }
};
