#include <vector>
using namespace std;
class TreeAncestor {
    vector<vector<int>> up;

public:
    TreeAncestor(int n, vector<int>& parent) {
        up.push_back(parent);
        for (int j = 1; j < 31; j++) {
            up.push_back(vector<int>(n, -1));
            for (int i = 0; i < n; i++)
                if (up[j - 1][i] >= 0) up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }
    int getKthAncestor(int node, int k) {
        for (int j = 0; k; j++, k >>= 1)
            if (k & 1) node = node < 0 ? -1 : up[j][node];
        return node;
    }
};
