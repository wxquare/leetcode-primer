#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

/*
    1. 在一个有向无环图中，节点之间存在依赖关系
    2. 根据依赖关系能否输出一个排序后的节点顺序
    3. 最经典的问题是课程表问题
*/

vector<int> topoSort(int n,vector<vector<int>>& edges){
    unordered_map<int,vector<int>> g;
    vector<int> in(n,0);
    for(auto e : edges){
        int u = e[0],v = e[1];
        in[v]++;
        g[u].push_back(v);
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for(int v : g[u]){
            in[v]--;
            if(in[v] == 0){
                q.push(v);
            }
        }
    }
    if(ans.size() != n){
        std::cout << "has cycles" << std::endl;
        return {};
    }
    return ans;
}