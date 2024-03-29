#include <vector>
#include <iostream>
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
        update(rt->GetRightChild(),l,r,1);
        update(rt->GetLeftChild(),l,r,1);
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
        return query(root,l,r);
    }

    // 在end的左边找一个节点，使得[left,end]包含k个零
    bool binary_search(SegNode* rt,int end,int& k,int& left){
        if(rt->R == end){
            // 区间内0的数量
            int cnt = rt->R - rt->L + 1 - rt->sum;
            if(cnt == k){
                left = rt->L;
                return true; // 结束
            } else if(cnt < k){
                k -= cnt;
                return false;
            } 
        } 
        int mid = (rt->L + rt->R) / 2;
        //终点在左子树
        if(end <= mid){
            return binary_search(rt->GetLeftChild(),end,k,left);
        } else {
            int ret = binary_search(rt->GetRightChild(),end,k,left);
            if(!ret) return binary_search(rt->GetLeftChild(),mid,k,left);
        }
        return true;
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

            // 线段树中使用二分查找更新的左端点,使得end点左右包含d个0值
            int left;
            tr->binary_search(tr->root,end,d,left);
            tr->Update(left,end,1); 
        }
        return tr->root->sum;
    }
};

int main(int argc, char const *argv[]){
<<<<<<< HEAD
    vector<int> nums = {1,3,5,7};
    std::cout << Solution().findSmallestInteger(nums,2) << std::endl;
=======
    /* code */
    Solution* so = new Solution();
    vector<vector<int>> tasks = {{1,2000,2000}};
    std::cout << so->findMinimumTime(tasks) << std::endl;
>>>>>>> c85ee50fb7b94e663304b58b9851f33b989dc56c
    return 0;
}
