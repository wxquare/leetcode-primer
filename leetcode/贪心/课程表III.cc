class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        /*
            最多可以修的课程数量
            1. 贪心。数据中包含两个维度，时间和持续时间，无论是根据结束时间还是持续时间都不好贪心，能不能先处理一下，然后再贪心，单调栈？
            2. 
        */
        sort(courses.begin(),courses.end(),[&](const vector<int>& v1,const vector<int>& v2){
            return v1[1] < v2[1];
        });
        priority_queue<int> q;
        int sum = 0;
        for(int i=0;i<courses.size();i++){
            int start = courses[i][1] - courses[i][0]+1;
            if(start > sum){
                sum += courses[i][0];
                q.push(courses[i][0]);
            } else {
                if(!q.empty() && q.top() > courses[i][0]){
                    sum -= q.top();
                    sum += courses[i][0];
                    q.pop();
                    q.push(courses[i][0]);
                }
            }
        }
        return q.size();
    }
};