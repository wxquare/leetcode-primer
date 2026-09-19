#include <random>
#include <vector>
using namespace std;

class Skiplist {
    enum { MAX_LEVEL = 16 };

    struct Node {
        int value;
        vector<Node*> next;
        Node(int value, int level) : value(value), next(level, 0) {}
    };

    Node* head;
    int levels;
    mt19937 generator;
    uniform_int_distribution<int> coin;

    int randomLevel() {
        int level = 1;
        while (level < MAX_LEVEL && coin(generator) == 1) ++level;
        return level;
    }

public:
    Skiplist()
        : head(new Node(0, MAX_LEVEL)),
          levels(1),
          generator(random_device()()),
          coin(0, 1) {}

    ~Skiplist() {
        Node* node = head;
        while (node) {
            Node* next = node->next[0];
            delete node;
            node = next;
        }
    }

    bool search(int target) {
        Node* node = head;
        for (int level = levels - 1; level >= 0; --level) {
            while (node->next[level] && node->next[level]->value < target) {
                node = node->next[level];
            }
        }
        node = node->next[0];
        return node && node->value == target;
    }

    void add(int num) {
        vector<Node*> previous(MAX_LEVEL, head);
        Node* node = head;
        for (int level = levels - 1; level >= 0; --level) {
            while (node->next[level] && node->next[level]->value < num) {
                node = node->next[level];
            }
            previous[level] = node;
        }

        int nodeLevel = randomLevel();
        if (nodeLevel > levels) {
            for (int level = levels; level < nodeLevel; ++level) {
                previous[level] = head;
            }
            levels = nodeLevel;
        }

        Node* added = new Node(num, nodeLevel);
        for (int level = 0; level < nodeLevel; ++level) {
            added->next[level] = previous[level]->next[level];
            previous[level]->next[level] = added;
        }
    }

    bool erase(int num) {
        vector<Node*> previous(MAX_LEVEL, head);
        Node* node = head;
        for (int level = levels - 1; level >= 0; --level) {
            while (node->next[level] && node->next[level]->value < num) {
                node = node->next[level];
            }
            previous[level] = node;
        }

        Node* removed = node->next[0];
        if (!removed || removed->value != num) return false;
        for (int level = 0; level < static_cast<int>(removed->next.size()); ++level) {
            if (previous[level]->next[level] == removed) {
                previous[level]->next[level] = removed->next[level];
            }
        }
        delete removed;
        while (levels > 1 && !head->next[levels - 1]) --levels;
        return true;
    }
};
