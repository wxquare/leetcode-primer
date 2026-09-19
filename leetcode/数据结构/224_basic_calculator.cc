#include <string>
using namespace std; class Solution{int i;int f(string&s){int n=0,sign=1,r=0;while(i<s.size()){char c=s[i++];if(c>='0'&&c<='9')n=n*10+c-'0';else if(c=='+'||c=='-')r+=sign*n,n=0,sign=c=='+'?1:-1;else if(c=='(')n=f(s);else if(c==')')return r+sign*n;else continue;}return r+sign*n;}public:int calculate(string s){i=0;return f(s);}};
