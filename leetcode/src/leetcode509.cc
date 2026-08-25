#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n){
        /*
            f[0] = 0;
            f[1] = 1;
            f[x]= fx[n-1]+f[x-2];
            fib[x+1] = f[x] + f[x-1];
        */
        if(n < 2) return n;
        int x_2 = 0;
        int x_1 = 1;
        int x;
        for(int i=2;i<=n;i++){
            x = x_1 + x_2;
            x_2 = x_1;
            x_1 = x;
        }
        return x;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().fib(10) << std::endl;
    return 0;
}
