/*
城市用一个 双向连通 图表示，图中有 n 个节点，从 1 到 n 编号（包含 1 和 n）。图中的边用一个二维整数数组 edges 表示，其中每个 edges[i] = [ui, vi] 表示一条节点 ui 和节点 vi 之间的双向连通边。每组节点对由 最多一条 边连通，顶点不存在连接到自身的边。穿过任意一条边的时间是 time 分钟。

每个节点都有一个交通信号灯，每 change 分钟改变一次，从绿色变成红色，再由红色变成绿色，循环往复。所有信号灯都 同时 改变。你可以在 任何时候 进入某个节点，但是 只能 在节点 信号灯是绿色时 才能离开。如果信号灯是  绿色 ，你 不能 在节点等待，必须离开。

第二小的值 是 严格大于 最小值的所有值中最小的值。

例如，[2, 3, 4] 中第二小的值是 3 ，而 [2, 2, 4] 中第二小的值是 4 。
给你 n、edges、time 和 change ，返回从节点 1 到节点 n 需要的 第二短时间 。

注意：

你可以 任意次 穿过任意顶点，包括 1 和 n 。
你可以假设在 启程时 ，所有信号灯刚刚变成 绿色 。


输入：n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
输出：13
解释：
上面的左图展现了给出的城市交通图。
右图中的蓝色路径是最短时间路径。
花费的时间是：
- 从节点 1 开始，总花费时间=0
- 1 -> 4：3 分钟，总花费时间=3
- 4 -> 5：3 分钟，总花费时间=6
因此需要的最小时间是 6 分钟。

右图中的红色路径是第二短时间路径。
- 从节点 1 开始，总花费时间=0
- 1 -> 3：3 分钟，总花费时间=3
- 3 -> 4：3 分钟，总花费时间=6
- 在节点 4 等待 4 分钟，总花费时间=10
- 4 -> 5：3 分钟，总花费时间=13
因此第二短时间是 13 分钟。

*/
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
   1. 第二短路
   2. 动态边权
   3. 单源最短路，从1到n的
*/

struct Node{
    int dis;
    int index;
    Node(int d,int i) : dis(d),index(i){}
    bool operator< (const Node& a) const {
        return this->dis > a.dis;
    }
};

class Solution_Dijkstra {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        priority_queue<Node> pq;

        // 无向图,稀疏
        unordered_map<int,vector<int>> g;
        for(auto e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        } 
           
        vector<int> dis1(n+1,INT_MAX/2);
        vector<int> dis2(n+1,INT_MAX/2);
        pq.push({0,1});
        while(!pq.empty()){
            auto no = pq.top();
            pq.pop();
            int dis = no.dis;
            int cur = no.index;
            for(auto next : g[cur]){
                int a = dis / change, b = dis % change;
                int wait = a % 2 == 0 ? 0 : change - b;
                int nd = dis + time + wait;
                if(nd < dis1[next]){
                    dis2[next] = dis1[next];
                    dis1[next] = nd;
                    pq.push({dis1[next],next});
                    pq.push({dis2[next],next});
                }else if(nd > dis1[next] && nd < dis2[next]){
                    dis2[next] = nd;
                    pq.push({dis2[next],next});
                }
            }
        }
        return dis2[n];   
    }
};




class Solution_Astar {
public:
    // 最短路,终点到其它点的最短距路
    vector<int> bfs(int n,unordered_map<int,vector<int>>& g){
        vector<int> dis(n+1,INT_MAX);
        queue<int> q;
        q.push(n);
        dis[n] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int next : g[cur]){
                if(dis[next] != INT_MAX) continue;
                dis[next] = dis[cur] + 1;
                q.push(next);
            }
        }
        return dis;
    }

    struct Node {
        int i;
        int g;
        int h;
        Node(int a,int b,int c):i(a),g(b),h(c){}
        bool operator<(const Node& other) const{
            return g+h > other.g + other.h;
        }
    };

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // 无向图,稀疏
        unordered_map<int,vector<int>> gr;
        for(auto e : edges){
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        } 
        vector<int> dis = bfs(n,gr);
        priority_queue<Node> pq;
        pq.push({1,0,dis[1]});
        int step = -1;
        int K = 2;
        while(!pq.empty()){
            auto [cur,g,h] = pq.top();
            pq.pop();
            if(cur == n && step != g){
                step = g;
                K--;
                if(K == 0){
                    break;
                }
            }
            for(int next : gr[cur]){
                pq.push({next,g+1,dis[next]});
            }
        }
        int ans = 0;
        for(int i=0;i<step;i++){
            int a = ans/change,b=ans%change;
            int wait = a % 2 == 0 ? 0 : change - b;
            ans += time + wait;
        }
        return ans;
    }
};


int main(){
    vector<vector<int>> edges = {{1,2}};
    std::cout << Solution_Astar().secondMinimum(2,edges,3,2) << std::endl;
}