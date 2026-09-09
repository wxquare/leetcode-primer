#include <iostream>
#include <vector>
using namespace std;



// 节点数量为n
// 无向图
vector<int> lca(int n,vector<vector<int>>& edges,vector<vector<int>>& queries){

    // build graph
    vector<vector<int>> g(n);
    for(auto e : edges){
        int v = e[0],u = e[1];
        g[v].push_back(u);
        g[u].push_back(v);
    }

    int m = 32 - __builtin_clz(n);
    // traverse
    vector<int> depth(n);
    vector<vector<int>> pa(n,vector<int>(n,-1));

}




const int MAXN = 10005; // 最大节点数
const int LOGN = 14;   // 2^14 > MAXN，用于预处理

vector<int> tree[MAXN]; // 树的邻接表
int parent[MAXN][LOGN]; // parent[i][j] 表示节点i的2^j级祖先

int depth[MAXN]; // 节点的深度

void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node][0] = par;

    for (int i = 1; i < LOGN; ++i) {
        if (parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        }
    }

    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }

    // 将x提升到和y相同深度
    for (int i = LOGN - 1; i >= 0; --i) {
        if (depth[x] - (1 << i) >= depth[y]) {
            x = parent[x][i];
        }
    }

    if (x == y) {
        return x;
    }

    // 同时向上跳跃，找到LCA
    for (int i = LOGN - 1; i >= 0; --i) {
        if (parent[x][i] != -1 && parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    return parent[x][0];
}

int main() {
    int n;
    cin >> n;

    // 初始化
    for (int i = 1; i <= n; ++i) {
        tree[i].clear();
        for (int j = 0; j < LOGN; ++j) {
            parent[i][j] = -1;
        }
    }

    // 构建树的结构
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        while (m--) {
            int child;
            cin >> child;
            tree[i].push_back(child);
        }
    }

    // 从根节点开始DFS，预处理节点深度和祖先信息
    dfs(1, -1, 0);

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ancestor = lca(x, y);
        cout << "LCA of " << x << " and " << y << " is " << ancestor << endl;
    }

    return 0;
}
