#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// AC 自动机的节点结构
struct Node {
    bool isEnd; // 是否是一个敏感词的结尾节点
    unordered_map<char, Node*> children; // 子节点
    Node* fail; // 失败指针，用于构建自动机

    Node() : isEnd(false), fail(nullptr) {}
};

// 构建 AC 自动机
void buildACAutomaton(Node* root, const vector<string>& keywords) {
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
    }

    // 构建失败指针
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
        }
    }
}

// 在文本中查找敏感词
vector<string> findSensitiveWords(const string& text, Node* root) {
    vector<string> sensitiveWords;
    Node* curr = root;
    for (char c : text) {
        while (curr != nullptr && curr->children.find(c) == curr->children.end()) {
            curr = curr->fail;
        }
        if (curr != nullptr) {
            curr = curr->children[c];
            if (curr->isEnd) {
                sensitiveWords.push_back("Sensitive word found");
            }
        } else {
            curr = root;
        }
    }
    return sensitiveWords;
}

int main() {
    // 构建敏感词列表
    vector<string> keywords = { "bad", "evil", "danger" };

    // 构建 AC 自动机
    Node* root = new Node();
    buildACAutomaton(root, keywords);

    // 检测敏感词
    string text = "There is a baddanger guy in the neighborhood.";
    vector<string> sensitiveWords = findSensitiveWords(text, root);

    // 输出结果
    if (sensitiveWords.empty()) {
        cout << "No sensitive words found." << endl;
    } else {
        for (const string& word : sensitiveWords) {
            cout << word << endl;
        }
    }

    return 0;
}
