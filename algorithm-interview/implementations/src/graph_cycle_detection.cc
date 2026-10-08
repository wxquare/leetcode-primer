#include <iostream>
#include <vector>
using namespace std;

int findMaxCycle(int n,vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for(auto e : edges){
        g[e[0]].push_back(e[1]);
    }
    int dis[n];
    memset(dis,-1,sizeof(dis));
    int ans = -1;
    function<void(int)> dfs = [&](int cur){
        for(auto & next : g[cur]){
            if(dis[next] != -1){
                ans = max(ans,dis[cur] - dis[next]+1);
            } else {
                dis[next] = dis[cur]+1;
                dfs(next);
            }
        }
        dis[cur] = -1;
    };
    for(int i=0;i<n;i++){
        memset(dis,-1,sizeof(dis));
        dis[i] = 1;
        dfs(i);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> edges = {{0,1},{1,0},{2,1},{0,2}};
    findMaxCycle(3,edges);
    return 0;
}




