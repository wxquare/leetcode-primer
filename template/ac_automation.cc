#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


const int inf = 0x3f3f3f3f;

// AC 自动机的节点结构
struct Node {
    unordered_map<char, Node*> children; // 子节点
    bool isEnd; // 是否是一个敏感词的结尾节点
    Node* fail; // 失败指针，用于构建自动机
    int minLen;  // 到节点恰好有终点的最短字符串的长度
    Node() : isEnd(false),minLen(inf),fail(nullptr) {}
};

// 构建 AC 自动机
void buildACAutomaton(Node* root, vector<string>& keywords) {
    // 构建 Trie 树
    for (const string& word : keywords) {
        Node* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new Node();
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
        curr->minLen = min(curr->minLen,int(word.length()));
    }

    // BFS构建失败指针
    queue<Node*> q;
    for (auto& kvp : root->children) {
        Node* child = kvp.second;
        child->fail = root;
        q.push(child);
    }
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        for (auto& kvp : curr->children) {
            char c = kvp.first;
            Node* child = kvp.second;
            q.push(child);
            Node* failNode = curr->fail;
            while (failNode != nullptr && failNode->children.find(c) == failNode->children.end()) {
                failNode = failNode->fail;
            }
            child->fail = (failNode != nullptr) ? failNode->children[c] : root;
            child->minLen = min(child->minLen,child->fail->minLen);
        }
    }
}

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        Node* root = new Node();
        buildACAutomaton(root,forbidden);
        int left = 0;
        int ans = 0;
        int n = word.length();
        Node* curr = root;
        for(int i=0;i<n;i++){
            while (curr != nullptr && curr->children.find(word[i]) == curr->children.end()) {
                curr = curr->fail;
            }
            if (curr != nullptr) {
                curr = curr->children[word[i]];
                if (curr->minLen != inf) {
                    left = max(left,i+1-curr->minLen+1);
                    curr = curr->fail;
                } 
            } else {
                curr = root;
            }
            ans = max(ans,i - left + 1);
        }
        return ans;
    }
}; 

int main(int argc, char const *argv[])
{
    string word = "aaaabaaacc";
    vector<string> forbidden = {"bcca","aaa","aabaa","baaac"};
    std::cout << Solution().longestValidSubstring(word,forbidden) << std::endl;
    return 0;
}
