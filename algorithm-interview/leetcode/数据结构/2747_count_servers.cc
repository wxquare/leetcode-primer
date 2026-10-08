
/*

给你一个整数 n ，表示服务器的总数目，再给你一个下标从 0 开始的 二维 整数数组 logs ，其中 logs[i] = [server_id, time] 表示 id 为 server_id 的服务器在 time 时收到了一个请求。

同时给你一个整数 x 和一个下标从 0 开始的整数数组 queries  。

请你返回一个长度等于 queries.length 的数组 arr ，其中 arr[i] 表示在时间区间 [queries[i] - x, queries[i]] 内没有收到请求的服务器数目。

注意时间区间是个闭区间。


输入：n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11,5]
   3，10
   5，8
输出：[1,2]
解释：
对于 queries[0]：id 为 1 和 2 的服务器在区间 [5, 10] 内收到了请求，所以只有服务器 3 没有收到请求。
对于 queries[1]：id 为 2 的服务器在区间 [6,11] 内收到了请求，所以 id 为 1 和 3 的服务器在这个时间段内没有收到请求。

1. 固定窗口 + 滑动区间
*/


#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int nq = queries.size();
        vector<int> ids(nq);
        iota(ids.begin(),ids.end(),0);
        sort(ids.begin(),ids.end(),[&](int i,int j){
            return queries[i] < queries[j];
        });
        sort(logs.begin(),logs.end(),[](const vector<int>& l1,const vector<int>& l2){
            return l1[1] < l2[1];
        });

        int left = 0;
        int right = 0;
        vector<int> cnt(n);
        int out = n;
        vector<int> ans(nq);
        for(int id : ids){
            while(right < logs.size() && logs[right][1] <= queries[id]){
                if(cnt[logs[right++][0]]++ == 0){
                    out--;
                }
            }
            while(left < logs.size() && logs[left][1] < queries[id] - x){
                if(--cnt[logs[left++][0]] == 0){
                    out++;
                }
            }
            ans[id] = out;
        }
        return ans; 
    }
};





class Fenwick {
public:
    explicit Fenwick(int n): sums_(n + 1) {}

    int lowbit(int x) {
        return x&-x;
    }

    void add(int idx, int val) {
        for(++idx; idx < sums_.size(); idx += lowbit(idx)) {
            sums_[idx] += val;
        }
    }

    int query(int idx) {
        int ans = 0;
        for(++idx; idx > 0; idx -= lowbit(idx)) {
            ans += sums_[idx];
        }
        return ans;
    }

    int query(int left, int right) {
        return query(right) - query(left - 1);
    }

private:
    vector<int> sums_;
};

class Solution2 {
public:
    vector<int> countServers(int tot, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int n = logs.size(), m = queries.size();
        sort(logs.begin(), logs.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<array<int, 3>> q(m);
        for(int i = 0; i < m; i++) {
            int l = queries[i] - x, r = queries[i];
            int left = lowerBound(logs, l), right = upperBound(logs, r);
            q[i] = {left, right, i};
        }
        sort(q.begin(), q.end(), [&](array<int, 3>& a, array<int, 3>& b) {
            return a[1] < b[1];
        });
        Fenwick bit(100001);
        vector<int> pre(tot + 1, -1);
        vector<int> ans(m);
        for(int i = 0, j = 0; i < n && j < m; i++) {
            if(pre[logs[i][0]] > -1) {
                // 之前出现过就把之前的位置删掉
                bit.add(pre[logs[i][0]], -1);
            }
            // 在新位置上插入
            bit.add(i, 1);
            pre[logs[i][0]] = i;
            while(j < m && q[j][1] <= i){
                int l = q[j][0], r = q[j][1], index = q[j][2];
                if(l == -1 || r == -1) {
                    ans[index] = tot;
                }else {
                    ans[index] = l <= r? tot - bit.query(l, r): tot;
                }
                j++;
            }
        }
        return ans;
    }

    // 大于等于x的第一个数
    int lowerBound(vector<vector<int>>& logs, int x) {
        int n = logs.size();
        int l = 0, r = n - 1, ans = -1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(logs[mid][1] >= x) {
                ans = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return ans;
    }

    // 小于等于x的最后一个数
    int upperBound(vector<vector<int>>& logs, int x) {
        int n = logs.size();
        int l = 0, r = n - 1, ans = -1;
        while(l <= r) {
            int mid = l + r >> 1;
            if(logs[mid][1] <= x) {
                ans = mid;
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        return ans;
    }
};