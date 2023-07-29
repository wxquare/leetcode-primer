
#include <vector>
#include <numeric>
using namespace std;

class UnionFind {
public:
    vector<int> parents;
    vector<int> sizes;
    int cnt;

    UnionFind(int n){
        parents.resize(n);
        iota(parents.begin(),parents.end(),0);
        sizes = vector<int>(n,1);
        cnt = n;
    }

    int Find(int x){
        return x == parents[x] ? x : parents[x] = Find(parents[x]);
    }

    bool isConnect(int x,int y){
        return Find(x) == Find(y);
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