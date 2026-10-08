#include <vector>
using namespace std;
class MyCircularDeque {
    vector<int> a;
    int h = 0, n = 0, k;

public:
    MyCircularDeque(int K) : a(K), k(K) {}
    bool insertFront(int x) {
        if (isFull()) return false;
        h = (h - 1 + k) % k;
        a[h] = x;
        n++;
        return true;
    }
    bool insertLast(int x) {
        if (isFull()) return false;
        a[(h + n) % k] = x;
        n++;
        return true;
    }
    bool deleteFront() {
        if (isEmpty()) return false;
        h = (h + 1) % k;
        n--;
        return true;
    }
    bool deleteLast() {
        if (isEmpty()) return false;
        n--;
        return true;
    }
    int getFront() { return isEmpty() ? -1 : a[h]; }
    int getRear() { return isEmpty() ? -1 : a[(h + n - 1 + k) % k]; }
    bool isEmpty() { return n == 0; }
    bool isFull() { return n == k; }
};
