
// class compare{
// public:
//     bool operator()(vector<int>& v1,vector<int>& v2)const{
//         return v1[0] < v1[0];
//     }
// };


#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        /*

        */
        int n = positions.size();
        set<vector<int>,less<vector<int>>> st;
        for(int i=0;i<n;i++){
            int d = directions[i] == 'L' ? 1 : 2;
            st.insert({positions[i],healths[i],d,i});
        }
        for(auto it =st.begin();it != st.end();){
            if((*it)[2] == 2){ // R
                auto pre = it;
                auto next = ++it;
                if(next == st.end()){
                    break;
                } 

                if((*next)[2] == 2){
                    it = next;
                } else { // R L
                    int x = (*pre)[1];
                    int y = (*next)[1];
                    auto itx = pre;
                    auto ity = next;
                    if(x == y){
                        if(pre != st.begin()){
                            it = --pre;
                        } else {
                            it = ++next;
                        }
                    }else if(x < y){
                        auto newnode = *ity;
                        newnode[1]--;
                        st.insert(newnode);
                        if(pre != st.begin()){
                             it = --pre;
                        } else {
                            it = ++next;
                        }
                    }else if(x > y){
                        auto newnode = *itx;
                        newnode[1]--;
                        st.insert(newnode);
                            it = pre;
                    }
                    st.erase(itx);
                    st.erase(ity);
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it=st.begin();it!=st.end();it++){
            ans.push_back({(*it)[3],(*it)[1]});
        }

        sort(ans.begin(),ans.end(),[](vector<int>& v1,vector<int>& v2){
            return v1[0] < v2[0];
        });
        vector<int> fin;
        for(auto & v : ans){
            // std::cout << v[0] << std::endl;
            fin.push_back(v[1]);
        }
        return fin;
    }
};