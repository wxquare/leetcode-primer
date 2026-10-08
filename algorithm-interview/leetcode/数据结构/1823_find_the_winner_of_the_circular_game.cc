class Solution {
public:
    int findTheWinner(int n, int k) {
        int r = 0;
        for (int i = 1; i <= n; i++) r = (r + k) % i;
        return r + 1;
    }
};
