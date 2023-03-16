#include <vector>
#include <iostream>
using namespace std;

class BIT {
public:
    vector<int> tree;
    vector<int> ori;
    int size;

    int get_parent(int i){
        return i - (i & (-i));
    }

    int get_next(int i){
        return i + (i & (-i));
    }


    // build bit array
    BIT(vector<int>& nums){
        size = nums.size();
        ori = nums;
        tree = vector<int>(size+1,0);
        for(int i=0;i<size;i++){
            for(int j=i+1;j<=size;j=get_next(j)){
                tree[j] += nums[i];
            }
        }
    }

    // prefixSum
    int prefixSum(int x){
        int ans = 0;
        for(int i=x;i>0;i=get_parent(i)){
            ans += tree[i];
        }
        return ans;
    }

    void update(int index,int x){
        int delta = x - ori[index];
        ori[index] = x;
        for(int i=index+1;i<=size;i=get_next(i)){
            tree[i] += delta;
        }
    }
};


class NumArray {
public:
    BIT* root;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        root = new BIT(nums);
    }

    void update(int index, int val) {
        root->update(index,val);
    }
    
    int sumRange(int left, int right) {
        return root->prefixSum(right+1) - root->prefixSum(left);
    }
};
