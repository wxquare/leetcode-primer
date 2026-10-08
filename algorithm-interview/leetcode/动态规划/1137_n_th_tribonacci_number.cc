class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1;
        while (n--) {
            int d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return a;
    }
};
