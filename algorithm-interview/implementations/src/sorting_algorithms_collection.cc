#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <vector>

namespace sorting_algorithms {
void bubble_sort(std::vector<int>& values) {
    for (std::size_t end = values.size(); end > 1; --end) {
        bool changed = false;
        for (std::size_t index = 1; index < end; ++index) {
            if (values[index] < values[index - 1]) {
                std::swap(values[index], values[index - 1]); changed = true;
            }
        }
        if (!changed) break;
    }
}

void insertion_sort(std::vector<int>& values) {
    for (std::size_t index = 1; index < values.size(); ++index) {
        const int current = values[index];
        std::size_t position = index;
        while (position > 0 && current < values[position - 1]) {
            values[position] = values[position - 1]; --position;
        }
        values[position] = current;
    }
}

void selection_sort(std::vector<int>& values) {
    for (std::size_t index = 0; index < values.size(); ++index) {
        std::iter_swap(values.begin() + static_cast<std::ptrdiff_t>(index),
                       std::min_element(values.begin() + static_cast<std::ptrdiff_t>(index), values.end()));
    }
}

void shell_sort(std::vector<int>& values) {
    for (std::size_t gap = values.size() / 2; gap > 0; gap /= 2) {
        for (std::size_t index = gap; index < values.size(); ++index) {
            const int current = values[index];
            std::size_t position = index;
            while (position >= gap && current < values[position - gap]) {
                values[position] = values[position - gap]; position -= gap;
            }
            values[position] = current;
        }
    }
}

namespace {
void quick_sort_range(std::vector<int>& values, std::ptrdiff_t left, std::ptrdiff_t right) {
    if (left >= right) return;
    const int pivot = values[static_cast<std::size_t>(left + (right - left) / 2)];
    std::ptrdiff_t first = left, second = right;
    while (first <= second) {
        while (values[static_cast<std::size_t>(first)] < pivot) ++first;
        while (values[static_cast<std::size_t>(second)] > pivot) --second;
        if (first <= second) {
            std::swap(values[static_cast<std::size_t>(first)], values[static_cast<std::size_t>(second)]);
            ++first; --second;
        }
    }
    if (left < second) quick_sort_range(values, left, second);
    if (first < right) quick_sort_range(values, first, right);
}

void merge_sort_range(std::vector<int>& values, std::vector<int>& temporary,
                      std::size_t left, std::size_t right) {
    if (right - left < 2) return;
    const std::size_t middle = left + (right - left) / 2;
    merge_sort_range(values, temporary, left, middle);
    merge_sort_range(values, temporary, middle, right);
    std::merge(values.begin() + static_cast<std::ptrdiff_t>(left),
               values.begin() + static_cast<std::ptrdiff_t>(middle),
               values.begin() + static_cast<std::ptrdiff_t>(middle),
               values.begin() + static_cast<std::ptrdiff_t>(right),
               temporary.begin() + static_cast<std::ptrdiff_t>(left));
    std::copy(temporary.begin() + static_cast<std::ptrdiff_t>(left),
              temporary.begin() + static_cast<std::ptrdiff_t>(right),
              values.begin() + static_cast<std::ptrdiff_t>(left));
}
}  // namespace

void quick_sort(std::vector<int>& values) {
    if (!values.empty()) quick_sort_range(values, 0, static_cast<std::ptrdiff_t>(values.size() - 1));
}
void merge_sort(std::vector<int>& values) {
    std::vector<int> temporary(values.size());
    merge_sort_range(values, temporary, 0, values.size());
}

void counting_sort(std::vector<int>& values) {
    if (values.empty()) return;
    const auto [minimum, maximum] = std::minmax_element(values.begin(), values.end());
    const int minimum_value = *minimum;
    const int maximum_value = *maximum;
    const long long range = static_cast<long long>(maximum_value) - minimum_value + 1;
    if (range > 1'000'000) {
        std::sort(values.begin(), values.end());
        return;
    }
    std::vector<std::size_t> counts(static_cast<std::size_t>(range));
    for (int value : values) ++counts[static_cast<std::size_t>(value - minimum_value)];
    std::size_t output = 0;
    for (std::size_t offset = 0; offset < counts.size(); ++offset) {
        while (counts[offset] > 0) {
            values[output++] = minimum_value + static_cast<int>(offset);
            --counts[offset];
        }
    }
}

void radix_sort(std::vector<int>& values) {
    std::vector<int> temporary(values.size());
    for (unsigned shift = 0; shift < std::numeric_limits<std::uint32_t>::digits; shift += 8) {
        std::array<std::size_t, 256> counts{};
        for (int value : values) {
            const auto key = static_cast<std::uint32_t>(value) ^ 0x80000000U;
            ++counts[(key >> shift) & 0xffU];
        }
        std::array<std::size_t, 256> positions{};
        for (std::size_t index = 1; index < positions.size(); ++index) {
            positions[index] = positions[index - 1] + counts[index - 1];
        }
        for (int value : values) {
            const auto key = static_cast<std::uint32_t>(value) ^ 0x80000000U;
            temporary[positions[(key >> shift) & 0xffU]++] = value;
        }
        values.swap(temporary);
    }
}

void bucket_sort(std::vector<int>& values) {
    if (values.size() < 2) return;
    const auto [minimum, maximum] = std::minmax_element(values.begin(), values.end());
    const std::size_t bucket_count = values.size();
    const long long range = static_cast<long long>(*maximum) - *minimum + 1;
    std::vector<std::vector<int>> buckets(bucket_count);
    for (int value : values) {
        const auto scaled = static_cast<long long>(value) - *minimum;
        std::size_t index = static_cast<std::size_t>(scaled * static_cast<long long>(bucket_count) / range);
        if (index == bucket_count) --index;
        buckets[index].push_back(value);
    }
    std::size_t output = 0;
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
        for (int value : bucket) values[output++] = value;
    }
}

void heap_sort(std::vector<int>& values) {
    std::make_heap(values.begin(), values.end());
    std::sort_heap(values.begin(), values.end());
}
}  // namespace sorting_algorithms
