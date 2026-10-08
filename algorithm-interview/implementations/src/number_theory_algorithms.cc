#include <algorithm>
#include <functional>
#include <numeric>
#include <random>
#include <stdexcept>
#include <vector>

namespace number_theory {
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

std::vector<int> prime_factors(int value) {
    if (value == 0) throw std::invalid_argument("zero has no finite prime factorization");
    value = std::abs(value);
    std::vector<int> factors;
    for (int divisor = 2; divisor <= value / divisor; ++divisor) {
        while (value % divisor == 0) {
            factors.push_back(divisor);
            value /= divisor;
        }
    }
    if (value > 1) factors.push_back(value);
    return factors;
}

std::vector<int> common_prime_factors(const std::vector<int>& values) {
    if (values.empty()) return {};
    int common = 0;
    for (int value : values) common = std::gcd(common, value);
    auto factors = prime_factors(common);
    factors.erase(std::unique(factors.begin(), factors.end()), factors.end());
    return factors;
}

int gcd(int first, int second) { return std::gcd(first, second); }
int lcm(int first, int second) { return std::lcm(first, second); }

struct ExtendedGcdResult { long long gcd; long long x; long long y; };

ExtendedGcdResult extended_gcd(long long first, long long second) {
    if (second == 0) {
        const long long sign = first < 0 ? -1 : 1;
        return {first * sign, sign, 0};
    }
    const auto next = extended_gcd(second, first % second);
    return {next.gcd, next.y, next.x - (first / second) * next.y};
}

long long mod_power(long long base, long long exponent, long long modulus) {
    if (modulus <= 1 || exponent < 0) throw std::invalid_argument("invalid modular power arguments");
    base %= modulus;
    if (base < 0) base += modulus;
    long long result = 1 % modulus;
    while (exponent > 0) {
        if ((exponent & 1) != 0) result = result * base % modulus;
        base = base * base % modulus;
        exponent >>= 1;
    }
    return result;
}

long long combination_mod(long long n, long long k, long long prime_modulus) {
    if (k < 0 || k > n) return 0;
    if (k > n - k) k = n - k;
    long long numerator = 1, denominator = 1;
    for (long long index = 1; index <= k; ++index) {
        numerator = numerator * ((n - k + index) % prime_modulus) % prime_modulus;
        denominator = denominator * (index % prime_modulus) % prime_modulus;
    }
    return numerator * mod_power(denominator, prime_modulus - 2, prime_modulus) % prime_modulus;
}

int rand10(const std::function<int()>& rand7) {
    while (true) {
        const int value = (rand7() - 1) * 7 + (rand7() - 1);
        if (value >= 0 && value < 40) return value % 10 + 1;
    }
}

std::vector<int> reservoir_sample(const std::vector<int>& values, std::size_t count,
                                  std::mt19937& generator) {
    if (count > values.size()) throw std::invalid_argument("sample is larger than input");
    std::vector<int> sample(values.begin(), values.begin() + static_cast<std::ptrdiff_t>(count));
    for (std::size_t index = count; index < values.size(); ++index) {
        std::uniform_int_distribution<std::size_t> distribution(0, index);
        const std::size_t position = distribution(generator);
        if (position < count) sample[position] = values[index];
    }
    return sample;
}

void shuffle(std::vector<int>& values, std::mt19937& generator) {
    std::shuffle(values.begin(), values.end(), generator);
}
}  // namespace number_theory
