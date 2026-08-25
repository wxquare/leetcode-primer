#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <list>
#include <iostream>

void bubbleSort(int a[], int length) {
    if (a == nullptr || length < 2)
        return;
    for (int i = 0; i < length - 1; i++) {
        for (int j = length - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                std::swap(a[j - 1], a[j]);
            }
        }
    }
}

void insertSort(int a[], int length) {
    if (a == nullptr || length < 2)
        return;

    for (int i = 1; i < length; i++) {
        if (a[i - 1] > a[i]) {
            int tmp = a[i];
            int j;
            for (j = i - 1; j >= 0 && a[j] > tmp; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = tmp;
        }
    }
}

void selectSort(int a[], int length) {
    if (a == nullptr || length < 2) return;
    for (int i = 0; i < length - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            std::swap(a[i], a[minIndex]);
        }
    }
}

void shellSort(int a[], int length) {
    if (a == nullptr || length < 2)  return;
    for (int gap = length / 2; gap >= 1; gap /= 2) {
        for (int i = gap; i < length; i++) {
            if (a[i - gap] > a[i]) {
                int tmp = a[i];
                int j;
                for (j = i - gap; j >= 0 && a[j] > tmp; j -= gap) {
                    a[j + gap] = a[j];
                }
                a[j + gap] = tmp;
            }
        }
    }
}

void quickSort(int a[], int start, int end) {
    if (a == nullptr || start >= end)
        return;

    int pivotVal = a[start];
    int left = start;
    int right = end;

    while (left < right) {
        while (left < right && a[right] >= pivotVal)
            right--;
        a[left] = a[right];
        while (left < right && a[left] <= pivotVal)
            left++;
        a[right] = a[left];
    }
    a[left] = pivotVal;
    quickSort(a, start, left - 1);
    quickSort(a, left + 1, end);
}

