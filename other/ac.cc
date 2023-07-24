#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_NODE = 100000; // 字典树节点最大数量
const int ALPHABET_SIZE = 26; // 字母表大小

// 字典树节点定义
struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    TrieNode* fail;
    bool isEnd;
    int depth;

    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
        fail = nullptr;
        isEnd = false;
        depth = 0;
    }
};

// 构建字典树
void insertTrie(TrieNode* root, string word) {
    TrieNode* node = root;
    for (char c : word) {
        int idx = c - 'a';
        if (!node->children[idx]) {
            node->children[idx] = new TrieNode();
        }
        node = node->children[idx];
    }
    node->isEnd = true;
    node->depth = word.length();
}

// 添加失败指针
void buildFailurePointer(TrieNode* root) {
    queue<TrieNode*> q;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            q.push(root->children[i]);
            root->children[i]->fail = root;
        }
    }

    while (!q.empty()) {
        TrieNode* curr = q.front();
        q.pop();

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            TrieNode* child = curr->children[i];
            if (child) {
                TrieNode* failNode = curr->fail;
                while (failNode && !failNode->children[i]) {
                    failNode = failNode->fail;
                }
                if (failNode) {
                    child->fail = failNode->children[i];
                } else {
                    child->fail = root;
                }
                q.push(child);
            }
        }
    }
}

// AC 自动机匹配
void acAutomaton(TrieNode* root, string text) {
    TrieNode* curr = root;
    for (char c : text) {
        int idx = c - 'a';
        while (curr && !curr->children[idx]) {
            curr = curr->fail;
        }
        if (curr) {
            curr = curr->children[idx];
        } else {
            curr = root;
        }

        TrieNode* temp = curr;
        while (temp) {
            if (temp->isEnd) {
                cout << "Pattern found at index: " << (text.size() - temp->depth) << endl;
            }
            temp = temp->fail;
        }
    }
}

int main() {
    vector<string> patterns = {"he", "she", "his", "hers"};
    string text = "ushers";

    TrieNode* root = new TrieNode();
    for (string pattern : patterns) {
        insertTrie(root, pattern);
    }

    buildFailurePointer(root);
    acAutomaton(root, text);

    return 0;
}
