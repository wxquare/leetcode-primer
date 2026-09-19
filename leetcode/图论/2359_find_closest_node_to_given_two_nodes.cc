#include <vector>
#include <algorithm>
using namespace std; class Solution{vector<int>go(vector<int>&e,int s){vector<int>d(e.size(),-1);for(int i=s;i!=-1&&d[i]<0;i=e[i])d[i]=d[i]<0?i: d[i];int x=s,k=0;while(x!=-1&&d[x]==-1)d[x]=k++,x=e[x];return d;}public:int closestMeetingNode(vector<int>&e,int a,int b){vector<int>x(e.size(),-1),y=x;int k=0;for(int i=a;i!=-1&&x[i]<0;i=e[i])x[i]=k++;k=0;for(int i=b;i!=-1&&y[i]<0;i=e[i])y[i]=k++;int ans=-1,best=1000000000;for(int i=0;i<(int)e.size();i++)if(x[i]>=0&&y[i]>=0&&max(x[i],y[i])<best)best=max(x[i],y[i]),ans=i;return ans;}};
