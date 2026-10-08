/*

存在一个由 n 个节点组成的无向连通图，图中的节点按从 0 到 n - 1 编号。

给你一个数组 graph 表示这个图。其中，graph[i] 是一个列表，由所有与节点 i 直接相连的节点组成。

返回能够访问所有节点的最短路径的长度。你可以在任一节点开始和停止，也可以多次重访节点，并且可以重用边。

方法一：状态压缩 + 广度优先搜索
思路与算法

由于题目需要我们求出「访问所有节点的最短路径的长度」，并且图中每一条边的长度均为 111，因此我们可以考虑使用广度优先搜索的方法求出最短路径。

在常规的广度优先搜索中，我们会在队列中存储节点的编号。对于本题而言，最短路径的前提是「访问了所有节点」，因此除了记录节点的编号以外，我们还需要记录每一个节点的经过情况。因此，我们使用三元组 (u,mask,dist)(u, \textit{mask}, \textit{dist})(u,mask,dist) 表示队列中的每一个元素，其中：

uuu 表示当前位于的节点编号；

mask\textit{mask}mask 是一个长度为 nnn 的二进制数，表示每一个节点是否经过。如果 mask\textit{mask}mask 的第 iii 位是 111，则表示节点 iii 已经过，否则表示节点 iii 未经过；

dist\textit{dist}dist 表示到当前节点为止经过的路径长度。

这样一来，我们使用该三元组进行广度优先搜索，即可解决本题。初始时，我们将所有的 (i,2i,0)(i, 2^i, 0)(i,2 
i
 ,0) 放入队列，表示可以从任一节点开始。在搜索的过程中，如果当前三元组中的 mask\textit{mask}mask 包含 nnn 个 111（即 mask=2n−1\textit{mask} = 2^n - 1mask=2 
n
 −1），那么我们就可以返回 dist\textit{dist}dist 作为答案。

细节

为了保证广度优先搜索时间复杂度的正确性，即同一个节点 uuu 以及节点的经过情况 mask\textit{mask}mask 只被搜索到一次，我们可以使用数组或者哈希表记录 (u,mask)(u, \textit{mask})(u,mask) 是否已经被搜索过，防止无效的重复搜索。

作者：力扣官方题解
链接：https://leetcode.cn/problems/shortest-path-visiting-all-nodes/solutions/918311/fang-wen-suo-you-jie-dian-de-zui-duan-lu-mqc2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q;
        vector<vector<int>> seen(n, vector<int>(1 << n));
        for (int i = 0; i < n; ++i) {
            q.emplace(i, 1 << i, 0);
            seen[i][1 << i] = true;
        }

        int ans = 0;
        while (!q.empty()) {
            auto [u, mask, dist] = q.front();
            q.pop();
            if (mask == (1 << n) - 1) {
                ans = dist;
                break;
            }
            // 搜索相邻的节点
            for (int v: graph[u]) {
                // 将 mask 的第 v 位置为 1
                int mask_v = mask | (1 << v);
                if (!seen[v][mask_v]) {
                    q.emplace(v, mask_v, dist + 1);
                    seen[v][mask_v] = true;
                }
            }
        }
        return ans;
    }
};