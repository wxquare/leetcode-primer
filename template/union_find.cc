class UnionFind {
private:
    vector<int> parent;
    vector<int> componentSize; // 每个连通块的大小（以根节点为 key）
    int componentCount;       // 连通块的总数量

public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // 批量初始化 parent[i] = i
        componentSize.assign(n, 1);
        componentCount = n;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;

        // 按大小合并：将较小的树合并到较大的树下方
        if (componentSize[rootX] > componentSize[rootY]) {
            swap(rootX, rootY);
        }
        
        parent[rootX] = rootY;
        componentSize[rootY] += componentSize[rootX];
        componentCount--;
        return true;
    }

    // 获取某个节点所在连通块的大小
    int getComponentSize(int x) {
        return componentSize[find(x)];
    }

    // 获取当前连通块的总数
    int getComponentCount() const {
        return componentCount;
    }
};
