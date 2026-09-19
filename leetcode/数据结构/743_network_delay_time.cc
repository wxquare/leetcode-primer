/*

有 n 个网络节点，标记为 1 到 n。

给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。

现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。
*/



/*
[[3,5,78],
[2,1,1],
[1,3,0],
[4,3,59],
[5,3,85],
[5,2,22],
[2,4,23],
[1,4,43],
[4,5,75],
[5,1,15],
[1,5,91],
[4,1,16],
[3,2,98],
[3,4,22],
[5,4,31],
[1,2,0],
[2,5,4],
[4,2,51],
[3,1,36],
[2,3,59]]
*/

#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n+1,INT_MAX);
        // 边转图
        unordered_map<int,vector<pair<int,int>>> g;
        for(auto t : times){
            g[t[0]].push_back({t[1],t[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dis[k] = 0;
        vector<int> vis(n+1,false);
        while(!pq.empty()){
            auto [w,u] = pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u] = true;   
            for(auto [v,w] : g[u]){
                if(dis[u] + w < dis[v]){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v],v});
                }
            }
        }
        int ans = *max_element(dis.begin()+1,dis.end());
        return ans == INT_MAX ? -1 : ans;
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    std::cout << Solution().networkDelayTime(times,4,2) << std::endl;
    return 0;
}
