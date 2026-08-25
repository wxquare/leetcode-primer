#include <algorithm>
#include <string>
#include <vector>

std::string longest_palindromic_substring(const std::string& s) {
    std::string transformed = "^";
    for (char c : s) transformed += '#', transformed += c;
    transformed += "#$";
    std::vector<int> radius(transformed.size()); int center = 0, right = 0, best_center = 0, best_radius = 0;
    for (int i = 1; i + 1 < (int)transformed.size(); ++i) {
        if (i < right) radius[i] = std::min(right - i, radius[2 * center - i]);
        while (transformed[i + radius[i] + 1] == transformed[i - radius[i] - 1]) ++radius[i];
        if (i + radius[i] > right) center = i, right = i + radius[i];
        if (radius[i] > best_radius) best_radius = radius[i], best_center = i;
    }
    return s.substr((best_center - best_radius) / 2, best_radius);
}
