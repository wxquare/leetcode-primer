#include <cstdlib>
#include <functional>
#include <numeric>
#include <stdexcept>
#include <vector>

namespace math_practice {
bool is_prime(int value) {
    if (value < 2) return false;
    for (int divisor = 2; divisor <= value / divisor; ++divisor) {
        if (value % divisor == 0) return false;
    }
    return true;
}

std::vector<int> primes_up_to(int limit) {
    if (limit < 2) return {};
    std::vector<bool> prime(static_cast<std::size_t>(limit + 1), true);
    prime[0] = prime[1] = false;
    for (int value = 2; value <= limit / value; ++value) {
        if (!prime[static_cast<std::size_t>(value)]) continue;
        for (int multiple = value * value; multiple <= limit; multiple += value) {
            prime[static_cast<std::size_t>(multiple)] = false;
        }
    }
    std::vector<int> result;
    for (int value = 2; value <= limit; ++value) {
        if (prime[static_cast<std::size_t>(value)]) result.push_back(value);
    }
    return result;
}

int gcd(int first, int second) { return std::gcd(first, second); }

int lcm(int first, int second) { return std::lcm(first, second); }

long long power(long long base, unsigned exponent) {
    long long result = 1;
    while (exponent > 0) {
        if ((exponent & 1U) != 0) result *= base;
        base *= base;
        exponent >>= 1U;
    }
    return result;
}

int rand10(const std::function<int()>& rand7) {
    while (true) {
        const int value = (rand7() - 1) * 7 + (rand7() - 1);
        if (value >= 0 && value < 40) return value % 10 + 1;
    }
}
}  // namespace math_practice
