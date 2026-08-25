class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses,0);
        vector<vector<int>> g(numCourses);
        for(auto p : prerequisites){
            in[p[1]]++;
            g[p[0]].push_back(p[1]);
        }
        function<void(int)> dfs = [&](int x){
            for(auto y : g[x]){
                in[y]--;
                if(in[y] == 0){
                    dfs(y);
                }
            }
        };
        for(int i=0;i<numCourses;i++){
            if(in[i] == 0){
                dfs(i);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(in[i] > 0) return false;
        }
        return true;

    }
};