#include <numeric>
#include <vector>

class UnionFind {
public:
    explicit UnionFind(int n) : parent(n), size(n, 1), components(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) std::swap(a, b);
        parent[b] = a; size[a] += size[b]; --components;
        return true;
    }
    bool connected(int a, int b) { return find(a) == find(b); }
    int component_size(int x) { return size[find(x)]; }
    int count() const { return components; }
private:
    std::vector<int> parent, size;
    int components;
};
