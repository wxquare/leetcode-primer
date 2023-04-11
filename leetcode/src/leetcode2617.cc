/*
给你一个下标从 0 开始的 m x n 整数矩阵 grid 。你一开始的位置在 左上角 格子 (0, 0) 。

当你在格子 (i, j) 的时候，你可以移动到以下格子之一：

满足 j < k <= grid[i][j] + j 的格子 (i, k) （向右移动），或者
满足 i < k <= grid[i][j] + i 的格子 (k, j) （向下移动）。
请你返回到达 右下角 格子 (m - 1, n - 1) 需要经过的最少移动格子数，如果无法到达右下角格子，请你返回 -1 。
*/


#include <vector>
#include <queue>
#include <iostream>
using namespace std;


/*
    时间复杂度：(m+n)*(mn)
*/
class Solution1 {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        q.push({0,0});
        int step = 0;
        if(grid.size() == 1 && grid[0].size() == 1) return 1;
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> vis(m*n,false);
        while(!q.empty()){
            step++; 
            int size = q.size();
            for(int i=0;i<size;i++){
                int curx = q.front().first;
                int cury = q.front().second;
                q.pop();
                if(curx == m-1 && cury == n-1){
                    return step;
                }
                if(vis[curx*n+cury]) continue;
                vis[curx*n+cury] = true;
                for(int j=1;j<=grid[curx][cury];j++){
                    int nx = curx + j;
                    int ny = cury + j;
                    
                   if(nx >= grid.size() && ny >= grid[0].size()) break;

                    if(nx < grid.size()){
                        q.push({nx,cury});
                    }
                    if(ny < grid[0].size()){
                        q.push({curx,ny});
                    }
                }    
            }
        }
        return -1;
    }
};


void printVector(vector<pair<int,int>>& data){
    for(auto it : data){
        std::cout << '{' << it.first << ',' << it.second << '}' << ','; 
    }
    std::cout << std::endl;
}

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mn;
        vector<vector<pair<int, int>>> col_st(n); // 每列的单调栈
        
        for (int i = m - 1; i >= 0; --i) {
            vector<pair<int, int>> st; // 当前行的单调栈

            for (int j = n - 1; j >= 0; --j) {
                auto &st2 = col_st[j];
                mn = INT_MAX;
                if (i == m - 1 && j == n - 1) // 特殊情况：已经是终点
                    mn = 0;
                else if (int g = grid[i][j]; g) {
                    // 在单调栈上二分
                    // 降序的二分查找
                    auto it = lower_bound(st.begin(), st.end(), j + g, [](const auto &a, const int b) {
                        return a.second > b;
                    });
                    if (it < st.end()) {
                        mn = min(mn, it->first);
                        //std::cout << "=== " << i << '\t' << j << '\t' << it->first << '\t' << it->second << std::endl;
                    }
                    it = lower_bound(st2.begin(), st2.end(), i + g, [](const auto &a, const int b) {
                        return a.second > b;
                    });
                    if (it < st2.end()) {
                        mn = min(mn, it->first);
                        //std::cout << i << '\t' << j << '\t' << it->first << '\t' << it->second << std::endl;
                    }
                }
                if (mn == INT_MAX) continue;

                ++mn; // 加上 (i,j) 这个格子
                // 插入单调栈
                while (!st.empty() && mn <= st.back().first)
                    st.pop_back();
                st.emplace_back(mn, j);
                printVector(st);
                while (!st2.empty() && mn <= st2.back().first)
                    st2.pop_back();
                st2.emplace_back(mn, i);
                printVector(st2);
            }
        }
        return mn < INT_MAX ? mn : -1;
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};
    std::cout << Solution().minimumVisitedCells(grid) << std::endl;
    return 0;
}
