class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> pa(n+1);
        vector<int> cnt(n+1,1);
        iota(pa.begin(),pa.end(),0);
        function<int(int)> find = [&](int x){
            return x == pa[x] ? x : pa[x] = find(pa[x]);
        };
        function<void(int,int)> merge = [&](int x,int y){
            int px = find(x);
            int py = find(y);
            if(px == py) return;
            if(cnt[px] < cnt[py]){
                swap(px,py);
            }
            pa[py] = px;
            cnt[px] += cnt[py];
        };

        vector<int> ans;
        for(auto & e : edges){
            int x = e[0], y = e[1];
            if(find(x) == find(y)){
                ans = e;
                break;
            } else {
                merge(x,y);
            }
        }
        return ans;
    }
};