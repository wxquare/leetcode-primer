
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

/*
    edges:[0,1],[0,2],[1,3]
*/
vector<int> bfs(int n,vector<vector<int>>& edges,int start){
    vector<int> dis(n,-1);
    dis[start] = 0;
    unordered_map<int,vector<int>> g;
    for(auto e : edges){
        g[e[0]].push_back(e[1]);
    }
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : g[u]){
            if(dis[v] == -1 || dis[u] + 1 < dis[v]){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis;
}

/*
    edges: [u,v,d],[0,1,3],[1,2,4]
*/
vector<int> dijkstra(int n,vector<vector<int>>& edges,int start){
    vector<int> dis(n,-1);
    dis[start] = 0;
    unordered_map<int,vector<pair<int,int>>> g;
    for(auto e : edges){
        int u = e[0],v = e[1],d = e[2];
        g[u].push_back({d,v});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> vis(n,false);
    pq.push({0,start});
    while(!pq.empty()){
        auto [_,u] = pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v,d] : g[u]){
            if(dis[v] == -1 || dis[v] < dis[u] + d){
                dis[v] = dis[u] + d;
                pq.push({v,dis[v]});
            }
        }
    }
    return dis;
}


/*
    edges: [u,v,d],[0,1,3],[1,2,-4]
*/
vector<int> bellmanFord(int n,vector<vector<int>>& edges,int start){
    vector<int> dis(n,INT_MAX);

    for(int i=0;i<n;i++){ // n-1轮松弛
        for(auto e : edges){ // 针对边遍历
            int u = e[0],v = e[1],d = e[2];
            if(dis[u] != INT_MAX){
                dis[v] = min(dis[v],dis[u]+d);
            }
        }
    }
    // 对于存在负数的情况，可以检测负环
    for(auto e : edges){ // 遍历边
        int u = e[0],v = e[1],d = e[2];
        if(dis[u] != INT_MAX){
            if(dis[u] + d < dis[v]){
                std::cout << "negative cycle" << std::endl;
                return dis;
            }
        }
    }
    return dis;
}


vector<vector<int>> floyd(int n,vector<vector<int>>& edges){
    vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++){
        dis[i][i] = 0;
    }
    for(auto e : edges){
        int u = e[0],v = e[1], d = e[2];
        dis[u][v] = min(dis[u][v],d);
    }
    for(int k=0;k<n;k++){
        // 允许经过[0,k],dis[i][j]的最短距离
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][k] == INT_MAX) continue;
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    // 检测是否存在负环
    for(int i=0;i<n;i++){
        if(dis[i][i] < 0) {
            std::cout << "has negative cycle" << std::endl;
            return {};
        }
    }
    return dis;
}