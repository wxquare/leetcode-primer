
/*

    1. 有向无环图，按照顶点的依赖关系排序

*/

#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> topoSort(vector<pair<int,int>>& graph,int n){
    vector<int> in(n,0);
    unordered_map<int,vector<int>> m;
    for(auto p : graph){
        in[p.second]++;
        m[p.first].push_back(p.second);
    }
    vector<int> ans;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto next : m[cur]){
            in[next]--;
            if(in[next] == 0){
                q.push(next);
            }
        }
    }
    if(ans.size() != n){
        std::cout << "exist a cycle" << std::endl;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
