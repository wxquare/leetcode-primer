#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
   vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
       int n = nums1.size();
       int m = queries.size();
       vector<int>ans(m);

       vector<pair<int,int>>p(n);
       for(int i = 0; i < n; i++){
           p[i] = {nums1[i], nums2[i]};
       }

       for(int i = 0; i < m; i++){
           queries[i].push_back(i);
       }

       // p 是按照第一个数排序的
       sort(p.begin(), p.end(), [&](const auto &a, const auto &b){
           return a.first > b.first;
       });

        // queries 也是按照第一个数排序的
       sort(queries.begin(),queries.end(),[&](const auto &a, const auto &b){
           return a[0] > b[0];
       });
       
       vector<pair<int,int>> mono; // y, x+y
       int j = 0;
       for(int i = 0; i< m; i++) {
           while(j < n && p[j].first >= queries[i][0]) {
               while(mono.size() > 0 && mono.back().second <= p[j].first + p[j].second) {
                   mono.pop_back();
               }
               if(mono.size() == 0 || mono.back().first < p[j].second)
                   mono.push_back({p[j].second,p[j].first+p[j].second});
               j++;
           }
           if(mono.empty())
               ans[queries[i][2]] = -1;
           else {
               auto it = lower_bound(mono.begin(), mono.end(), queries[i][1],[&](const pair<int, int>&a, int value){
                   return a.first < value;
               });
               if(it != mono.end()) {
                   int index = it-mono.begin();
                   ans[queries[i][2]] = mono[index].second;
               }else
                   ans[queries[i][2]] = -1;
           }
       }
       return ans;
   }
};