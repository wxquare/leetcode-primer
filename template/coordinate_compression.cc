#include <algorithm>
#include <vector>

template <class T>
class CoordinateCompression {
public:
    explicit CoordinateCompression(std::vector<T> values) : coordinates(std::move(values)) {
        std::sort(coordinates.begin(), coordinates.end()); coordinates.erase(std::unique(coordinates.begin(), coordinates.end()), coordinates.end());
    }
    int index(const T& value) const { return std::lower_bound(coordinates.begin(), coordinates.end(), value) - coordinates.begin(); }
    const T& value(int index) const { return coordinates[index]; }
    int size() const { return coordinates.size(); }
private:
    std::vector<T> coordinates;
};
