const int MOD = 1e9 + 7;

struct SegNode{
    int l,r; // 范围[l,r]
    long long lz;
    long long sum;
    SegNode *ll,*rr; 
    SegNode(int l0,int r0){
        l = l0,r = r0;
        lz = 0,sum = 0;
        ll = nullptr,rr = nullptr;
    }
    inline SegNode* getLeftChild(){
        if(ll) return ll;
        if(l >= r) return nullptr;
        int mid = l + (r - l) / 2;
        ll = new SegNode(l,mid);
        return ll;
    }
    inline SegNode* getRightChild(){
        if(rr) return rr;
        if(l >= r) return nullptr;
        int mid = l + (r - l) / 2;
        rr = new SegNode(mid+1,r);
        return rr;
    }
};

class SegTree {
public:
    SegNode* root;
    int l,r;

    SegTree(int l0,int r0){
        root = new SegNode(l0,r0);
        l = l0;
        r = r0;
    }
    inline void pushDown(SegNode* rt){
        if(rt->lz == 0) return;
        SegNode* ll = rt->getLeftChild();
        if(ll){
            ll->lz += rt->lz;
            ll->sum = ll->sum + 1LL * (ll->r - ll->l + 1) * rt->lz;
        }
        SegNode* rr = rt->getRightChild();
        if(rr){
            rr->lz += rt->lz;
            rr->sum = rr->sum + 1LL * (rr->r - rr->l + 1) * rt->lz;
        }
        rt->lz = 0;
    };
    inline void pushUp(SegNode* rt) {
        rt->sum = 0;
        SegNode* ll = rt->getLeftChild();
        if(ll) rt->sum += ll->sum;
        SegNode* rr = rt->getRightChild();
        if(rr) rt->sum += rr->sum;
    };
    void add(int l,int r,int val){
        function<void(SegNode*)> add = [&](SegNode* rt){
            // 不包含
            if(max(rt->l,l) > min(rt->r,r)){
                return;
            }
            // 全包含
            if(rt->l >= l && rt->r <= r){
                rt->lz += val;
                rt->sum += (rt->r - rt->l + 1) * val;
                return;
            }
            // 部分包含
            pushDown(rt);
            SegNode* ll = rt->getLeftChild();
            if(ll) add(ll);
            SegNode* rr = rt->getRightChild();
            if(rr) add(rr);
            pushUp(rt);
        };
        add(root);
    }

    long long query(int l,int r){
        function<long long(SegNode*)> query = [&](SegNode* rt)->long long{
            if(rt == nullptr) return 0;
            // 不包含
            if(max(rt->l,l) > min(rt->r,r)){
                return 0;
            }
            // 全包含
            if(rt->l >= l && rt->r <= r){
                return rt->sum;
            }
            if(rt->lz != 0){
                pushDown(rt);
            }
            return query(rt->getLeftChild()) + query(rt->getRightChild());
        };
        return query(root);
    }
};

class Solution {
public:
    int sumCounts(vector<int> &nums) {
        int n = nums.size();
        SegTree* root = new SegTree(0,n);
        unordered_map<int, int> last;
        long long ans = 0, s = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int j = last.count(x) ? last[x] : -1;
            s = s + 0LL + 1LL * root->query(j+1,i) * 2 + i - j;
            ans = (ans + s) % MOD;
            root->add(j+1,i,1);
            last[x] = i;
        }
        return ans;
    }
};
