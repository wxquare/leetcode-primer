

#include <unordered_map>
#include <list>

using namespace std;

// least frequency used
struct Node{
    int key;
    int val;
    int freq;
    Node(int k,int v,int f):key(k),val(v),freq(f){}
};

class LFU{
public:
    int minFreq;
    unordered_map<int,list<Node>> mf;
    unordered_map<int,list<Node>::iterator> mkv;
    int get(int key){
        if(mkv.count(key) == 0) return -1;
        auto it = mkv[key];
        int freq = it->freq;
        if(mf.count(freq+1) == 0){
            mf[freq+1] = list<Node>();
        }
        mf[freq+1].push_front(Node(freq+1,it->key,it->val));
        mf[freq].erase(it);
        mkv[key] = mf[freq+1].begin();
        if(mf[freq].size() == 0){
            mf.erase(freq);
            if(minFreq == freq){
                minFreq++;
            }
        }
    }
    void put(int key,int val){
        if(mkv.count(key)){
            auto it = mkv[key];
            int freq = it->freq;
            if(mf.count(freq+1) == 0){
                mf[freq+1] = list<Node>();
            }
            mf[freq+1].push_front(Node(freq+1,it->key,val));
            mf[freq].erase(it);
            mkv[key] = mf[freq+1].begin();
            if(mf[freq].size() == 0){
                mf.erase(freq);
                if(minFreq == freq){
                    minFreq++;
                }
            }
        } else {
            if(mf.count(1) == 0){
                mf[1] = list<Node>();
            }
            mf[1].push_front(Node(1,key,val));
            mkv[key] = mf[1].begin();
            minFreq = 1;
        }
    }
};