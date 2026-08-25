#include <vector>
#include <stack>

using namespace std;

struct Node {
    int val;
    Node *left,*right;
    Node(int x) : val(x){
        left = nullptr;
        right = nullptr;
    }
};

vector<int> preOrder(Node* rt){
    vector<int> res;
    stack<Node*> st;
    Node* cur = rt;
    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            res.push_back(cur->val);
            cur = cur->left;
        }

        if(!st.empty()){
            cur = st.top()->right;
            st.pop();
        }
    }
    return res;
}

vector<int> inOrder(Node* rt){
    vector<int> res;
    stack<Node*> st;
    Node* cur = rt;
    while(cur || !st.empty()){
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        if(!st.empty()){
            cur = st.top();
            res.push_back(cur->val);
            st.pop();
            cur = cur->right;
        }
    }
    return res;
}


vector<int> postOrder(Node* rt){
    vector<int> res;
    stack<Node*> st;

    Node* cur = rt;
    while(cur){
        st.push(cur);
        cur = cur->left;
    }
    Node* lastVisted = nullptr;
    while(!st.empty()){
        cur = st.top();
        if(cur->right == nullptr || cur->right == lastVisted){
            res.push_back(cur->val);
            lastVisted = cur;
            st.pop();
        } else {
            cur = cur->right;
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
        }
    }
    return res;
}