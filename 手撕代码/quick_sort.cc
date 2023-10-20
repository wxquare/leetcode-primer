#include <vector>
#include <iostream>
using namespace std;

void quickSort(vector<int>& nums){
    function<void(int,int)> f = [&](int l,int r){
        if(l >=r) return;
        int pivot = nums[l];
        int i = l,j = r;
        while(i < j){
            while(i<j && nums[j] >= pivot){
                j--;
            }
            nums[i] = nums[j];
            while(i<j && nums[i] <= pivot){
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        f(l,i-1);
        f(j+1,r);
    };
    return f(0,nums.size() - 1);
}

int main(){
    vector<int> nums = {3,2,1,2,2,3,1,5,6,4,4};
    quickSort(nums);
    for(int i=0;i<nums.size();i++){
        std::cout << nums[i] << '\t';
    }
    std::cout << '\n';
}