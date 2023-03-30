
/*

   1. 并查集是一种用于管理元素所属集合的数据结构，实现为一个森林，其中每棵树表示一个集合，树中的节点表示对应集合中的元素。
   2. 时间复杂度是常数，空间复杂度是O(n)
*/

#include <vector>
#include <numeric>
using namespace std;

class UnionFind {
public:
    vector<int> parents;
    vector<int> sizes;
    int setCnt; //连通量
    UnionFind(int n){
        parents = vector<int>(n,0);
        iota(parents.begin(),parents.end(),0);
        sizes = vector<int>(n,1);
        setCnt = n;
    }
    
    // 启发式union
    void Union(int x,int y){
        int px = Find(x);
        int py = Find(y);
        if(px == py) return;
        if(sizes[px] < sizes[py]){
            swap(px,py);
        }
        parents[py] = px;
        sizes[px] += parents[py];
        setCnt--;
    }

    int Find(int x){
        // 路径压缩
        return parents[x] == x ? x : parents[x] = Find(parents[x]);
    }
};