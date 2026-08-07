#include <algorithm>
#include <vector>

class SparseTableMin {
public:
    explicit SparseTableMin(const std::vector<int>& values) {
        int n = values.size(); log.assign(n + 1, 0);
        for (int i = 2; i <= n; ++i) log[i] = log[i / 2] + 1;
        table.assign(log[n] + 1, values);
        for (int k = 1; k < (int)table.size(); ++k)
            for (int i = 0; i + (1 << k) <= n; ++i)
                table[k][i] = std::min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
    }
    int query(int left, int right) const {
        int k = log[right - left + 1];
        return std::min(table[k][left], table[k][right - (1 << k) + 1]);
    }
private:
    std::vector<std::vector<int>> table; std::vector<int> log;
};
