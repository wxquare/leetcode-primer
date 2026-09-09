/*
    667. 优美的排列 II

    给你两个整数 n 和 k ，请你构造一个答案列表 answer ，该列表应当包含从 1 到 n 的 n 个不同正整数，并同时满足下述条件：

    假设该列表是 answer = [a1, a2, a3, ... , an] ，那么列表 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数。
    返回列表 answer 。如果存在多种答案，只需返回其中 任意一种 。

    输入：n = 3, k = 1
    输出：[1, 2, 3]
    解释：[1, 2, 3] 包含 3 个范围在 1-3 的不同整数，并且 [1, 1] 中有且仅有 1 个不同整数：1

    1 <= k < n <= 10^4
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {

        /*
            假如n = 5,
            k = 1, 1,2,3,4,5,6
            k = 2, 1,3,2,4,5,6
            k = 3, 1,4,2,3,5,6
            k = 4, 1,5,2,4,3,6
            k = 5, 1,6,2,5,3,4
        */
        vector<int> ans = {1};
        for(int i=k;i>0;i--){
            if((ans.size() & 1) == 1){
                ans.push_back(ans.back()+i);
            } else {
                ans.push_back(ans.back()-i);
            }
        }
        if(n < 2) return ans;
        int start = ans[1];
        while(ans.size() < n){
            start++;
            ans.push_back(start);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ans = Solution().constructArray(3,2);

    for(auto i : ans){
        std::cout << i << '\t';
    }
    std::cout << '\n';

    return 0;
}
