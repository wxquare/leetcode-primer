#include <stdexcept>
#include <vector>

using Matrix = std::vector<std::vector<long long>>;

Matrix multiply(const Matrix& a, const Matrix& b, long long mod) {
    int n = a.size(), m = b[0].size(), inner = b.size(); Matrix result(n, std::vector<long long>(m));
    for (int i = 0; i < n; ++i) for (int k = 0; k < inner; ++k) if (a[i][k]) for (int j = 0; j < m; ++j)
        result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod;
    return result;
}

Matrix matrix_power(Matrix base, long long exponent, long long mod) {
    int n = base.size(); Matrix result(n, std::vector<long long>(n));
    for (int i = 0; i < n; ++i) result[i][i] = 1;
    while (exponent) { if (exponent & 1) result = multiply(result, base, mod); base = multiply(base, base, mod); exponent >>= 1; }
    return result;
}
