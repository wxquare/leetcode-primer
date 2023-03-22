
/*

    - BFS（广度优先搜索) 可用于求单源最短路，用于求无权路（同权路）的最短路。也有用于求无环图的权重图，一般不考虑。O(n)
    
    - Dijkstra 算法都是单源最短路径算法，作用于非负权图，可以有环。O(nlog(n))
    
    - 而 Floyd 算法和 Bellman-Ford 算法是多源最短路径算法。

    BFS 通过遍历从源节点可达的所有节点，层层递进，最终到达终点节点。BFS 可以求出从源节点到终点节点的最短路径，但只适用于无权图。

    Dijkstra 算法则是一种贪心算法，它能够处理带权图。它通过维护一个距离集合，从源节点开始，每次选取距离最小的节点进行松弛操作，并将该节点标记为已访问。Dijkstra 算法不能处理带有负权边的图。

    Floyd 算法和 Bellman-Ford 算法都可以处理带有负权边的图。Floyd 算法通过动态规划的思想，维护任意两个节点之间的最短距离。它通过多次迭代，逐步计算出所有节点之间的最短路径。Floyd 算法的时间复杂度为 O(n^3)，适用于节点数较小的图。

    Bellman-Ford 算法则是一种基于松弛操作的算法，通过不断的松弛操作，更新节点之间的距离。它可以处理带有负权边的图，并且能够检测出负权环。但是 Bellman-Ford 算法的时间复杂度较高，为 O(nm)，其中 n 和 m 分别为节点数和边数。

*/

#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;


/*
    1. 一般只用于求无权路的最短路。（也可用于求无环、权重图，单不常见）
    2. edges 表示边的集合，n：节点数量，start：源点
*/
vector<int> bfs(vector<vector<int>>& edges,int n,int start){
    unordered_map<int,vector<int>> g;
    for(auto e : edges){
        g[e[0]].push_back(e[1]);
    }
    vector<int> dis(n,INT_MAX);
    vector<bool> vis(n,false);
    queue<int> q;
    q.push(start);
    dis[start] = 0;
    vis[start] = true;        
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            dis[v] = dis[u] + 1;
            if(vis[v]) continue;
            vis[v] = true;
            q.push(v);
        }
    }
    return dis;
}


/*
 1. 用于求单源最短路
 2. 作用于求非负权图
 3. 不用用于检测负环
*/
vector<int> dijkstra(vector<vector<pair<int,int>>>& graph, int start){
    int n = graph.size();
    vector<int> dis(n,INT_MAX);
    dis[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,start});
    vector<bool> vis(n,false);
    while(!q.empty()){
        auto [w,u] = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v,w] : graph[u]){
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
            }
        }
    }
    return dis;
}


/*
    1. 单源最短路
    2. 支持负权图
    3. 可以用于检测负环
*/
vector<int> bellmanFord(vector<vector<pair<int,int>>>& graph,int start){
    int n = graph.size();
    vector<int> dis(n,INT_MAX);
    dis[start] = 0;
    for(int i=0;i<n-1;i++){ // n - 1 轮松弛
        for(int j=0;j<n;j++){ // from:j,to:v
            for(auto [v,w] : graph[j]){
                if(dis[j] != INT_MAX && w != INT_MAX){
                    dis[v] = min(dis[v],dis[j]+w);
                }
            }
        }
    }
    for(int i=0;i<n;i++){ // from:i,to:v
        for(auto [v,w] : graph[i]){
            if(dis[i] != INT_MAX && w != INT_MAX){
                if(dis[i] + w < dis[v]){
                    std::cout << "has negative cycle" << std::endl;
                    return vector<int>();
                }
            }
        }
    }
    return dis;
}

/*
1. 求任意两个结点之间的最短路
2. 支持有向、无向
3. 支持正向权重、负向权重
4. 可以用于检测是否存在负环

  限制条件：不能存在负环
*/
vector<vector<int>> floyd(vector<vector<int>>& graph){
    int n = graph.size();
    vector<vector<int>> dist(n+1,vector<int>(n+1,INT_MAX));
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    // 检测负环
    for(int i=1;i<=n;i++){
        if(dist[i][i] < 0){
            std::cout << "has negative cycle" << std::endl;
        }
    }
    return dist;
}


int main(){
    int n = 5;
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    graph[0] = {{1, 10}, {2, 3}, {3, 20}};
    graph[1] = {{0, 10}, {2, 5}};
    graph[2] = {{0, 3}, {1, 5}, {3, 2}};
    graph[3] = {{0, 20}, {2, 2}, {4, 1}};
    graph[4] = {{3, 1}};

    std::vector<int> dist = bfs(graph,0);
    for(auto d : dist){
        std::cout << d << '\t';
    }
    std::cout << std::endl;

}
