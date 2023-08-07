#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorites){
        // 拓扑排序
        int n = favorites.size();
        vector<int> in(n,0);
        for(auto f : favorites){
            in[f]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        vector<int> maxDepth(n,0);
        while(q.empty()){
            int cur = q.front();
            q.pop();
            ++maxDepth[cur];
            int next = favorites[cur];
            maxDepth[next] = max(maxDepth[next],maxDepth[cur]+1);
            if(--in[next] == 0){
                q.push(next);
            }
        }
        int ans = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(in[i] == 0) continue;
            in[i] = 0;
            int ringSize = 0;
            for(int j=i;j!=i;j=favorites[i]){
                in[j] = 0;
                ringSize++;
            }

            if(ringSize == 2){
                sum += maxDepth[i] + maxDepth[favorites[i]];
            } else {
                ans = max(ans,ringSize);
            }
        }
        return max(ans,sum);
    }
};