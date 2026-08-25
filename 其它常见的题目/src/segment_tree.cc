#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


/*
    1. 动态开点 vs 数组4n
    2. lzay标记,区间修改时要用
*/

struct SegNode {
    int l,r;
    SegNode *lchild,*rchild;
    int lazy;
    int sum; // aggregation value in the interval.

    SegNode(int _l,int _r){
        l = _l;
        r = _r;
        lazy = 0;
        sum = 0;
        lchild = nullptr;
        rchild = nullptr;
    }

    inline SegNode* GetLeftChild(){
        if(lchild) return lchild;
        if(l < r){
            lchild = new SegNode(l,(l+r)/2);
        }
        return lchild;
    }

    inline SegNode* GetRightChild(){
        if(rchild) return rchild;
        if(l < r) {
            rchild = new SegNode((l+r)/2+1,r);
        }
        return rchild;
    }
};

class SegTree{
private:
    SegNode* root;
    inline void push_down(SegNode* rt){
        // 判断是否需要push_down
        if(rt->lazy == 0) return;
        SegNode* lchild = rt->GetLeftChild();
        if(lchild){
            lchild->lazy = rt->lazy;
            lchild->sum = (lchild->r - lchild->l + 1) * rt->lazy;
        }
        SegNode* rchild = rt->GetRightChild();
        if(rchild){
            rchild->lazy = rt->lazy;
            rchild->sum = (rchild->r - rchild->l + 1) * rt->lazy;
        }
        rt->lazy = 0;
        return;
    }

    inline void push_up(SegNode* rt){
        rt->sum = 0;  // noted
        SegNode* ll = rt->GetLeftChild();
        if(ll){
            rt->sum += ll->sum;
        }
        SegNode* rr = rt->GetRightChild();
        if(rr){
            rt->sum += rr->sum;
        }
    }

    void update(SegNode* rt,int l,int r,int val){
        if(rt == nullptr) return;
        
        // 不包含
        if(max(rt->l,l) > min(rt->r,r)) return;
        // 全包含
        if(rt->l >= l && rt->r <= r){
            rt->lazy = val;
            rt->sum = (rt->r - rt->l + 1) * val;
            return;
        }
        // 部分包含
        push_down(rt);
        if(rt->GetLeftChild()) update(rt->GetLeftChild(),l,r,val);
        if(rt->GetRightChild()) update(rt->GetRightChild(),l,r,val);
        push_up(rt);
    }

    int query(SegNode* rt,int l,int r){
        if(rt == nullptr) return 0;
        // 不包含
        if(max(rt->l,l) > min(rt->r,r)) return 0;
        // 全包含
        if(rt->l >=l && rt->r <= r){
            return rt->sum;
        }
        // 部分包含
        return query(rt->GetLeftChild(),l,r) + query(rt->GetRightChild(),l,r);
    }

    inline void build(SegNode* rt,vector<int>& nums){
        if(rt == nullptr) return;
        if(rt->l == rt->r){
            rt->sum = nums[rt->l];
            return;
        }
        build(rt->GetLeftChild(),nums);
        build(rt->GetRightChild(),nums);
        if(rt->GetLeftChild()) rt->sum += rt->GetLeftChild()->sum;
        if(rt->GetRightChild()) rt->sum += rt->GetRightChild()->sum;
    }

public:
    SegTree(int l,int r){
        root = new SegNode(l,r);
    }

    SegTree(int l,int r,vector<int>& nums){
        root = new SegNode(l,r);
        build(root,nums);
    }

    void Update(int l,int r,int val){
        update(root,l,r,val);
    }   

    int Query(int l,int r){
        return query(root,l,r);
    }
};


class NumArray {
public:
    SegTree* root;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        root = new SegTree(0,n-1,nums);
    }

    void update(int index, int val) {
        root->Update(index,index,val);
    }
    
    int sumRange(int left, int right) {
        return root->Query(left,right);
    }
};