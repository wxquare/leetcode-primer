

#include <iostream>
#include <vector>
#include <queue>
using namespace std;




struct Edge {
    int to;
    int capacity;
    int flow;
    int rev; // 反向边在vector中的下标
};

/*
    n个节点的有向权图
*/
int maxFlow(int n,vector<vector<int>>& edges,int s,int t){

    // build graph
    vector<vector<Edge>> g(n);
    for(auto e : edges){
        g[e[0]].push_back({e[1],e[2]});
    }

    

}


const int INF = 1e9;

struct Edge {
    int to;
    int capacity;
    int flow;
    int rev; // 反向边在vector中的下标
};

class Dinic {
public:
    int n; // 图中顶点的数量
    vector<vector<Edge>> graph;
    vector<int> level; // 层次图
    vector<int> iter; // 当前弧优化

    Dinic(int n) {
        this->n = n;
        graph.resize(n);
        level.resize(n);
        iter.resize(n);
    }

    void addEdge(int from, int to, int capacity) {
        graph[from].push_back({to, capacity, 0, graph[to].size()});
        graph[to].push_back({from, 0, 0, graph[from].size() - 1});
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const Edge& e : graph[u]) {
                if (level[e.to] < 0 && e.flow < e.capacity) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }

        return level[t] >= 0;
    }

    int dfs(int u, int t, int f) {
        if (u == t) return f;

        for (int& i = iter[u]; i < graph[u].size(); i++) {
            Edge& e = graph[u][i];
            if (e.capacity > e.flow && level[e.to] == level[u] + 1) {
                int d = dfs(e.to, t, min(f, e.capacity - e.flow));
                if (d > 0) {
                    e.flow += d;
                    graph[e.to][e.rev].flow -= d;
                    return d;
                }
            }
        }

        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(iter.begin(), iter.end(), 0);
            int f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
};

int main() {
    int n = 4;
    Dinic dinic(n);
    dinic.addEdge(0, 1, 2);
    dinic.addEdge(0, 2, 3);
    dinic.addEdge(1, 2, 1);
    dinic.addEdge(1, 3, 1);
    dinic.addEdge(2, 3, 2);

    int maxFlow = dinic.maxFlow(0, 3);
    cout << "Max Flow: " << maxFlow << endl;

    return 0;
}
