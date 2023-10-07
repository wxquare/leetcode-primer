class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        // 建图
        vector<vector<int>> g(n);
        for(auto e : edges){
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // 遍历树，计算每个节点遍历的次数
        vector<int> cnt(n,0);
        function<bool(int,int,int)> dfs = [&](int u,int fa,int target){
            if(u == target) return true;
            for(int v : g[u]){
                if(v != fa){
                    cnt[v]++;
                    bool find = dfs(v,u,target);
                    if(find) return find;
                    cnt[v]--;
                }
            }
            return false;
        };

        for(auto & t : trips){
            cnt[t[0]]++;
            dfs(t[0],-1,t[1]);
        }

       // tree dp
        function<pair<int,int>(int,int)> dfs2 = [&](int u,int fa)->pair<int,int> {
            int not_halve = price[u] * cnt[u];
            int halve = not_halve / 2;
            for(auto v : g[u]){
                if(v != fa){
                    auto [nh,h] = dfs2(v,u); 
                    halve += nh;
                    not_halve += min(nh,h);
                }
            }
            return {not_halve,halve};
        };
        auto [nh,h] = dfs2(0,-1);
        return min(nh,h);
    }
};