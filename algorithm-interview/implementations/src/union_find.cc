#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class UnionFind{
public:
    vector<int> pars;
    int cnt; // 集合个数
    vector<int> sz;

    UnionFind(int n){
        pars = vector<int>(n,0);
        iota(pars.begin(),pars.end(),0);
        cnt = n;
        sz = vector<int>(n,1);
    }

    int find(int x){
        return x == pars[x] ? x : pars[x] = find(pars[x]);
    }

    void merge(int x,int y){
        int px = find(x),py = find(y);
        if(px == py) return;

        if(sz[px] < sz[py]){
            swap(px,py);
        }
        pars[px] = pars[py];
        sz[px] += sz[py];
        cnt--;
    }
    bool isConnect(int x,int y){
        return find(x) == find(y);
    }
};

int main(){
    UnionFind uf(10);
    uf.merge(1,2);
    std::cout << uf.cnt << '\t' << uf.isConnect(1,2) << std::endl;
}