/*
45. 跳跃游戏 II

给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

0 <= j <= nums[i] 
i + j < n
返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。


输入: nums = [2,3,1,1,4]
             3,10,1,1,1
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;


/*
    时间复杂度：O(n*n)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0; 
        int step = 0;
        queue<pair<int,int>> q;
        q.push({nums[0],0});
        bool succ = false;
        vector<bool> vis(n,false);
        while(!q.empty() && !succ){
            step++;
            int size = q.size();
            for(int s=0;s<size;s++){
                auto [val,start] = q.front();
                q.pop();
                if(vis[start]) continue;
                vis[start] = true;
                for(int i=val;i>=1;i--){
                    int next = start + i;
                    if(next == n-1){
                        succ = true;
                        break;
                    }
                    if(next < n){
                        q.push({nums[next],next});
                    }
                }
            }
        }
        return step;
    }
};


class Solution{
public:
    int jump(vector<int>& nums){
        int pos = nums.size() - 1;
        int step = 0;
        while(pos > 0){
            for(int i=0;i<pos;i++){
                if(i + nums[i] >= pos){
                    pos = i;
                    step++;
                }
            }
        }
        return step;
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};



/*


class Solution2 {
    public int jump(int[] nums) {
        int position = nums.length - 1;
        int steps = 0;
        while (position > 0) {
            for (int i = 0; i < position; i++) {
                if (i + nums[i] >= position) {
                    position = i;
                    steps++;
                    break;
                }
            }
        }
        return steps;
    }
}

*/



int main(){
    vector<int> nums = {2,3,1,1,4};
    std::cout << Solution().jump(nums) << std::endl;
}