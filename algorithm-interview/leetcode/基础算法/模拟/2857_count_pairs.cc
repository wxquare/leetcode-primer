#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int countPairs(vector<vector<int>> coordinates,int k){
		map<int,map<int,int>> m;
		int n = coordinates.size();
		int ans = 0;
		for(int i=0;i<n;i++){
			int x = coordinates[i][0], y = coordinates[i][1];
			for(int j=0;j<=k;j++){
				if(m.count(x^j) && m[x^j].count(y^(k-j))){
					ans += m[x^j][y^(k-j)];
				}
			}
			m[x][y]++;
		}
    }
};