#include <cstddef>
#include <cstdint>
#include <stdexcept>

namespace cstring_ops {
namespace {
void require_pointer(const void* pointer, std::size_t count) {
    if (pointer == nullptr && count != 0) {
        throw std::invalid_argument("null pointer with non-zero length");
    }
}
}  // namespace

void* copy(void* destination, const void* source, std::size_t count) {
    require_pointer(destination, count);
    require_pointer(source, count);
    auto* output = static_cast<unsigned char*>(destination);
    const auto* input = static_cast<const unsigned char*>(source);
    for (std::size_t index = 0; index < count; ++index) output[index] = input[index];
    return destination;
}

void* move(void* destination, const void* source, std::size_t count) {
    require_pointer(destination, count);
    require_pointer(source, count);
    auto* output = static_cast<unsigned char*>(destination);
    const auto* input = static_cast<const unsigned char*>(source);
    const auto output_address = reinterpret_cast<std::uintptr_t>(output);
    const auto input_address = reinterpret_cast<std::uintptr_t>(input);
    if (output_address > input_address && output_address < input_address + count) {
        for (std::size_t index = count; index > 0; --index) output[index - 1] = input[index - 1];
    } else {
        copy(destination, source, count);
    }
    return destination;
}

void* fill(void* destination, unsigned char value, std::size_t count) {
    require_pointer(destination, count);
    auto* output = static_cast<unsigned char*>(destination);
    for (std::size_t index = 0; index < count; ++index) output[index] = value;
    return destination;
}

std::size_t length(const char* text) {
    if (text == nullptr) throw std::invalid_argument("text must not be null");
    std::size_t result = 0;
    while (text[result] != '\0') ++result;
    return result;
}

int compare(const char* lhs, const char* rhs) {
    if (lhs == nullptr || rhs == nullptr) throw std::invalid_argument("strings must not be null");
    while (*lhs != '\0' && *lhs == *rhs) { ++lhs; ++rhs; }
    return static_cast<unsigned char>(*lhs) - static_cast<unsigned char>(*rhs);
}

char* copy_string(char* destination, const char* source) {
    copy(destination, source, length(source) + 1);
    return destination;
}

char* concatenate(char* destination, const char* source) {
    copy(destination + length(destination), source, length(source) + 1);
    return destination;
}
}  // namespace cstring_ops
