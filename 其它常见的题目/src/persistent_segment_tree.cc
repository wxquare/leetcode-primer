#include <algorithm>
#include <vector>

class PersistentSegmentTree {
    struct Node { int left = 0, right = 0, sum = 0; };
public:
    explicit PersistentSegmentTree(int value_count) : n(value_count) { nodes.push_back({}); roots.push_back(0); }
    void append(int position) { roots.push_back(update(roots.back(), 0, n - 1, position)); }
    int kth(int left_version, int right_version, int k) const { return kth(roots[left_version], roots[right_version], 0, n - 1, k); }
private:
    int n; std::vector<Node> nodes; std::vector<int> roots;
    int clone(int index) { nodes.push_back(nodes[index]); return (int)nodes.size() - 1; }
    int update(int old, int left, int right, int position) {
        int now = clone(old); ++nodes[now].sum;
        if (left == right) return now;
        int mid = left + (right - left) / 2;
        if (position <= mid) nodes[now].left = update(nodes[old].left, left, mid, position);
        else nodes[now].right = update(nodes[old].right, mid + 1, right, position);
        return now;
    }
    int kth(int left_root, int right_root, int left, int right, int k) const {
        if (left == right) return left;
        int left_count = nodes[nodes[right_root].left].sum - nodes[nodes[left_root].left].sum, mid = left + (right - left) / 2;
        if (k <= left_count) return kth(nodes[left_root].left, nodes[right_root].left, left, mid, k);
        return kth(nodes[left_root].right, nodes[right_root].right, mid + 1, right, k - left_count);
    }
};
