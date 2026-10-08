#include <vector>
using namespace std;
class MyHashMap {
    vector<int> a;

public:
    MyHashMap() : a(1000001, -1) {}
    void put(int k, int v) { a[k] = v; }
    int get(int k) { return a[k]; }
    void remove(int k) { a[k] = -1; }
};
