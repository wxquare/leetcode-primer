#include <algorithm>
#include <string>
#include <vector>

std::vector<int> z_function(const std::string& s) {
    int n = s.size(), left = 0, right = 0; std::vector<int> z(n);
    for (int i = 1; i < n; ++i) {
        if (i < right) z[i] = std::min(right - i, z[i - left]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > right) left = i, right = i + z[i];
    }
    if (n) z[0] = n;
    return z;
}
