class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        /*
            1. n个节点，n调变，至少有一个环。通常为环+额外的节点
        */

        int n = edges.size();
        vector<int> re[n];
        for(int i=0;i<n;i++){
            re[edges[i]].push_back(i);
        }
        int vis[n];
        memset(vis,0,sizeof(vis));
        int dis[n];
        memset(dis,-1,sizeof(dis));
        vector<int> ans(n);
        for(int s = 0;s<n;s++){
            if(dis[s] != -1) continue;
            int now = s;
            int cnt = 1;
            for(;vis[now]==0;now = edges[now],cnt++){
                vis[now] = cnt;
            }
            int loop = cnt - vis[now];

            queue<int> q;
            q.push(now);
            dis[now] = 0;
            for(int sn = edges[now];sn!=now;sn=edges[sn]){
                q.push(sn);
                dis[sn] = 0;
            }

            while(!q.empty()){
                int sn = q.front();
                q.pop();
                ans[sn] = dis[sn] + loop;
                for(auto fn : re[sn]){
                    if(dis[fn] == -1){
                        q.push(fn);
                        dis[fn] = dis[sn] + 1;
                    }
                }
            }
        }
        return ans;
    }
};