#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace combinatorics {
using i64 = long long;

i64 choose(unsigned n, unsigned k) {
    if (k > n) return 0;
    if (k > n - k) k = n - k;
    i64 result = 1;
    for (unsigned index = 1; index <= k; ++index) {
        result = result * static_cast<i64>(n - k + index) / static_cast<i64>(index);
    }
    return result;
}

i64 mod_power(i64 base, i64 exponent, i64 modulus) {
    if (modulus <= 1 || exponent < 0) throw std::invalid_argument("invalid modular power arguments");
    base %= modulus;
    i64 result = 1 % modulus;
    while (exponent > 0) {
        if ((exponent & 1) != 0) result = result * base % modulus;
        base = base * base % modulus;
        exponent >>= 1;
    }
    return result;
}

class ModCombinations {
public:
    ModCombinations(std::size_t maximum, i64 modulus)
        : modulus_(modulus), factorial_(maximum + 1, 1), inverse_factorial_(maximum + 1, 1) {
        if (modulus_ <= 1) throw std::invalid_argument("modulus must be greater than one");
        for (std::size_t value = 1; value <= maximum; ++value) {
            factorial_[value] = factorial_[value - 1] * static_cast<i64>(value) % modulus_;
        }
        inverse_factorial_[maximum] = mod_power(factorial_[maximum], modulus_ - 2, modulus_);
        for (std::size_t value = maximum; value > 0; --value) {
            inverse_factorial_[value - 1] = inverse_factorial_[value] * static_cast<i64>(value) % modulus_;
        }
    }

    i64 choose(std::size_t n, std::size_t k) const {
        if (k > n || n >= factorial_.size()) return 0;
        return factorial_[n] * inverse_factorial_[k] % modulus_ * inverse_factorial_[n - k] % modulus_;
    }

private:
    i64 modulus_;
    std::vector<i64> factorial_;
    std::vector<i64> inverse_factorial_;
};

namespace {
i64 choose_small_mod(i64 n, i64 k, i64 prime) {
    if (k < 0 || k > n) return 0;
    if (k > n - k) k = n - k;
    i64 numerator = 1, denominator = 1;
    for (i64 index = 1; index <= k; ++index) {
        numerator = numerator * (n - k + index) % prime;
        denominator = denominator * index % prime;
    }
    return numerator * mod_power(denominator, prime - 2, prime) % prime;
}
}  // namespace

i64 lucas(i64 n, i64 k, i64 prime) {
    if (n < 0 || k < 0 || prime <= 1) throw std::invalid_argument("invalid Lucas arguments");
    i64 result = 1;
    while (n > 0 || k > 0) {
        const i64 digit_n = n % prime;
        const i64 digit_k = k % prime;
        if (digit_k > digit_n) return 0;
        result = result * choose_small_mod(digit_n, digit_k, prime) % prime;
        n /= prime;
        k /= prime;
    }
    return result;
}
}  // namespace combinatorics
