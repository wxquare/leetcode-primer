#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    int longestCycle(vector<int>& edges){
        int n = edges.size();
        vector<int> in(n);
        for(int v : edges){
            if(v >=0 && v <n){
                in[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }   
        int ans = 0;
        while(q.empty()){
            int cur = q.front();
            q.pop();
            int next = edges[cur];
            if(next >= 0 && next < n){
                if(--edges[next] == 0){
                    q.push(next);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(in[i] == 0) continue;

            int j = edges[i];
            int ringSize = 1;
            for(;j!=i;j=edges[i]){
                ringSize++;
                in[j]--;
            }
            ans = max(ans,ringSize);
        }
    }
};
