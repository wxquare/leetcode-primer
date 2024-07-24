#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {

        vector<long long> prefixRow(verticalCut.size()+1,0);
        vector<long long> prefixCol(horizontalCut.size()+1,0);


        for(int i=0;i<verticalCut.size();i++){
            prefixRow[i+1] = verticalCut[i] + prefixRow[i];
        }

        for(int i=0;i<horizontalCut.size();i++){
            prefixCol[i+1] = horizontalCut[i] + prefixCol[i];
        }

        int memo[m][n];
        memset(memo,-1,sizeof(memo));

        function<long long(int,int)> dfs = [&](int x,int y)->long long{

            // std::cout << x << '\t' << y << std::endl;
            if(x == m - 1){
                long long t = prefixRow.back() - prefixRow[y];
                std::cout << x << '\t' << y << '\t' << t << std::endl;
                return t;
            }

            if(y == n - 1){
                long long t = prefixCol.back() - prefixCol[x];
                std::cout << x << '\t' << y << '\t' <<  t << std::endl;
                return t;
            }

            // if(memo[x][y] != -1){
            //     return memo[x][y];
            // }
            std::cout << "====1" << x << '\t' << y << '\t' << horizontalCut[x] + prefixCol.back() - prefixCol[y] << std::endl;
            long long res1 = dfs(x+1,y) + horizontalCut[x] + prefixRow.back() - prefixRow[y];
            std::cout << "====2" << x << '\t' << y << '\t' << verticalCut[y] + prefixRow.back() - prefixRow[x] << std::endl;
            long long res2 = dfs(x,y+1) + verticalCut[y] + prefixCol.back() - prefixCol[x];
            long long r = min(res1,res2);
            // std::cout << x << '\t' << y << '\t' << r << std::endl;
            // memo[x][y] = r;

            std::cout << x << '\t' << y << '\t' << r << std::endl;
            return r;
        };
        return dfs(4,1);
    }
};

int main(){
    vector<int> horizontalCut = {2,3,2,3,1};
    vector<int> verticalCut = {1,2};
    std::cout << Solution().minimumCost(6,3,horizontalCut,verticalCut) << std::endl;

}