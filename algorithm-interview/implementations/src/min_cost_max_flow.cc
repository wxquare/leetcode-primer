#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class MinCostMaxFlow {
    struct Edge { int to, rev, capacity, cost; };
public:
    explicit MinCostMaxFlow(int n) : graph(n) {}
    void add_edge(int from, int to, int capacity, int cost) {
        graph[from].push_back({to, (int)graph[to].size(), capacity, cost});
        graph[to].push_back({from, (int)graph[from].size() - 1, 0, -cost});
    }
    std::pair<int, long long> flow(int source, int sink, int limit = std::numeric_limits<int>::max()) {
        const int inf = std::numeric_limits<int>::max() / 4; int total_flow = 0; long long total_cost = 0;
        while (total_flow < limit) {
            std::vector<int> dist(graph.size(), inf), parent_v(graph.size()), parent_e(graph.size());
            std::vector<bool> in_queue(graph.size()); std::queue<int> q; dist[source] = 0; q.push(source); in_queue[source] = true;
            while (!q.empty()) { int u = q.front(); q.pop(); in_queue[u] = false;
                for (int i = 0; i < (int)graph[u].size(); ++i) { const Edge& e = graph[u][i];
                    if (e.capacity > 0 && dist[e.to] > dist[u] + e.cost) { dist[e.to] = dist[u] + e.cost; parent_v[e.to] = u; parent_e[e.to] = i; if (!in_queue[e.to]) q.push(e.to), in_queue[e.to] = true; }
                }
            }
            if (dist[sink] == inf) break;
            int add = limit - total_flow;
            for (int v = sink; v != source; v = parent_v[v]) add = std::min(add, graph[parent_v[v]][parent_e[v]].capacity);
            for (int v = sink; v != source; v = parent_v[v]) { Edge& e = graph[parent_v[v]][parent_e[v]]; e.capacity -= add; graph[v][e.rev].capacity += add; }
            total_flow += add; total_cost += 1LL * add * dist[sink];
        }
        return {total_flow, total_cost};
    }
private:
    std::vector<std::vector<Edge>> graph;
};
