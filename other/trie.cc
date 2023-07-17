#include <vector>
#include <string>
using namespace std;

struct TrieNode{
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode():isEnd(false),children(26,nullptr){}
};


class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for(char & c : word){
            if(p->children[c - 'a'] == nullptr){
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for(char & c : word){
            if(p->children[c - 'a'] == nullptr){
                return false;
            }
            p = p->children[c - 'a'];
        }
        return p->isEnd;
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


int main(int argc, char const *argv[])
{
    Trie *root = new Trie();
    vector<string> words = {"abc","cbd","dfajakfdjk"};
    for(string &  w : words){
        root->insert(w);
    }
    return 0;
}
