class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(numCourses);
        vector<vector<bool>> m(numCourses,vector<bool>(numCourses,false));
        vector<int> indegree(numCourses);
        for(auto p : prerequisites){
            g[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }
        vector<bool> visited(numCourses,false);
        function<void(int)> dfs = [&](int x){
            for(int y : g[x]){
                m[y][x] = true;
                for(int i=0;i<numCourses;i++){
                    if(m[x][i]){
                        m[y][i] = true;
                    }
                }
                indegree[y]--;
                if(indegree[y] == 0 && visited[y] == false){
                    visited[y] = true;
                    dfs(y);
                }
            }
        };

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0 && visited[i] == false){
                dfs(i);
            }
        }

        vector<bool> ans;
        for(auto q : queries){
            ans.push_back(m[q[1]][q[0]]);
        }
        return ans;
    }
};