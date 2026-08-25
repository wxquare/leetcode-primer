/*
给你一个 n 个点的带权无向连通图，节点编号为 0 到 n-1 ，同时还有一个数组 edges ，其中 edges[i] = [fromi, toi, weighti] 表示在 fromi 和 toi 节点之间有一条带权无向边。最小生成树 (MST) 是给定图中边的一个子集，它连接了所有节点且没有环，而且这些边的权值和最小。

请你找到给定图中最小生成树的所有关键边和伪关键边。如果从图中删去某条边，会导致最小生成树的权值和增加，那么我们就说它是一条关键边。伪关键边则是可能会出现在某些最小生成树中但不会出现在所有最小生成树中的边。

请注意，你可以分别以任意顺序返回关键边的下标和伪关键边的下标。
输入：n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
输出：[[0,1],[2,3,4,5]]
解释：上图描述了给定图。
下图是所有的最小生成树。
*/

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class UnionFind{
public:
    vector<int> pars;
    vector<int> size;
    // 联通分量
    int setCnt;
    UnionFind(int n):pars(n),size(n,1),setCnt(n){
        iota(pars.begin(),pars.end(),0);
    }

    int Find(int x){
        return x == pars[x] ? x : pars[x] = Find(pars[x]);
    }

    void Union(int x,int y){
        int px = Find(x);
        int py = Find(y);
        if(px == py) return;

        if(size[px] > size[py]){
            swap(px,py);
        }
        pars[px] = py;
        size[py] += size[px];
        --setCnt;
    }
    bool IsConnected(int x,int y){
        return Find(x) == Find(y);
    }
};


class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // 将索引加入到edge中，方便后面将构造返回ans
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }

        vector<vector<int>> ans(2);
        
        // 按照边的weight从小到大排序
        sort(edges.begin(),edges.end(),[](const vector<int>& e1,const vector<int>& e2){
            return e1[2] < e2[2];
        });

        // 整个图的最小生成树
        UnionFind uf(n);
        int minVal = 0;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(!uf.IsConnected(u,v)){
                uf.Union(u,v);
                minVal += w;
            }
        }
        // 枚举，去掉每一条边
        for(int i=0;i<edges.size();i++){
            UnionFind uf(n);
            int val = 0;
            for(int j=0;j<edges.size();j++){
                if(i == j) continue;
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(!uf.IsConnected(u,v)){
                    uf.Union(u,v);
                    val += w;
                }
            }
            if(uf.setCnt > 1 || val > minVal){
                ans[0].push_back(edges[i][3]); // 关键边,除去这条边可能导致不连通或者最小生成树的值大于全图的值
                continue;
            }


            // 判断是否时伪关键边
            UnionFind uf2(n);
            uf2.Union(edges[i][0],edges[i][1]);
            val = edges[i][2];
            for(int j=0;j<edges.size();j++){
                if(i == j) continue;
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(!uf2.IsConnected(u,v)){
                    uf2.Union(u,v);
                    val += w;
                }
            }
            if(uf2.setCnt == 1 && val == minVal){
                ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> edges = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};
    vector<vector<int>> ans = Solution().findCriticalAndPseudoCriticalEdges(5,edges);
    for(auto a : ans){
        for(auto b : a){
            std::cout << b  << '\t';
        }
        std::cout << '\n';
    }
    return 0;
}