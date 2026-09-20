#include <vector>
using namespace std;
class Solution {
public:
    int minDeletion(vector<int>& a) {
        int d = 0;
        for (int i = 0; i < a.size(); i++)
            if ((i - d) % 2 == 0 && i + 1 < a.size() && a[i] == a[i + 1]) d++;
        return (a.size() - d) % 2 ? d + 1 : d;
    }
};
