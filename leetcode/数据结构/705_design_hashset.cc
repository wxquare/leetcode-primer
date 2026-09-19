#include <vector>
using namespace std; class MyHashSet{vector<char>a;public:MyHashSet():a(1000001){}void add(int k){a[k]=1;}void remove(int k){a[k]=0;}bool contains(int k){return a[k];}};
