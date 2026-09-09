struct SegNode {
    int left,right;
    SegNode *leftChild,*rightChild;
    int maxVal;
    int lazy;
    SegNode(int l,int r){
        left = l,right = r;
        leftChild = nullptr;
        rightChild = nullptr;
        maxVal = 0;
        lazy = 0;
    }
    SegNode* getLeftChild(){
        if(leftChild) return leftChild;
        if(left == right) return nullptr;
        int mid = left + (right - left) / 2;
        leftChild = new SegNode(left,mid);
        return leftChild;
    }

    SegNode* getRightChild(){
        if(rightChild) return rightChild;
        if(left == right) return nullptr;
        int mid = left + (right - left) / 2;
        rightChild = new SegNode(mid+1,right);
        return rightChild;
    }
};

class SegTree {
public:
    SegNode* root;
    SegTree(int l,int r){
        root = new SegNode(l,r);
    }
    void pushDown(SegNode* cur){
        if(cur->lazy == 0) return;
        SegNode* ll = cur->getLeftChild();
        if(ll){
            ll->lazy = max(ll->lazy,cur->lazy);
            ll->maxVal = max(ll->maxVal,cur->lazy);
        }
        SegNode* rr = cur->getRightChild();
        if(rr){
            rr->lazy = max(rr->lazy,cur->lazy);
            rr->maxVal = max(rr->maxVal,cur->lazy);
        }
    }

    void pushUp(SegNode* cur){
        cur->maxVal = 0;
        SegNode* ll = cur->getLeftChild();
        if(ll) cur->maxVal = max(cur->maxVal,ll->maxVal);
        SegNode* rr = cur->getRightChild();
        if(rr) cur->maxVal = max(cur->maxVal,rr->maxVal);
    }

    void update(int l,int r,int val){
        function<void(SegNode*)> update = [&](SegNode* cur){
            if(cur == nullptr) return;
            // 不包含
            if(max(cur->left,l) > min(cur->right,r)){
                return;
            }
            // 全包含
            if(cur->left >= l && cur->right <= r){
                cur->lazy = max(cur->lazy,val);
                cur->maxVal = max(cur->maxVal,val);
                return;
            }
            pushDown(cur);
            update(cur->getLeftChild());
            update(cur->getRightChild());
            pushUp(cur);
        };
        return update(root);
    }

    int query(int l,int r){
        function<int(SegNode*)> query = [&](SegNode* cur)->int{
            if(cur == nullptr) return 0;
            // 不包含
            if(max(cur->left,l) > min(cur->right,r)){
                return 0;
            }
            // 全包含
            if(cur->left >= l && cur->right <= r){
                return cur->maxVal;
            }
            pushDown(cur);
            return max(query(cur->getLeftChild()),query(cur->getRightChild()));
        };
        return query(root);
    }
};


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> boundaries;
        for (auto& building : buildings) {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());
        SegTree* root = new SegTree(boundaries[0],boundaries.back());
        for(auto b : buildings){
            root->update(b[0],b[1]-1,b[2]);
        }
        vector<vector<int>> ret;
        for (auto& boundary : boundaries) {
            int maxn = root->query(boundary,boundary);
            if (ret.size() == 0 || maxn != ret.back()[1]) {
                ret.push_back({boundary, maxn});
            }
        }
        return ret;
    }
};