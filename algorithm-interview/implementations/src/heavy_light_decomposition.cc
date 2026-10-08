#include <algorithm>
#include <utility>
#include <vector>

class HeavyLightDecomposition {
public:
    explicit HeavyLightDecomposition(int n) : graph(n), parent(n), depth(n), heavy(n, -1), head(n), pos(n), size(n) {}
    void add_edge(int u, int v) { graph[u].push_back(v); graph[v].push_back(u); }
    void build(int root = 0) { dfs_size(root, -1); current = 0; dfs_decompose(root, root); }
    std::vector<std::pair<int, int>> path_segments(int u, int v) const {
        std::vector<std::pair<int, int>> result;
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]]) std::swap(u, v);
            result.push_back({pos[head[u]], pos[u]}); u = parent[head[u]];
        }
        if (depth[u] > depth[v]) std::swap(u, v);
        result.push_back({pos[u], pos[v]});
        return result;
    }
    int index(int u) const { return pos[u]; }
private:
    std::vector<std::vector<int>> graph;
    std::vector<int> parent, depth, heavy, head, pos, size;
    int current = 0;
    int dfs_size(int u, int p) {
        parent[u] = p; size[u] = 1; int best = 0;
        for (int v : graph[u]) if (v != p) { depth[v] = depth[u] + 1; int sub = dfs_size(v, u); size[u] += sub; if (sub > best) best = sub, heavy[u] = v; }
        return size[u];
    }
    void dfs_decompose(int u, int h) {
        head[u] = h; pos[u] = current++;
        if (heavy[u] != -1) dfs_decompose(heavy[u], h);
        for (int v : graph[u]) if (v != parent[u] && v != heavy[u]) dfs_decompose(v, v);
    }
};