void mergeSort(int a[], int start, int end) {
    if (a == nullptr || start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(a, start, mid);
    mergeSort(a, mid + 1, end);

    //merge operation
    int *tmp = new int[end - start + 1];
    int left = start;
    int right = mid + 1;
    int k = 0;
    while (left <= mid && right <= end) {
        if (a[left] <= a[right]) {
            tmp[k++] = a[left++];
        } else {
            tmp[k++] = a[right++];
        }
    }

    while (left <= mid) {
        tmp[k++] = a[left++];
    }
    while (right <= end) {
        tmp[k++] = a[right++];
    }
    for (int i = 0; i < k; i++) {
        a[start + i] = tmp[i];
    }
    delete[] tmp;
}

void radixSort(int a[], int length) {
    if (a == nullptr || length < 2)
        return;

    //maxValue and d;
    int maxVal = a[0];
    for (int i = 1; i < length; i++) {
        maxVal = std::max(maxVal, a[i]);
    }
    int d = 0;
    while (maxVal > 0) {
        d++;
        maxVal /= 10;
    }

    int radix = 1;
    int* count = new int[10];
    int* tmp = new int[length];
    for (int n = 0; n < d; n++) {
        memset(count, 0, sizeof(int) * 10);
        for (int i = 0; i < length; i++) {
            count[a[i] / radix % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = length - 1; i >= 0; i--) {
            tmp[--count[a[i] / radix % 10]] = a[i];
        }

        for (int i = 0; i < length; i++) {
            a[i] = tmp[i];
        }
        radix *= 10;
    }
    delete[] count;
    delete[] tmp;
}

// small range 0 ~ maxVal
void countSort(int a[], int length) {
    if (a == nullptr || length < 2)
        return;

    int maxVal = a[0];
    for (int i = 1; i < length; i++) {
        maxVal = std::max(a[i], maxVal);
    }

    int* tmp = new int[maxVal + 1];
    memset(tmp,0,sizeof(int)*(maxVal+1));

    for (int i = 0; i < length; i++) {
        tmp[a[i]]++;
    }
    int k = 0;
    for (int i = 0; i <= maxVal; i++) {
        for (int j = 0; j < tmp[i]; j++) {
            a[k++] = i;
        }
    }
    delete[] tmp;
}

//10 bucktets;range 0~99
void bucketSort(int a[], int length) {
    if (a == nullptr || length < 2)
        return;
    std::vector<std::list<int>> buckets(10);
    for (int i = 0; i < length; i++) {
        buckets[a[i] / 10].push_back(a[i]);
    }
    //sort every buckets and merge
    int k = 0;
    for (size_t i = 0; i < buckets.size(); i++) {
        buckets[i].sort();
        for (int num : buckets[i]) {
            a[k++] = num;
        }
    }
}

void heapAdjust(int a[],int start,int end){
    int leftChild = 2*start + 1;
    int rightChild = 2*start + 2;

    while(rightChild <= end){
        if(a[start] >= a[leftChild] && a[start] >= a[rightChild]){
            break;
        }

        if(a[leftChild] >= a[rightChild]){
            std::swap(a[start],a[leftChild]);
            start = leftChild;
        }else{
            std::swap(a[start],a[rightChild]);
            start = rightChild;
        }
        leftChild = 2 * start + 1;
        rightChild = leftChild+1;
    }
    if(leftChild <= end && a[leftChild] > a[start]){
        std::swap(a[leftChild],a[start]);
    }

}

void heapSort(int a[],int length){

    if(a == nullptr  || length < 2) return;


    for(int i=length/2-1;i >=0;i--){
        heapAdjust(a,i,length-1);
    }
    // max heap
    for(int i=length-1;i>=0;i--){
        std::swap(a[0],a[i]);
        heapAdjust(a,0,i-1);
    }
}


void printArray(int a[],int length){
    for(int i=0;i<length;i++){
        std::cout << a[i] << ",";
    }
    std::cout << '\n';
}




// 简单版本的快排
void quickSort1(vector<int>& nums){
    function<void(int,int)> quickSort = [&](int left,int right){
        if(left >= right) return;
        int l = left;
        int r = right;
        int pos = left + rand() % (right - left + 1);
        swap(nums[left],nums[pos]);
        int pivot = nums[left];
        while(l < r){
            while(l < r && nums[r] >= pivot){
                r--;
            }
            nums[l] = nums[r];
            while(l < r && nums[l] <= pivot){
                l++;
            }
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        quickSort(left,l-1);
        quickSort(l+1,right);
    };
    quickSort(0,nums.size() - 1);
}

void quickSort2(vector<int>& nums){
    function<void(int,int)> quickSort = [&](int left,int right){
        if(left >= right) return;
        int pos = left + rand() % (right - left + 1);
        swap(nums[pos],nums[left]);
        int pivot = nums[left];
        int less = left;
        int more = right + 1;
        int i = left + 1;
        while(i < more){
            if(nums[i] < pivot){
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
        swap(nums[left],nums[less]);
        quickSort(left,less-1);
        quickSort(more,right);
    };
    quickSort(0,nums.size() - 1);
}


void mergeSort(vector<int>& nums){
    int n = nums.size();
    vector<int> tmp(n,0);
    function<void(int,int)> mergeSort = [&](int left,int right){
        if(left >= right) return;
        int mid = left + (right - left) / 2;
        mergeSort(left,mid);
        mergeSort(mid+1,right);        
        int p = left;
        int q = mid + 1;
        int start = left;
        while(p <= mid && q <= right){
            if(nums[p] <= nums[q]){
                tmp[start++] = nums[p++];
            } else {
                tmp[start++] = nums[q++];
            }
        }
        while(p <= mid){
            tmp[start++] = nums[p++];
        }
        while(q <= right){
            tmp[start++] = nums[q++];
        }
        start = left;
        while(start <= right){
            nums[start] = tmp[start];
            start++;
        }
    };
    mergeSort(0,nums.size()-1);
}


int main() {
    int a[] = {1,8,4,2,5,3,7,6};
    printArray(a,8);

    bubbleSort(a,8);
//    insertSort(a,8);
//    selectSort(a,8);
//    shellSort(a,8);
//    quickSort(a,0,7);
//    mergeSort(a,0,7);
//    radixSort(a,8);
//    countSort(a,8);
//    bucketSort(a,8);
//    heapSort(a,8);
    printArray(a,8);

    return 0;
}