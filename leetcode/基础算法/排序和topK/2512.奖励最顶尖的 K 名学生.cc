struct stu{
    int id;
    int score;
    stu(int i,int s):id(i),score(s){}
    bool operator<(const stu & other) const {
        if(score < other.score) return true;
        if(score == other.score){
            return id > other.id;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> positives;
        unordered_set<string> negatives;
        for(auto & s : positive_feedback){
            positives.insert(s);
        }
        for(auto & s : negative_feedback){
            negatives.insert(s);
        }
        unordered_map<int,int> stus;
        int n = report.size();
        for(int i=0;i<n;i++){
            int start = 0;
            if(stus.count(student_id[i]) == 0){
                stus[student_id[i]] = 0;
            }
            for(int j=0;j<=report[i].length();j++){
                if(j == report[i].length() || report[i][j] == ' '){
                    string s = report[i].substr(start,j - start);
                    start = j + 1;
                    if(positives.count(s)) stus[student_id[i]] += 3;
                    if(negatives.count(s)) stus[student_id[i]] -= 1;
                }
            }
        }

        priority_queue<stu> pq;
        for(auto it : stus){
            pq.push({it.first,it.second});
        }
        
        vector<int> ans(k,0);
        for(int i=0;i<k;i++){
            auto cur = pq.top();
            pq.pop();
            ans[i] = cur.id;
        }
        return ans;
    }
};