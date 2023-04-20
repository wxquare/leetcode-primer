#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    vector<pair<int,int>> nums = {{1,2},{1,3},{2,1},{2,2}};
    auto it1 = lower_bound(nums.begin(),nums.end(),2,[](const auto &a,const int &b){
        return a.second > b;
    });
    std::cout << it1->first << '\t' << it1->second << std::endl;    
}
