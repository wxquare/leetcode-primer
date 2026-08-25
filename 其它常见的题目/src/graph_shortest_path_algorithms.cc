#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

/*
    1. 一般只用于求无权路的最短路。（也可用于求无环、权重图，但不常见）
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
vector<int> dijkstra(vector<vector<int>>& edges, int n,int start){
    unordered_map<int,vector<pair<int,int>>> g;
    for(auto e : edges){
        int u = e[0],v=e[1],w=e[2];
        g[u].push_back({w,v});
    }
    vector<int> dis(n,INT_MAX);
    vector<bool> vis(n,false);
    dis[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,start});
    while(!q.empty()){
        auto [w,u] = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v,w] : g[u]){
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
vector<int> bellmanFord(vector<vector<int>>& edges,int n,int start){
    unordered_map<int,vector<pair<int,int>>> g;
    for(auto e : edges){
        g[e[0]].push_back({e[2],e[1]});
    }

    vector<int> dis(n,INT_MAX);
    dis[start] = 0;
    for(int i=0;i<n-1;i++){ // n - 1 轮松弛
        for(int j=0;j<n;j++){ // from:j,to:v
            for(auto [v,w] : g[j]){
                if(dis[j] != INT_MAX){
                    dis[v] = min(dis[v],dis[j]+w);
                }
            }
        }
    }
    for(int i=0;i<n;i++){ // from:i,to:v
        for(auto [v,w] : g[i]){
            if(dis[i] != INT_MAX){
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
vector<vector<int>> floyd(vector<vector<int>>& edges,int n){
    
    vector<vector<int>> dist(n+1,vector<int>(n+1,INT_MAX));

    for(auto e : edges){
        int u = e[0],v=e[1],w=e[2];
        dist[u][v] = min(dist[u][v],w);
    }

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