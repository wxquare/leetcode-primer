#include <string>
#include <vector>
using namespace std;

class MagicDictionary {
    struct Node {
        Node* children[26];
        bool terminal;
        Node() : terminal(false) {
            for (int i = 0; i < 26; ++i) children[i] = 0;
        }
    };

    Node* root;

    bool match(Node* node, const string& word, int index, bool changed) const {
        if (index == static_cast<int>(word.size())) {
            return changed && node->terminal;
        }
        int original = word[index] - 'a';
        for (int letter = 0; letter < 26; ++letter) {
            if (!node->children[letter]) continue;
            if (letter == original) {
                if (match(node->children[letter], word, index + 1, changed)) {
                    return true;
                }
            } else if (!changed &&
                       match(node->children[letter], word, index + 1, true)) {
                return true;
            }
        }
        return false;
    }

    void destroy(Node* node) {
        if (!node) return;
        for (int i = 0; i < 26; ++i) destroy(node->children[i]);
        delete node;
    }

public:
    MagicDictionary() : root(new Node()) {}

    ~MagicDictionary() {
        destroy(root);
    }

    void buildDict(vector<string> dictionary) {
        for (size_t i = 0; i < dictionary.size(); ++i) {
            Node* node = root;
            for (size_t j = 0; j < dictionary[i].size(); ++j) {
                int letter = dictionary[i][j] - 'a';
                if (!node->children[letter]) node->children[letter] = new Node();
                node = node->children[letter];
            }
            node->terminal = true;
        }
    }

    bool search(string searchWord) {
        return match(root, searchWord, 0, false);
    }
};
