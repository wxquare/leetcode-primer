#include <algorithm>
#include <vector>

class BridgeAndCutVertex {
public:
    explicit BridgeAndCutVertex(int n) : graph(n), tin(n, -1), low(n), is_cut(n, false) {}
    void add_edge(int u, int v) {
        int id = edges++;
        graph[u].push_back({v, id}); graph[v].push_back({u, id});
    }
    void build() { for (int i = 0; i < (int)graph.size(); ++i) if (tin[i] == -1) dfs(i, -1); }
    const std::vector<std::pair<int, int>>& bridges() const { return bridge_edges; }
    const std::vector<bool>& cut_vertices() const { return is_cut; }
private:
    std::vector<std::vector<std::pair<int, int>>> graph;
    std::vector<int> tin, low;
    std::vector<bool> is_cut;
    std::vector<std::pair<int, int>> bridge_edges;
    int timer = 0, edges = 0;
    void dfs(int u, int parent_edge) {
        tin[u] = low[u] = timer++; int children = 0;
        for (auto [v, id] : graph[u]) {
            if (id == parent_edge) continue;
            if (tin[v] != -1) low[u] = std::min(low[u], tin[v]);
            else {
                dfs(v, id); low[u] = std::min(low[u], low[v]); ++children;
                if (low[v] > tin[u]) bridge_edges.push_back({u, v});
                if (parent_edge != -1 && low[v] >= tin[u]) is_cut[u] = true;
            }
        }
        if (parent_edge == -1 && children > 1) is_cut[u] = true;
    }
};
