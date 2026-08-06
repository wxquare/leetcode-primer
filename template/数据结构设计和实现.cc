#include <unordered_map>
#include <list>
#include <vector>
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
    LRUCache(int capacity) : cap(capacity){}
    int get(int key) {
        if(m.count(key) == 0) return -1;
        int val =  m[key]->val;
        lt.splice(lt.begin(),lt,m[key]);
        return val;
    }
    void put(int key, int value) {
        if(m.count(key)){
            auto it = m[key];
            it->val = value;
            lt.splice(lt.begin(),lt,m[key]);
        } else {
            if(m.size() == cap){
                auto it = lt.rbegin();
                m.erase(it->key);
                lt.pop_back();
            }
            lt.push_front(Node(key,value));
            m[key] = lt.begin();
        }
    }
};
};

namespace lfu{
// 缓存的节点信息
struct Node {
    int key, val, freq;
    Node(int _key,int _val,int _freq): key(_key), val(_val), freq(_freq){}
};
class LFUCache {
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;
public:
    LFUCache(int _capacity) {
        minfreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }
    
    int get(int key) {
        if(key_table.count(key) == 0) return -1;
        list<Node>::iterator node = key_table[key];;
        int val = node -> val, freq = node -> freq;
        freq_table[freq].erase(node);
        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0) {
            freq_table.erase(freq);
            if (minfreq == freq) minfreq += 1;
        }
        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 缓存已满，需要进行删除操作
            if (key_table.size() == capacity) {
                // 通过 minFreq 拿到 freq_table[minFreq] 链表的末尾节点
                auto it2 = freq_table[minfreq].back();
                key_table.erase(it2.key);
                freq_table[minfreq].pop_back();
                if (freq_table[minfreq].size() == 0) {
                    freq_table.erase(minfreq);
                }
            } 
            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minfreq = 1;
        } else {
            // 与 get 操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it -> second;
            int freq = node -> freq;
            freq_table[freq].erase(node);
            if (freq_table[freq].size() == 0) {
                freq_table.erase(freq);
                if (minfreq == freq) minfreq += 1;
            }
            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};
};


namespace hm{
const int BUCKET_SIZE = 16;
class MyHashMap{
public:
    vector<list<pair<int,int>>> data;

    int bucket(int key){
        return key % BUCKET_SIZE;
    }

    MyHashMap(){
        data.resize(BUCKET_SIZE);
    }

    void put(int key,int val){
        int idx = bucket(key);
        for(auto it=data[idx].begin();it!=data[idx].end();it++){
            if(it->first == key){
                it->second = val;
                return;
            }
        } 
        data[idx].push_back(make_pair(key,val));
        return;
    }

    int get(int key){
        int idx = bucket(key);
        for(auto it=data[idx].begin();it!=data[idx].end();it++){
            if(it->first == key){
                return it->second;
            }
        }
        return -1;
    }

    void remove(int key){
        int idx = bucket(key);
        for(auto it=data[idx].begin();it!=data[idx].end();it++){
            if(it->first == key){
                data[idx].erase(it);
                return;
            }
        }
        return;
    }
};
};


namespace sl{

const int MAX_LEVEL = 32;
const int FACTOR = 2;

struct SkipListNode{
    int val;
    int level; //当前节点的level
    vector<SkipListNode*> forwards;
    SkipListNode(int x,int _level = MAX_LEVEL) : val(x),level(_level),forwards(level,nullptr){}
};

class SkipList{
public:
    SkipListNode* root;
    int curLevel; // 当前跳表最大level
    SkipList(){
        root = new SkipListNode(-1);
        curLevel = 0;
    }

    int randomLevel(){
        int lv = 1;
        while(random() % FACTOR == 1){
            lv++;
        }
        return min(lv,MAX_LEVEL);
    }

    void add(int num){
        vector<SkipListNode*> update(MAX_LEVEL);
        SkipListNode* cur = root;
        for(int i=curLevel-1;i>=0;i--){
            while(cur->forwards[i] && cur->forwards[i]->val < num){
                cur = cur->forwards[i];
            }
            update[i] = cur;
        }
        int level = randomLevel();
        this->curLevel = max(level,this->curLevel);
        SkipListNode* newNode = new SkipListNode(num,level);
        for(int i=level-1;i>=0;i--){
            newNode->forwards[i] = update[i]->forwards[i];
            update[i]->forwards[i] = newNode;
        }
    }

    bool search(int target){
        SkipListNode* cur = root;
        for(int i=this->curLevel-1;i>=0;i--){
            while(cur->forwards[i] && cur->forwards[i]->val < target){
                cur = cur->forwards[i];
            }
        }
        return cur->forwards[0] && cur->forwards[0]->val == target;
    }

    void erase(int num){
        vector<SkipListNode*> update(this->curLevel);
        SkipListNode* cur = root;
        for(int i=curLevel-1;i>=0;i--){
            while(cur->forwards[i] && cur->forwards[i]->val < num){
                cur = cur->forwards[i];
            }
            update[i] = cur;
        }
        // 不存在num
        if(cur->forwards[0] == nullptr || cur->forwards[0]->val != num) return;

        for(int i=cur->forwards[0]->level-1;i>=0;i--){
            update[i]->forwards[i] = update[i]->forwards[i]->forwards[i];
        }
        delete cur->forwards[0];
        for(int i=curLevel-1;i<=0;i--){
            if(cur->forwards[i] == nullptr){
                curLevel--;
            }
        }
        return;
    }
};
};


