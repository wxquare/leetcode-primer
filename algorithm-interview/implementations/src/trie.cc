#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    bool end;
    TrieNode():end(false),children(26,nullptr){}
};

class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string& word){
        TrieNode* p = root;
        for(char c : word){
            if(p->children[c - 'a'] == nullptr){
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->end = true;
    }

    bool search(string&  word){
        TrieNode* p = root;
        for(char c : word){
            if(p->children[c - 'a'] == nullptr){
                return false;
            }
            p = p->children[c - 'a'];
        }
        return p->end;
    }

    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(char & c : prefix){
            if(p->children[c - 'a'] == nullptr){
                return false;
            }
            p = p->children[c - 'a'];
        }
        return true;
    }
};

int main(){
    Trie* rt = new Trie();
    string s1 = "abcd";
    string s2 = "ab";
    rt->insert(s1);
    rt->insert(s2);
    std::cout << rt->search(s2) << std::endl;
}