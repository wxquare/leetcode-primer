#include <unordered_map>
#include <list>
using namespace std;

/*
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

namespace lru{
    
struct Node{
    int key;
    int val;
    Node(int k,int v):key(k),val(v){};
};

class LRUCache {
public:
    int cap;
    list<Node> lt;
    unordered_map<int,list<Node>::iterator> m;// key,node address.

    LRUCache(int capacity) : cap(capacity){
    }
    int get(int key) {
        if(m.count(key) == 0) return -1;
        int val =  m[key]->val;
        // auto p = m[key];
        // lt.erase(p);
        // lt.push_front(Node(key,val));
        // m[key] = lt.begin();
        lt.splice(lt.begin(),lt,m[key]);
        return val;
    }
    void put(int key, int value) {
        if(m.count(key)){
            lt.erase(m[key]);
        } 

        lt.push_front(Node(key,value));
        m[key] = lt.begin();

        if(m.size() > cap){
            auto it = lt.rbegin();
            m.erase(it->key);
            lt.pop_back();
        }
    }
};
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */