#include <algorithm>
#include <array>
#include <cstdint>

class LinearBasis {
public:
    bool insert(std::uint64_t value) {
        for (int bit = 63; bit >= 0; --bit) if ((value >> bit) & 1) {
            if (!basis[bit]) { basis[bit] = value; return true; }
            value ^= basis[bit];
        }
        return false;
    }
    std::uint64_t max_xor(std::uint64_t seed = 0) const {
        for (int bit = 63; bit >= 0; --bit) seed = std::max(seed, seed ^ basis[bit]);
        return seed;
    }
    bool representable(std::uint64_t value) const {
        for (int bit = 63; bit >= 0; --bit) if ((value >> bit) & 1) { if (!basis[bit]) return false; value ^= basis[bit]; }
        return true;
    }
private:
    std::array<std::uint64_t, 64> basis{};
};
