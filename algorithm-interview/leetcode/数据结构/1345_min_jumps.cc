
/*
1345. 跳跃游戏 IV

给你一个整数数组 arr ，你一开始在数组的第一个元素处（下标为 0）。

每一步，你可以从下标 i 跳到下标 i + 1 、i - 1 或者 j ：

i + 1 需满足：i + 1 < arr.length
i - 1 需满足：i - 1 >= 0
j 需满足：arr[i] == arr[j] 且 i != j
请你返回到达数组最后一个元素的下标处所需的 最少操作次数 。

注意：任何时候你都不能跳到数组外面。

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8

输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
输出：3
解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        vector<bool> visited(n,false);
        queue<pair<int,int>> q;
        q.push({0,arr[0]});
        visited[0] = true;

        int step = 0;

        while(!q.empty()){
            int size = q.size();
            step++;
            for(int i=0;i<size;i++){
                int curi = q.front().first;
                int curv = q.front().second;
                q.pop();
                // i + 1
                int nexti = curi + 1;
                if(nexti >= 0 && nexti < n && !visited[nexti]) {
                    if(nexti == n - 1) return step;
                    visited[nexti] = true;
                    q.push({nexti,arr[nexti]});
                }

                // i - 1
                nexti = curi - 1;
                if(nexti >= 0 && nexti < n && !visited[nexti]) {
                    if(nexti == n - 1) return step;
                    visited[nexti] = true;
                    q.push({nexti,arr[nexti]});
                }

                // j 需满足：arr[i] == arr[j] 且 i != j
                for(auto nexti : m[arr[curi]]){
                    if(nexti < 0 || nexti >= n || visited[nexti]) continue;
                    if(nexti == n - 1) return step;
                    visited[nexti] = true;
                    q.push({nexti,arr[nexti]});
                }
                m.erase(arr[nexti]);
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    std::cout << Solution().minJumps(arr) << std::endl;
    return 0;
}
