/*
给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。

连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。

请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。
*/



#include <vector>
#include <numeric>
#include <iostream>
using namespace std;


class UnionFind {
public:
    vector<int> pa;
    vector<int> szs;

    UnionFind(int n):pa(n),szs(n,1){
        iota(pa.begin(),pa.end(),0);
    }

    // 路径压缩
    int Find(int x){
        return x == pa[x] ? x : pa[x] = Find(pa[x]);
    }

    // 启发式
    void Union(int x,int y){
        int px = Find(x);
        int py = Find(y);
        if(px == py) return;

        if(szs[px] < szs[py]){
            swap(px,py);
        }
        szs[px] += szs[py];
        pa[py] = px;
    }   

    bool isConnected(int x,int y){
        return Find(x) == Find(y);
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i,j,d});
            }
        }
        sort(edges.begin(),edges.end(),[](const auto& v1,const auto& v2){
            return v1[2] < v2[2];
        });
        int ans = 0;
        int finished = 0;
        UnionFind uf(n);
        for(int i=0;i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];
            if(!uf.isConnected(x,y)){
                uf.Union(x,y);
                ans += w;
                finished++;
                if(finished == n-1) break;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    std::cout << Solution().minCostConnectPoints(points) << std::endl;
}