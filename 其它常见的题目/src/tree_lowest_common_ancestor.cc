#include <cstddef>
#include <queue>
#include <stdexcept>
#include <utility>
#include <vector>

class LowestCommonAncestor {
public:
    LowestCommonAncestor(int vertex_count,
                         const std::vector<std::pair<int, int>>& edges,
                         int root = 0)
        : size_(checked_size(vertex_count)), depth_(size_, -1) {
        check_vertex(root);
        std::vector<std::vector<int>> graph(size_);
        for (const auto& [first, second] : edges) {
            check_vertex(first); check_vertex(second);
            graph[static_cast<std::size_t>(first)].push_back(second);
            graph[static_cast<std::size_t>(second)].push_back(first);
        }
        std::size_t levels = 1;
        while ((std::size_t{1} << levels) <= size_) ++levels;
        parent_.assign(levels, std::vector<int>(size_, root));
        std::queue<int> pending;
        depth_[static_cast<std::size_t>(root)] = 0; pending.push(root);
        while (!pending.empty()) {
            const int current = pending.front(); pending.pop();
            for (int next : graph[static_cast<std::size_t>(current)]) {
                if (depth_[static_cast<std::size_t>(next)] != -1) continue;
                depth_[static_cast<std::size_t>(next)] = depth_[static_cast<std::size_t>(current)] + 1;
                parent_[0][static_cast<std::size_t>(next)] = current;
                pending.push(next);
            }
        }
        for (int value : depth_) {
            if (value == -1) throw std::invalid_argument("graph must be connected");
        }
        for (std::size_t level = 1; level < parent_.size(); ++level) {
            for (std::size_t vertex = 0; vertex < size_; ++vertex) {
                parent_[level][vertex] = parent_[level - 1][static_cast<std::size_t>(parent_[level - 1][vertex])];
            }
        }
    }

    int query(int first, int second) const {
        check_vertex(first); check_vertex(second);
        if (depth_[static_cast<std::size_t>(first)] < depth_[static_cast<std::size_t>(second)]) std::swap(first, second);
        int difference = depth_[static_cast<std::size_t>(first)] - depth_[static_cast<std::size_t>(second)];
        for (std::size_t level = 0; difference > 0; ++level, difference >>= 1) {
            if ((difference & 1) != 0) first = parent_[level][static_cast<std::size_t>(first)];
        }
        if (first == second) return first;
        for (std::size_t level = parent_.size(); level-- > 0;) {
            if (parent_[level][static_cast<std::size_t>(first)] != parent_[level][static_cast<std::size_t>(second)]) {
                first = parent_[level][static_cast<std::size_t>(first)];
                second = parent_[level][static_cast<std::size_t>(second)];
            }
        }
        return parent_[0][static_cast<std::size_t>(first)];
    }

private:
    std::size_t size_;
    std::vector<int> depth_;
    std::vector<std::vector<int>> parent_;
    static std::size_t checked_size(int vertex_count) {
        if (vertex_count <= 0) throw std::invalid_argument("vertex count must be positive");
        return static_cast<std::size_t>(vertex_count);
    }
    void check_vertex(int vertex) const {
        if (vertex < 0 || static_cast<std::size_t>(vertex) >= size_) throw std::out_of_range("vertex is outside the tree");
    }
};
