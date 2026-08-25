#include <vector>
#include <iostream>
using namespace std;

void mergeSort(vector<int>& nums){
    int n = nums.size();
    vector<int> tmp(n);
    function<void(int,int)> f = [&](int l,int r){
        if(l>=r) return;
        int mid = l + (r - l) / 2;
        f(l,mid);
        f(mid+1,r);
        int k = 0;
        int i = l;
        int j = mid+1;
        while(i<=mid && j <= r){
            if(nums[i] <= nums[j]){
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while(i <= mid){
            tmp[k++] = nums[i++];
        }
        while(j<=r){
            tmp[k++] = nums[j++];
        }
        for(int i=0;i<k;i++){
            nums[l+i] = tmp[i];
        }
    };
    return f(0,nums.size() - 1);
}

int main(){
    vector<int> nums = {1,2,3,4,5,2,2,7};
    mergeSort(nums);
    for(int i=0;i<nums.size();i++){
        std::cout << nums[i] << std::endl;
    }
}