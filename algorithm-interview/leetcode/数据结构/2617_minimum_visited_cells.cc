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
#include <set>
using namespace std;

/*
    时间复杂度：(m+n)*(mn)
*/
class Solution{
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(); // m rows
        int n = grid[0].size(); // n cols

        vector<set<pair<int,int>>> colsts(n); // 每一列的平衡二叉树

        vector<vector<int>> ans(m,vector<int>(n,INT_MAX/2)); //到达该位置的最小需要走的步数
        for(int i=0;i<m;i++){
            set<pair<int,int>> st;
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0){
                    ans[i][j] = 0;
                } else {
                    while(!st.empty() && st.begin()->second < j){
                        st.erase(st.begin());
                    }
                    while(!colsts[j].empty() && colsts[j].begin()->second < i){
                        colsts[j].erase(colsts[j].begin());
                    }
                    if(!st.empty()){
                        ans[i][j] = min(ans[i][j],st.begin()->first);
                    }
                    if(!colsts[j].empty()){
                        ans[i][j] = min(ans[i][j],colsts[j].begin()->first);
                    }
                }
                st.insert({ans[i][j]+1,j+grid[i][j]});
                colsts[j].insert({ans[i][j]+1,i+grid[i][j]});
            }
        }
        return ans[m-1][n-1] == INT_MAX/2 ? -1 : ans[m-1][n-1] + 1;
    }
};



int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};
    std::cout << Solution().minimumVisitedCells(grid) << std::endl;
    return 0;
}
