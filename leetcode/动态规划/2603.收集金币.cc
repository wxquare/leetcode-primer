class Solution {
private:
vector<int> ans1;
vector<vector<int>> cnt;
vector<vector<int>> rootedcnt;
vector<vector<int>> g;
vector<int> ans2;
int n;
void dfs1(int u,int fa,vector<int> & coins)
{
    if(coins[u]) cnt[u][0]++;
    for(auto & v:g[u])
    {
        if(v==fa) continue;
        dfs1(v,u,coins);
        //若必须走到v,直接从其答案的基础上再加上2.表示u->v 后 v->u.
        if(ans1[v]) ans1[u]+=(ans1[v]+2);
        else 
        {  
            //若v子树中存在距离>=2的点.没有办法了.必须走过去.
            if(cnt[v][2]) ans1[u]+=2;
        }
        for(int i = 0;i<2;i++) {
            cnt[u][i+1]+=cnt[v][i];
        }
        cnt[u][2]+=cnt[v][2];
    }
}
//考虑如何换根?
void dfs2(int u,int fa)
{
    for(auto & v:g[u])
    {
        if(v==fa) continue;
        //考虑一下,当u、v父子关系时反转时,u的答案就是把原本v的贡献拿掉.
        int cur = ans2[u];
        if(ans1[v]) cur-=(ans1[v]+2);
        else if(cnt[v][2]) cur-=2;
        ans2[v] = ans1[v];
        if(cur) ans2[v]+=(ans2[u]+2);
        //否则同样地,考察此时的u有多少cnt.如果我们能得到一个rootedcnt就好了.
        else if(rootedcnt[u][2]-cnt[v][1]-cnt[v][2]) ans2[v]+=2;

        rootedcnt[v] = cnt[v];
        int c0 = rootedcnt[u][0],c1 = rootedcnt[u][1],c2 = rootedcnt[u][2];
        c1-=cnt[v][0];
        c2-=(cnt[v][1]+cnt[v][2]);
        rootedcnt[v][1]+=c0;
        rootedcnt[v][2]+=(c1+c2);
        dfs2(v,u);
    }
}
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        //先考虑定根的树形dp.
        this->n = coins.size();
        g.resize(n);
        cnt = vector<vector<int>>(n,vector<int>(3,0));
        ans1.resize(n,0);
        ans2.resize(n);
        rootedcnt = vector<vector<int>>(n,vector<int>(3,0));
        for(auto & x:edges)
        {
            g[x[0]].emplace_back(x[1]);
            g[x[1]].emplace_back(x[0]);
        }
        
        dfs1(0,-1,coins);
        ans2[0] = ans1[0];
        rootedcnt[0] = cnt[0];

        dfs2(0,-1);
        int res = 2*n;
        for(int i = 0;i<n;i++) res = min(res,ans2[i]);
        return res;
    }
};