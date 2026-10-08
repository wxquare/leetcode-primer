#include <vector>
#include <iostream>
using namespace std;

void sort(vector<int>& nums){
    int n = nums.size();
    function<void(int,int)> quick_sort = [&](int l,int r){
        if(l >= r) return;
        int p = random() % (r - l + 1);
        swap(nums[l],nums[p]);

        int pivot = nums[l];
        int less = l;
        int more = r + 1;
        int i = l;
        while(i < more){
            if(nums[i] <  pivot) {
                less++;
                swap(nums[i],nums[less]);
                i++;
            } else if(nums[i] == pivot){
                i++;
            } else if(nums[i] > pivot){
                more--;
                swap(nums[i],nums[more]);
            }
        }
        swap(nums[less],nums[l]);
        quick_sort(l,less-1);
        quick_sort(more,r);
    };
    return quick_sort(0,nums.size()-1);
}

int main(){
    vector<int> nums = {3,2,1,2,2,3,1,5,6,4,4};
    sort(nums);
    for(int i=0;i<nums.size();i++){
        std::cout << nums[i] << '\t';
    }
    std::cout << '\n';
}