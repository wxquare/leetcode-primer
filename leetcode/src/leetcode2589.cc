#include <vector>
using namespace std;


struct SegNode{
    int L,R;
    int lazy,sum;
    SegNode* lchild,*rchild;
    SegNode(int l,int r){
        L = l;
        R = r;
        lazy = 0;
        sum = 0;
        lchild = nullptr;
        rchild = nullptr;
    }

    SegNode* GetLeftChild(){
        if(lchild) return lchild;
        if(L < R){
            lchild = new SegNode(L,(L + R)/2);
        }
        return lchild;
    }

    SegNode* GetRightChild(){
        if(rchild) return rchild;
        if(L < R){
            rchild = new SegNode((L+R)/2 + 1,R);
        }
        return rchild;
    }
};

class SegTree{
private:

    void push_down(SegNode* rt){
        if(rt->lazy != 0){
            SegNode* ll = rt->GetLeftChild();
            if(ll) {
                ll->lazy = rt->lazy;
                ll->sum = (ll->R - ll->L + 1) * rt->lazy;
            }
            SegNode* rr = rt->GetRightChild();
            if(rr){
                rr->lazy = rt->lazy;
                rr->sum = (rr->R - rr->L + 1) * rt->lazy;
            }
            rt->lazy = 0;
        }
    }

    void push_up(SegNode* rt){
        rt->sum = 0;
        if(rt->GetLeftChild()){
            rt->sum += rt->GetLeftChild()->sum;
        }
        if(rt->GetRightChild()){
            rt->sum += rt->GetRightChild()->sum;
        }
    }

    // rt 表示当前节点
    void update(SegNode* rt,int l,int r,int v){
        if(rt == nullptr) return;
        // 当前节点的区间范围与[l,r]无交集，不需要更新
        if(max(rt->L,l) > min(rt->R,r)){
            return;
        }

        // 当前节点范围被[l,r]完全包围
        if(rt->L >= l && rt->R <= r){
            rt->lazy = v;
            rt->sum = (rt->R - rt->L + 1) * v;
            return;
        }
        push_down(rt);
        int mid = (rt->R + rt->L) / 2;
        if(rt->R - mid - Query(rt->L,rt->R) >= v){
            update(rt->GetRightChild(),l,r,v); // 优先更新右子树,只需更新右子树
        } else {
            update(rt->GetRightChild(),l,r,1);
            update(rt->GetLeftChild(),l,r,v - (rt->R - mid - Query(rt->L,rt->R)));
        }
        push_up(rt);
    }

    int query(SegNode* rt,int l,int r){
        if(rt == nullptr) return 0;
        // 当前节点的区间范围与[l,r]无交集，不需要更新
        if(max(rt->L,l) > min(rt->R,r)){
            return 0;
        }

        // 当前节点范围被[l,r]完全包围
        if(rt->L >= l && rt->R <= r){
            return rt->sum;
        }
        push_down(rt);
        return  query(rt->GetLeftChild(),l,r) + query(rt->GetRightChild(),l,r);
    }

public:
    SegNode* root;
    SegTree(int l,int r){
        root = new SegNode(l,r);
    }
    //区间更新
    void Update(int l,int r,int v){
        update(root,l,r,v);
    }

    int Query(int l,int r){
        query(root,l,r);
    }
};


class Solution {
public:
    /*
        1. 按照右值排序，贪心
        2. 使用线段树求区间和，修改区间值
    */

    int findMinimumTime(vector<vector<int>>& tasks) {
        // 按照右值排序
        sort(tasks.begin(),tasks.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1] < b[1];
        });

        SegTree* tr = new SegTree(0,tasks.back()[1]);

        for(auto task : tasks){
            int start = task[0],end = task[1],d= task[2];
            d -= tr->Query(start,end);
            if(d <= 0) continue;
            tr->Update(start,end,d); // 如何在[star,end]区间内新增d个时间点
        }
        return tr->root->sum;
    }
};