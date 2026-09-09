#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class BinaryIndexedTree {
public:
    vector<int> tree;
    
    BinaryIndexedTree(int n){
        tree.resize(n+1,0);  // index 需要从1开始
    }


    // 将index值改为val
    void update(int index,int val){
        std::cout << "update" << index <<std::endl;
        for(int i=index;i<=tree.size();i+=i&-i){
            tree[i] = max(tree[i],val);
        }
    }

    int ask(int index){
        std::cout << "ask" << index <<std::endl;
        int ans = 0;
        for(int i=index;i>0;i-=i&-i){
            ans = max(ans,tree[i]);
        }
        return ans;
    }

};

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        BinaryIndexedTree bt(mx+2);

        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            std::cout << i << std::endl;
            int v = bt.ask(nums[i]);
            ans = max(ans,v+1);
            bt.update(nums[i]+1,v+1);
        }
        return ans;

	}
};



int main(int argc, char const *argv[])
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    std::cout << Solution().lengthOfLIS(nums) << std::endl;
    return 0;
}


