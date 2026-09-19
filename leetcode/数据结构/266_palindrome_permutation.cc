#include <string>
using namespace std; class Solution{public:bool canPermutePalindrome(string s){int x=0;for(char c:s)x^=1<<(c-'a');return (x&(x-1))==0;}};
