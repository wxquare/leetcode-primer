#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        map<int,vector<pair<int,int>>> g;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                g[mat[i][j]].push_back({i,j});
            }
        }

        vector<int> rowMax(m),colMax(n);
        int ans = 0;
        for(auto &[_,pos] : g){
            vector<int> mx; 
            for(auto &[i,j] : pos){
                mx.push_back(max(rowMax[i],colMax[j]) + 1);
                ans = max(mx.back(),ans);
            }

            for(int k=0;k<pos.size();k++){
                auto &[i,j] = pos[k];
                rowMax[i] = max(rowMax[i],mx[k]);
                colMax[j] = max(colMax[j],mx[k]);
            }
        }

        return ans;
    }
};