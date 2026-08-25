#include <deque>
#include <limits>
#include <tuple>
#include <vector>

std::vector<int> zero_one_bfs(int n, const std::vector<std::tuple<int, int, int>>& edges, int source) {
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (auto [u, v, w] : edges) graph[u].push_back({v, w});
    const int inf = std::numeric_limits<int>::max();
    std::vector<int> dist(n, inf); std::deque<int> q;
    dist[source] = 0; q.push_back(source);
    while (!q.empty()) {
        int u = q.front(); q.pop_front();
        for (auto [v, w] : graph[u]) if (dist[u] != inf && dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            if (w == 0) q.push_front(v); else q.push_back(v);
        }
    }
    return dist;
}
