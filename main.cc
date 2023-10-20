#include <iostream>
#include <algorithm>
using namespace std;

// 线段树,动态开点
struct SegNode {
    int l,r; // 节点表示的范围 [left,right]
    SegNode *leftChild,*rightChild; // 左右孩子节点
    int aggregate;// 区间聚合值,比如区间和，区间最大值
    int lazy;

    SegNode(int l,int r) : l(l),r(r){
        lazy = -1;
        aggregate = -1;
    }

    SegNode* getLeftChild(){
        if(leftChild) return leftChild;
        if(l == r) return nullptr; // 叶子节点
        int mid = l + (r - l) / 2;
        leftChild = new SegNode(l,mid); 
        return leftChild;
    }

    SegNode* getRightChild(){
        if(rightChild) return rightChild;
        if(l == r) return nullptr; //叶子节点
        int mid = l + (r - l) / 2;
        rightChild = new SegNode(mid+1,r);
        return rightChild;
    }
};

class SegTree{
private:
    void pushDown(SegNode* rt){
        if(rt->lazy == -1) return; // 没有需要pushdown的lazy值
        SegNode* ll = rt->getLeftChild();
        if(ll){
            ll->lazy = rt->lazy;
            ll->aggregate = rt->lazy; // 聚合值为最大值
        }
        SegNode* rr = rt->getRightChild();
        if(rr){
            rr->lazy = rt->lazy;
            rr->aggregate = rt->lazy; // 聚合值为最大值
        }
        rt->lazy = -1;
    }

    void pushUp(SegNode* rt){
        if(rt->getLeftChild()){
            rt->aggregate = max(rt->getLeftChild()->aggregate,rt->aggregate);
        }

        if(rt->getRightChild()){
            rt->aggregate = max(rt->getRightChild()->aggregate,rt->aggregate);
        }
    }

    void update(SegNode* rt,int l,int r,int v){
        // 不包含
        if(max(rt->l,l) > min(rt->r,r)) return;
        // 全包含
        if(rt->l >= l && rt->r <=r){
            rt->lazy = v;
            rt->aggregate = v; // 区间最大值
        }
        pushDown(rt);
        if(rt->getLeftChild()){
            update(rt->getLeftChild(),l,r,v);
        }
        if(rt->getRightChild()){
            update(rt->getRightChild(),l,r,v);
        }
        pushUp(rt);
    }

    int query(SegNode* rt,int l,int r){
        if(rt == nullptr) return -1;
        // 不包含
        if(max(rt->l,l) > min(rt->r,r)) return -1;

        // 全包含
        if(rt->l >= l && rt->r <= r){
            return rt->aggregate;
        }
        return max(query(rt->getLeftChild(),l,r),query(rt->getRightChild(),l,r));
    }
public:
    SegNode* root;

    SegTree(int l,int r){
        root = new SegNode(l,r);
    }
    // 区间更新
    void Update(int l,int r,int v){
        update(root,l,r,v);
    }
    // 区间查询
    int Query(int l,int r){
        return query(root,l,r);
    }
};

int main(){
    SegTree* st = new SegTree(1,10);
    st->Update(2,4,2);
    st->Update(3,4,5);
    st->Update(4,4,1);
    std::cout << st->Query(1,3) << std::endl;
    return 0;
}