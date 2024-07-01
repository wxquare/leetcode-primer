#include <iostream>
#include <vector>

using namespace std;

// 矩形结构体
struct Rectangle {
    int x1, y1, x2, y2; // 左上角 (x1, y1) 和 右下角 (x2, y2)
};

// 判断两个矩形是否重叠
bool isOverlapping(Rectangle A, Rectangle B) {
    // 如果在水平或垂直方向上没有交集，则不重叠
    if (A.x2 <= B.x1 || A.x1 >= B.x2 || A.y2 <= B.y1 || A.y1 >= B.y2) {
        return false;
    }
    // 否则重叠
    return true;
}

int main() {
    // 示例矩形
    Rectangle A = {0, 0, 2, 2}; // A 覆盖 (0,0) 到 (2,2)
    Rectangle B = {2, 2, 4, 4}; // B 覆盖 (2,2) 到 (4,4)
    
    if (isOverlapping(A, B)) {
        cout << "The rectangles overlap." << endl;
    } else {
        cout << "The rectangles do not overlap." << endl;
    }
    
    // 测试重叠在一个点上的情况
    Rectangle C = {0, 0, 1, 1};
    Rectangle D = {1, 1, 2, 2};
    
    if (isOverlapping(C, D)) {
        cout << "Rectangles C and D overlap." << endl;
    } else {
        cout << "Rectangles C and D do not overlap." << endl;
    }

    return 0;
}
