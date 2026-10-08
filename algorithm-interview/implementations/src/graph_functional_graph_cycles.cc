#include <algorithm>
#include <limits>
#include <queue>
#include <stdexcept>
#include <utility>
#include <vector>

namespace graph_cycles {
int shortest_undirected_cycle(int vertex_count,
                              const std::vector<std::pair<int, int>>& edges) {
    if (vertex_count < 0) throw std::invalid_argument("vertex count must be non-negative");
    std::vector<std::vector<int>> graph(static_cast<std::size_t>(vertex_count));
    for (const auto& [from, to] : edges) {
        if (from < 0 || from >= vertex_count || to < 0 || to >= vertex_count) {
            throw std::out_of_range("edge endpoint is outside the graph");
        }
        graph[static_cast<std::size_t>(from)].push_back(to);
        graph[static_cast<std::size_t>(to)].push_back(from);
    }
    int answer = std::numeric_limits<int>::max();
    for (int start = 0; start < vertex_count; ++start) {
        std::vector<int> distance(static_cast<std::size_t>(vertex_count), -1);
        std::vector<int> parent(static_cast<std::size_t>(vertex_count), -1);
        std::queue<int> pending;
        distance[static_cast<std::size_t>(start)] = 0;
        pending.push(start);
        while (!pending.empty()) {
            const int current = pending.front();
            pending.pop();
            for (int next : graph[static_cast<std::size_t>(current)]) {
                if (distance[static_cast<std::size_t>(next)] == -1) {
                    distance[static_cast<std::size_t>(next)] = distance[static_cast<std::size_t>(current)] + 1;
                    parent[static_cast<std::size_t>(next)] = current;
                    pending.push(next);
                } else if (parent[static_cast<std::size_t>(current)] != next) {
                    answer = std::min(answer, distance[static_cast<std::size_t>(current)] +
                                             distance[static_cast<std::size_t>(next)] + 1);
                }
            }
        }
    }
    return answer == std::numeric_limits<int>::max() ? -1 : answer;
}

int longest_directed_cycle(const std::vector<int>& next) {
    const int size = static_cast<int>(next.size());
    for (int vertex : next) {
        if (vertex < -1 || vertex >= size) throw std::out_of_range("successor is outside the graph");
    }
    std::vector<int> visit(static_cast<std::size_t>(size), 0);
    std::vector<int> depth(static_cast<std::size_t>(size), 0);
    int answer = -1;
    for (int start = 0; start < size; ++start) {
        if (visit[static_cast<std::size_t>(start)] != 0) continue;
        const int marker = start + 1;
        int current = start, current_depth = 0;
        while (current != -1 && visit[static_cast<std::size_t>(current)] == 0) {
            visit[static_cast<std::size_t>(current)] = marker;
            depth[static_cast<std::size_t>(current)] = current_depth++;
            current = next[static_cast<std::size_t>(current)];
        }
        if (current != -1 && visit[static_cast<std::size_t>(current)] == marker) {
            answer = std::max(answer, current_depth - depth[static_cast<std::size_t>(current)]);
        }
    }
    return answer;
}
}  // namespace graph_cycles
