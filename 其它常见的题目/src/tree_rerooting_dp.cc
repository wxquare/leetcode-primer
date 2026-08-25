#include <vector>

std::vector<long long> sum_of_distances_in_tree(int n, const std::vector<std::vector<int>>& graph, int root = 0) {
    std::vector<int> size(n, 1); std::vector<long long> answer(n);
    auto first = [&](auto&& self, int u, int p, int depth) -> void {
        answer[root] += depth;
        for (int v : graph[u]) if (v != p) self(self, v, u, depth + 1), size[u] += size[v];
    };
    auto second = [&](auto&& self, int u, int p) -> void {
        for (int v : graph[u]) if (v != p) { answer[v] = answer[u] + n - 2LL * size[v]; self(self, v, u); }
    };
    first(first, root, -1, 0); second(second, root, -1); return answer;
}
