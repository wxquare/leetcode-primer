#include <vector>
using namespace std;


const int MX = 1e5;

// 预处理
vector<int> primes;
int init = [](){
    vector<bool> isPrime = vector<bool>(MX,true);
    for(int i=2;i<=MX;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j=1LL*i*i;j<=MX;j+=i){
                isPrime[j] = false;
            }
        }
    }
    return 0;
}();

class Solution{
public:
    int maximumScore(vector<int>& nums,int x){
        /*
            [2,3,5,7,11,13,,17,19,23]

            原数组：                  [19,12,14,6,10,18]
            质因子数量                 [1,2,2,2,2,2]
            选择当前数据时，子数组的数量   
            count = 向右找质因子数量<=x + 向左找质因子数量<x 
            []
                          [a,b,c,x,e,d,f]
                          []
        */ 
        int n = nums.size();
        vector<int> counts(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<i && j<primes.size();j++){
                if(nums[i] % nums[j] == 0){
                    counts[i]++;
                }
            }
        }



    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
