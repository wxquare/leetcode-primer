
#include <vector>
#include <iostream>
using namespace std;

/*
    前缀和数组
    nums = [1,2,3]
    prefix = [1,3,6]
    difference = [1,1,1]
    fenwick_tree = [1,3,6]
    segment_tree = 动态开点，区间聚合值，
*/

/*
    差分数组是一种常用的数据结构，用于高效处理数组的区间增减操作。它可以在 O(1) 的时间内完成区间增减操作，而不需要修改原始数组的每个元素
*/
// 原数组:  [1,4,5,6,3]
// 差分数组: [1,3,1,1,-3]
// 差分数组的前缀和是: [1,4,5,6,3]
// 差分数组区间增加一个值，例如在[2，4]区间加上 diff[start] += 3,diff[end+1] -=3
void difference(){
    vector<int> nums = {1,4,5,6,4}; //原数组
    int n = nums.size();
    // 由原数组创建diff数组
    vector<int> diff(n);
    diff[0] = nums[0];
    for(int i=1;i<n;i++){
        diff[i] = nums[i] - nums[i-1];
    }

    // 在区间[2,4]中每个数加上3
    diff[2] += 3;
    diff[4+1] -= 3;

    // 由差分数组返回原数组
    vector<int> ans(n,0);
    ans[0] = diff[0];
    for(int i=1;i<n;i++){
        ans[i] = diff[i] + ans[i-1];
    }
}

class FenwickTree{
public:
    vector<int> tree;
    // 从1开始 
    FenwickTree(int n){
        tree = vector<int>(n+1,0);//noted
    }

    // add val
    void update(int i,int val){
        while(i < tree.size()){
            tree[i] += val;
            i += i & (-i); // add lowbit(i)
        }
    }

    int prefixSum(int i){
        int sum = 0;
        while(i > 0){
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }

    int rangeSum(int i,int j){
        return prefixSum(j) - prefixSum(i-1);
    }
};

struct SegNode {
    int l,r; // 节点表示的范围
    SegNode* leftChild;
    SegNode* rightChild;
    int x; // 区间内的聚合值，可以是区间和、区间最大最小值、平均值等
    int lz; // 懒加载
    SegNode(int l_,int r_){
        l = l_;
        r = r_;
        leftChild = nullptr;
        rightChild = nullptr;
        x = 0; // 注意初始化值
    }
    SegNode* GetLeftChild(){
        if(l == r) return nullptr;
        if(leftChild == nullptr){
            int mid = l + (r - l) / 2;
            leftChild = new SegNode(l,mid);
            return leftChild;
        }
        return leftChild;
    }
    SegNode* GetRightChild(){
        if(l == r) return nullptr;
        if(rightChild == nullptr){
            int mid = l + (r - l) / 2;
            rightChild = new SegNode(mid + 1,r);
            return rightChild;
        }
        return rightChild;
    }
};
/*
    1. 动态开点
*/
class SegTree{
private:
    void pushDownLazy(SegNode* rt){
        // 判断lazy 是否需要pushdown
        if(rt->lz == 0) return;
        if(rt->GetLeftChild()){
            SegNode* ll = rt->GetLeftChild();
            ll->lz = rt->lz;
            ll->x = (ll->r - ll->l + 1) * ll->lz;
        }

        if(rt->GetRightChild()){
            SegNode* rr = rt->GetRightChild();
            rr->lz = rt->lz;
            rr->x = (rr->r - rr->l + 1) * rr->lz;
        }
        rt->lz = 0; // reset rt->lz
    }
    void pushUpX(SegNode* rt){
        rt->x = 0;
        if(rt->GetLeftChild()){
            rt->x += rt->GetLeftChild()->x;
        }
        if(rt->GetRightChild()){
            rt->x += rt->GetRightChild()->x;
        }
    }
    void update(SegNode* rt,int l,int r,int val){
        // 区间无相交
        if(max(rt->l,l) > min(rt->r,r)){
            return;
        }
        // 全包含
        if(rt->l >= l && rt->r <= r){
            rt->lz = val;
            rt->x = (rt->r - rt->l + 1) * val;
            return;
        }
        // 部分包含
        pushDownLazy(rt);
        if(rt->GetLeftChild()){
            update(rt->GetLeftChild(),l,r,val);
        }
        if(rt->GetRightChild()){
            update(rt->GetRightChild(),l,r,val);
        }
        pushUpX(rt);
    }
    int query(SegNode* rt,int l,int r){
        // 停止
        if(rt == nullptr) return 0;
        // 不包含
        if(max(rt->l,l) > min(rt->r,r)){
            return 0;
        }
        //全包含
        if(rt->l >= l && rt->r <= r){
            return rt->x;
        }
        // 聚合左右节点的数据
        return query(rt->GetLeftChild(),l,r) + query(rt->GetRightChild(),l,r);
    }
public:
    SegNode* root;
    SegTree(int l_,int r_){
        root = new SegNode(l_,r_);
    }
    // 将某个区间[left,right]内的数都变为val
    void Update(int left,int right,int val){
        update(root,left,right,val);
    }
    // 查询某个区间[left,right]内聚合的数据x
    int Query(int left,int right){
        return query(root,left,right);
    }
};

