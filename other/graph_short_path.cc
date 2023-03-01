#include <vector>
#include <iostream>
#include <queue>
using namespace std;



vector<int> bfs(vector<vector<pair<int,int>>>& graph,int start){
    int n = graph.size();
    vector<int> dis(n,INT_MAX);
    vector<bool> vis(n,false);
    queue<int> q;
    q.push(start);
    dis[start] = 0;
    vis[start] = true;        
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto [next,w] : graph[cur]){
            dis[next] = min(dis[cur]+w,dis[next]);
            if(vis[next]) continue;
            vis[next] = true;
            q.push(next);
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
    // dis,cur
    q.push({0,start});
    vector<bool> vis(n,false);
    while(!q.empty()){
        int v = q.top().second;
        q.pop();
        if(vis[v]) continue;
        vis[v] = true;
        for(auto [nv,nu] : graph[v]){
            if(vis[nv]) continue;
            if(dis[v] == INT_MAX && nu == INT_MAX) continue;
            if(dis[v] + nu >= dis[nv]) continue;
            dis[nv] = dis[v] + nu;
            q.push({dis[nv],nv});
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
