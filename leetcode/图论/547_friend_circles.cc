/*
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。


isConnected = [[1,1,0],[1,1,0],[0,0,1]]
*/

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class UnionFind{
public:
    vector<int> pa;
    vector<int> sz;
    int cnt;
    UnionFind(int n):pa(n),sz(n,1),cnt(n){
        iota(pa.begin(),pa.end(),0);
    }

    int Find(int x){
        return x == pa[x] ? x : pa[x] = Find(pa[x]);
    }

    void Union(int x,int y){
        int px = Find(x);
        int py = Find(y);
        if(px == py){
            return;
        }
        if(sz[px] < sz[py]){
            swap(px,py);
        }
        sz[px] += sz[py];
        pa[py] = px;
        cnt--;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j) continue;
                if(isConnected[i][j] == 1){
                    uf.Union(i,j);
                }
            }
        }
        return uf.cnt;
    }
};

int main(){
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    std::cout << Solution().findCircleNum(isConnected) << std::endl;
}