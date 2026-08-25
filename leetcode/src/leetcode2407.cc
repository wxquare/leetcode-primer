#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


const int defaultLazy = 0;
const int defaultAggregate = 0;


struct SegNode {
    int l,r;
    int lz,ag;
    SegNode *lchild,*rchild;

    SegNode(int l_,int r_){
        l = l_,r = r_;
        lz = defaultLazy,ag = defaultAggregate;
        lchild = nullptr,rchild = nullptr;
    }

    inline SegNode *getLeft(){
        if(lchild) return lchild;
        if(l == r) return nullptr; // leaf node;
        lchild = new SegNode(l,(l+r)/2);
        return lchild;
    }

    inline SegNode* getRight(){
        if(rchild) return rchild;
        if(l == r) return nullptr;
        rchild = new SegNode((l+r)/2+1,r);
        return rchild;
    }
};

class SegTree {
private:
    inline void pushdown(SegNode* rt){
        if(rt->lz == defaultLazy) return;
        SegNode* ll = rt->getLeft();
        if(ll){
            ll->lz = rt->lz;
            ll->ag = max(ll->ag,rt->ag);
        }
        SegNode* rr = rt->getRight();
        if(rr){
            rr->lz = rt->lz;
            rr->ag = max(rr->ag,rt->ag);
        }
        rt->lz = defaultLazy; // 恢复默认值
    }

    inline void pushup(SegNode* rt){
        SegNode* ll = rt->getLeft();
        if(ll){
            rt->ag = max(ll->ag,rt->ag);
        }
        SegNode* rr = rt->getRight();
        if(rr){
            rt->ag = max(rr->ag,rt->ag);
        }
    }

public:
    SegNode* root;

    SegTree(int l,int r){
        root = new SegNode(l,r);
    }

    // update range
    // 将区间内所有值修改为val
    void update(int l,int r,int val){
        function<void(SegNode*)> dfs = [&](SegNode* rt){
            // 结点不包含要修改的区间[l,r]
            if(rt == nullptr || max(rt->l,l) > min(rt->r,r)) return;
            // 节点完全再要改的区间[l,r] 范围内
            if(rt->l >= l && rt->r <= r){
                rt->lz = val;
                rt->ag = val;
            }
            pushdown(rt);
            dfs(rt->getLeft());
            dfs(rt->getRight());
            pushup(rt);
        };
        dfs(root);
    }

    int query(int l,int r){
        function<int(SegNode*)> dfs = [&](SegNode* rt) -> int {
            if(rt == nullptr || max(rt->l,l) > min(rt->r,r)) {
                return defaultAggregate;
            }
            if(rt->l >= l && rt->r <= r){
                return rt->ag;
            }
            return max(dfs(rt->getLeft()),dfs(rt->getRight()));
        };
        return dfs(root);
    }

};



class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {

        /* 
            1. 动态规划
            2. 子问题，dp[nums[i]] 表示以nums[i] 为结尾的最长子序列的长度
            3. 状态转移： dp[nums[i]] = max(dp[nums[i]],j); (nums[i]-k<j<nums[i])
            4. 暴力dp,时间复杂为O(n^2)
        */

        int mx = *max_element(nums.begin(),nums.end());
        vector<int> dp(mx+1);
        SegTree* st = new SegTree(0,mx);
        int ans = 0;
        for(int & num : nums){
            dp[num] = st->query(max(0,num - k),num-1) + 1;
            st->update(num,num,dp[num]);
            ans = max(ans,dp[num]);
        }
        return ans;
    }
};
