/*
树状数组（Fenwick Tree），也称为二叉索引树（Binary Indexed Tree，BIT），
是一种用于高效处理数组前缀和（或区间和）的数据结构。它可以在对数组进行动态单点更新的同时，快速计算任意前缀和。

树状数组的核心思想是利用二进制表示中的低位特性，通过维护一个类似二叉树的结构来高效计算前缀和。树状数组的每个节点存储了一定范围内的元素和，通过合理的设计和运算，可以快速计算出任意区间的和。

树状数组的基本操作包括：
- 初始化：根据给定数组的长度构建初始的树状数组结构。
- 单点更新：将指定位置的元素进行更新，并相应地更新树状数组中的节点值。
- 前缀和计算：计算数组的前缀和，即从起始位置到指定索引位置的元素之和。
- 区间和计算：计算指定区间的元素之和，通过巧妙地利用前缀和的性质，可以在 O(logn) 的时间复杂度内完成计算。

总结起来，树状数组是一种用于高效处理前缀和（或区间和）的数据结构，适用于需要频繁更新和查询前缀和的场景。它的时间复杂度为 O(logn)，相较于其他数据结构（如线段树）具有较低的实现复杂度和较小的空间开销

https://www.bilibili.com/video/BV1ce411u7qP/?spm_id_from=333.337.search-card.all.click&vd_source=04e82c25f6ff3d6a1a08a7f1c343987c

*/

#include <vector>
#include <iostream>

using namespace std;

class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int size) {
        tree.resize(size + 1, 0);
    }

    // 单点更新：将指定位置的元素加上val
    void update(int index, int val) {
        while (index < tree.size()) {
            tree[index] += val;
            index += index & -index;  //lowbit(x)
        }
    }

    // 前缀和计算：计算从1到指定位置的元素和
    int getPrefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index; // lowbit
        }
        return sum;
    }

    // 区间和计算：计算指定区间 [start, end] 的元素和
    int getRangeSum(int start, int end) {
        return getPrefixSum(end) - getPrefixSum(start - 1);
    }
};

int main(){
    FenwickTree ft(8);
    for(int i=1;i<=8;i++){
        ft.update(i,i);
    }
    std::cout << ft.getPrefixSum(3) << std::endl;
}



