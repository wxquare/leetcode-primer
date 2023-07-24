#include <string>
#include <vector>
#include <iostream>
using namespace std;


int kmp(string text,string pattern){
    int n = pattern.length();
    // ABABCCABAB
    // 0012001234
    vector<int> lps(n); // length of common prefix and suffix
    int len = 0;
    for(int i=1;i<n;){
        if(pattern[i] == pattern[len]){
            len++;  
            lps[i] = len;
            i++;
        } else {
            if(len - 1 > 0){
                len = lps[len - 1];
            } else {
                i++;
            }
        }
    }
    int j = 0;
    for(int i=0;i<text.length();){
        if(text[i] == pattern[j]){
            j++;
            i++;
        } else {
            if(j > 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
        if(j == pattern.length()){
            std::cout << "find target " << pattern << std::endl;
            return j - pattern.length();
        }
    }
    return -1;
}




/*
    字典树：适用于大量字符串的前缀匹配、模式匹配、最长公共前缀查找等场景。例如，实现搜索引擎中的搜索提示功能、自动补全功能等。
    哈希表：适用于高效的查找、插入和删除操作，适用于需要快速判断字符串是否存在的场景。例如，在字典中查找单词、统计字符串频次等
*/
struct TrieNode {
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode():isEnd(false),children(26,nullptr){};  // 26个小写字母
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
        p->isEnd = true;
    }
    bool search(string & word){
        TrieNode *p = root;
        for(char c : word){
            if(p->children[c - 'a'] == nullptr){
                return false;
            }
            p = p->children[c - 'a'];
        }
        return p->isEnd;
    }
};