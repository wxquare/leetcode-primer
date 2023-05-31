#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

const int defaultAggregate = 0;
const int defaultLazy = 0;

struct SegNode {
    int l,r; // [l,r] range
    SegNode *lchild,*rchild; // left,right child node
    int ag; // aggregate value of the node
    int lz; // lz flag.

    SegNode(int l_,int r_){
        l = l_,r = r_;
        ag = defaultAggregate;
        lz = defaultLazy;
        lchild = nullptr,rchild = nullptr;
    }

    inline SegNode* getLeftChild(){
        if(lchild) return lchild;
        if(l == r) return nullptr; // 叶子结点
        lchild = new SegNode(l,(l+r)/2);
        return lchild;
    }
    
    inline SegNode* getRightChild(){
        if(rchild) return rchild;
        if(l == r) return nullptr;
        rchild = new SegNode((l+r)/2+1,r);
        return rchild;
    }
};


class SegTree {
private:
    int aggregate(int ag1,int ag2){
        return max(ag1,ag2);
    }

    void pushdown(SegNode* rt){
        if(rt->lz == defaultLazy) return;
        SegNode* ll = rt->getLeftChild();
        if(ll) {
            ll->lz = rt->lz;
            ll->ag = rt->lz; 
        }
        SegNode* rr = rt->getRightChild();
        if(rr){
            rr->lz = rt->lz;
            rr->ag = rt->lz;
        }
        rt->lz = defaultLazy;
    }

    void pushup(SegNode* rt){
        rt->ag = defaultAggregate;
        if(rt->getLeftChild()){
            rt->ag = max(rt->ag,rt->getLeftChild()->ag);
        }
        if(rt->getRightChild()){
            rt->ag = max(rt->getRightChild()->ag,rt->ag);
        }
    }

    void update(SegNode* rt,int l,int r,int val){
        // 不包含
        if(max(rt->l,l) > min(rt->r,r)) return;
        // 全包含
        if(rt->l >= l && rt->r <= r){
            rt->lz = val;
            rt->ag = val;
            return;
        }
        pushdown(rt);
        rt->lz = defaultLazy;
        if(rt->getLeftChild()) update(rt->getLeftChild(),l,r,val);
        if(rt->getRightChild()) update(rt->getRightChild(),l,r,val);
        pushup(rt);
    }


    int query(SegNode* rt,int l,int r){
        // 不包含
        if(max(rt->l,l) > min(rt->r,r)) {
            return defaultAggregate;
        }
        // 全包含
        if(rt->l >= l && rt->r <= r){
            return rt->ag;
        }
        return aggregate(query(rt->getLeftChild(),l,r),query(rt->getRightChild(),l,r));
    }


public:
    SegNode* root;
    SegTree(int l,int r){
        root = new SegNode(l,r);
    }

    void UpdateRange(int l,int r,int val){
        update(root,l,r,val);
    }

    int QueryRange(int l,int r){
        return query(root,l,r);
    }
};



class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
        // 去重排序
        set<int> s(nums.begin(), nums.end());
        int cnt = 0;
        unordered_map<int, int> m;
        for (int i : s) {
            m[i] = cnt++;
        }
        SegTree* st = new SegTree(0,m.size());
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int v = st->QueryRange(0,m[nums[i]]-1);
            ans = max(ans,v+1);
            st->UpdateRange(m[nums[i]],m[nums[i]],v+1);
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

