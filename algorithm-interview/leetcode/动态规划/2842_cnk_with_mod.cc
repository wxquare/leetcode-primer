#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    const int MOD = 1e9 + 7;
    int cnkWithMOD(int n,int k){
        long long numerator = 1;
        long long denominator = 1;

        for(int i=0;i<k;i++){
            numerator = numerator * (n - i) % MOD;
            denominator = denominator * (i+1) % MOD;
        }
        return (numerator * powWithMod(denominator,MOD - 2)) % MOD;
    }

    int powWithMod(long long n,long long k){
        k = k % MOD;
        long long ans = 1;
        while(k){
            if((k & 1) == 1){
                ans = (ans * n) % MOD;
            }
            n = (n * n) % MOD;
            k = k / 2;
        }
        return ans % MOD;
    }

    int countKSubsequenceWithMaxBeauty(string s,int k){
        vector<int> cnt(26,0);

        for(int i=0;i<s.length();i++){
            cnt[s[i] - 'a']++;
        }

        sort(cnt.begin(),cnt.end(),[](int x,int y){
            return x > y;
        });

        if(k > 26 || cnt[k-1] == 0) return 0;

        long long ans = 1;

        int must = 0;
        int candidates = 0;
        int i = 0;
        for(i=0;i<26;i++){
            if(cnt[i] > cnt[k-1]){
                ans = ans * cnt[i] % MOD;
                must++;
            } else if(cnt[i] == cnt[k-1]){
                candidates++;
            } else {
                break;
            }
        }
        ans = ans * cnkWithMOD(candidates,k - must) * powWithMod(cnt[k-1],k-must) % MOD;
        return ans;
    }
};