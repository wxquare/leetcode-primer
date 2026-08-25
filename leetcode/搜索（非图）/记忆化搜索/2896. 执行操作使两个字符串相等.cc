class Solution1 {
public:
    int minOperations(string s1, string s2, int x) {
        int n = s1.length();
        vector<int> nums;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]){
                nums.push_back(i);
            }
        }
        if(nums.size() % 2 == 1) return -1; 
        int sz = nums.size();
        vector<bool> mask(sz,false);
        map<vector<bool>,int> m;
        function<int(int,vector<bool>&)> dfs = [&](int i,vector<bool>& mask)->int {
            if(i == sz) return 0;
            if(m.count(mask)) {
                return m[mask];
            }
            if(mask[i] == true) return dfs(i+1,mask);
            int ans = INT_MAX / 2;
            for(int j=i+1;j<sz;j+=2){
                if(mask[j]) continue;
                mask[i] = true;
                mask[j] = true;
                int t = min(nums[j]-nums[i],x) + dfs(i+1,mask);
                mask[i] = false;
                mask[j] = false;
                ans = min(t,ans);
            }
            m[mask] = ans;
            return ans;
        };
        return dfs(0,mask);
    }
};


class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int n = s1.length();
        int c1 = 0,c2 = 0;
        for(int i=0;i<s1.length();i++){
            if(s1[i] == '1') c1++;
            if(s2[i] == '1') c2++;
        }
        if(c1 % 2 != c2 % 2) return -1;

        int memo[n][n+1][2];
        memset(memo,-1,sizeof(memo));
        function<int(int,int,bool)> dfs = [&](int i,int j,bool pre_rev) -> int {
            if(i == n){
                if(j > 0 || pre_rev) {
                    return INT_MAX / 2;
                }
                return 0;
            }
            if(memo[i][j][pre_rev] != -1) return memo[i][j][pre_rev] ;
            int ans = INT_MAX;
            if(pre_rev){
                if(s1[i] != s2[i]){
                    return dfs(i+1,j,false);
                } else {
                    return dfs(i+1,j,true) + 1;
                }
            } else {
                if(s1[i] == s2[i]){
                    return dfs(i+1,j,false);
                } 
            }
            ans = min(ans,dfs(i+1,j,true)+1);
            ans = min(ans,dfs(i+1,j+1,false)+x);
            if(j) ans = min(ans,dfs(i+1,j-1,false));
            memo[i][j][pre_rev] = ans;
            return ans;
        };
        return dfs(0,0,false);
    }
};