#include <unordered_map>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};
class Solution {
    unordered_map<Node*, Node*> seen;
    Node* dfs(Node* n) {
        if (!n) return 0;
        if (seen.count(n)) return seen[n];
        Node* c = new Node(n->val);
        seen[n] = c;
        for (Node* x : n->neighbors) c->neighbors.push_back(dfs(x));
        return c;
    }

public:
    Node* cloneGraph(Node* node) {
        seen.clear();
        return dfs(node);
    }
};
