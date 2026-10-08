#include <algorithm>
#include <limits>
#include <queue>
#include <stdexcept>
#include <vector>

class Dinic {
public:
    explicit Dinic(int vertex_count)
        : graph_(checked_size(vertex_count)), level_(graph_.size()), next_edge_(graph_.size()) {}

    void add_edge(int from, int to, long long capacity) {
        check_vertex(from); check_vertex(to);
        if (capacity < 0) throw std::invalid_argument("capacity must be non-negative");
        const int reverse_from = static_cast<int>(graph_[static_cast<std::size_t>(to)].size());
        const int reverse_to = static_cast<int>(graph_[static_cast<std::size_t>(from)].size());
        graph_[static_cast<std::size_t>(from)].push_back({to, reverse_from, capacity});
        graph_[static_cast<std::size_t>(to)].push_back({from, reverse_to, 0});
    }

    long long max_flow(int source, int sink) {
        check_vertex(source); check_vertex(sink);
        if (source == sink) return 0;
        long long result = 0;
        while (build_levels(source, sink)) {
            std::fill(next_edge_.begin(), next_edge_.end(), 0);
            while (const long long pushed = send(source, sink, std::numeric_limits<long long>::max())) {
                result += pushed;
            }
        }
        return result;
    }

private:
    struct Edge { int to; int reverse; long long capacity; };
    std::vector<std::vector<Edge>> graph_;
    std::vector<int> level_;
    std::vector<std::size_t> next_edge_;

    static std::size_t checked_size(int vertex_count) {
        if (vertex_count < 0) throw std::invalid_argument("vertex count must be non-negative");
        return static_cast<std::size_t>(vertex_count);
    }
    void check_vertex(int vertex) const {
        if (vertex < 0 || static_cast<std::size_t>(vertex) >= graph_.size()) {
            throw std::out_of_range("vertex is outside the graph");
        }
    }
    bool build_levels(int source, int sink) {
        std::fill(level_.begin(), level_.end(), -1);
        std::queue<int> pending;
        level_[static_cast<std::size_t>(source)] = 0; pending.push(source);
        while (!pending.empty()) {
            const int current = pending.front(); pending.pop();
            for (const Edge& edge : graph_[static_cast<std::size_t>(current)]) {
                if (edge.capacity > 0 && level_[static_cast<std::size_t>(edge.to)] == -1) {
                    level_[static_cast<std::size_t>(edge.to)] = level_[static_cast<std::size_t>(current)] + 1;
                    pending.push(edge.to);
                }
            }
        }
        return level_[static_cast<std::size_t>(sink)] != -1;
    }
    long long send(int current, int sink, long long available) {
        if (current == sink) return available;
        auto& edges = graph_[static_cast<std::size_t>(current)];
        for (std::size_t& index = next_edge_[static_cast<std::size_t>(current)]; index < edges.size(); ++index) {
            Edge& edge = edges[index];
            if (edge.capacity == 0 || level_[static_cast<std::size_t>(edge.to)] != level_[static_cast<std::size_t>(current)] + 1) continue;
            const long long pushed = send(edge.to, sink, std::min(available, edge.capacity));
            if (pushed == 0) continue;
            edge.capacity -= pushed;
            graph_[static_cast<std::size_t>(edge.to)][static_cast<std::size_t>(edge.reverse)].capacity += pushed;
            return pushed;
        }
        return 0;
    }
};
