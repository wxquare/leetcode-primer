/*
    1. 我们定义无向连通图的 最小生成树（Minimum Spanning Tree，MST）为边权和最小的生成树。
    注意：只有连通图才有生成树，而对于非连通图，只存在生成森林。
*/

#include <vector>
#include <numeric>
using namespace std;

/*
    [u,v,w]
*/

class UnionFind{
public:
    vector<int> parents;
    vector<int> sizes;
    int cnt;

    UnionFind(int n){
        parents = vector<int>(n,0);
        iota(parents.begin(),parents.end(),0);
        sizes = vector<int>(n,1);
    }

    int Find(int x){
        return x == parents[x] ? x : parents[x] = Find(parents[x]);
    }

    void Union(int x,int y){
        int px = Find(x);
        int py = Find(y);
        if(px == py) return;

        if(sizes[px] < sizes[py]){
            swap(px,py);
        }
        parents[py] = px;
        sizes[px] += sizes[py];
        cnt--;
    }    
};

vector<vector<int>> kruskal(vector<vector<int>>& edges,int n){
    sort(edges.begin(),edges.end(),[](const vector<int>& e1,const vector<int>& e2){
        return e1[2] < e2[2];
    });
    UnionFind uf(n);
    vector<vector<int>> ans;
    for(auto & e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if(uf.Find(u) != uf.Find(v)){
            ans.push_back({u,v});
            uf.Union(u,v);
        }
    }
    return ans;
}
