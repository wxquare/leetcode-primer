
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

// least recently used.
class LRU {
public:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    LRU(int cap):cap(cap){}

    int get(int key){
        if(m.count(key) == 0) return -1;
        auto it = m[key];
        l.push_front(make_pair(it->first,it->second));
        l.erase(it);
        m[key] = l.begin();
        return l.begin()->second;
    }

    void put(int key,int val){
        if(m.count(key)){
            auto it = m[key];
            int ans = it->second;
            l.push_front(make_pair(it->first,val));
            l.erase(it);
            m[key] = l.begin();
        } else {
            l.push_front(make_pair(key,val));
            m[key] = l.begin();
            if(m.size() > cap){
                auto it = l.back();
                m.erase(it.first);
                l.pop_back();
            }
        }
    }
    
    void print(){
        for(auto it = l.begin();it!=l.end();it++){
            std::cout << it->first << '\t' << it->second << std::endl;
        }
    }
};

int main(){
    LRU l = LRU(3);
    l.put(1,1);
    l.put(2,2);
    l.put(3,3);
    l.get(2);
    l.put(4,4);
    l.print();
}