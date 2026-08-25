class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto p : prerequisites){
            g[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int next : g[cur]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};