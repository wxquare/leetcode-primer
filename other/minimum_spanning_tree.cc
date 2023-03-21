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
    vector<int> pars,szs;

    UnionFind(int n){
        pars = vector<int>(n,0);
        iota(pars.begin(),pars.end(),0);
        szs = vector<int>(n,0);
    }

    int Find(int x){
        return x == pars[x] ? x : pars[x] = Find(pars[x]);
    }

    void Union(int x,int y){
        int px = Find(x);
        int py = Find(y);
        if(szs[py] < szs[px]){
            swap(px,py);
        }
        pars[px] = py;
        szs[px] += szs[py];
    }    
};

vector<pair<int,int>> kruskal(vector<vector<int>>& graph,int n){
    sort(graph.begin(),graph.end(),[](const vector<int>& v1,const vector<int>& v2){
        return v1[2] < v2[2];
    });
    UnionFind uf(n);
    vector<pair<int,int>> ans;
    for(auto & e : graph){
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


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

