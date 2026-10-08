#include <string>
using namespace std;
class WordDictionary {
    struct N {
        N* c[26];
        bool e;
        N() : e(0) {
            for (int i = 0; i < 26; i++) c[i] = 0;
        }
    }* r;
    bool f(N* p, string& s, int i) {
        if (i == s.size()) return p->e;
        if (s[i] == '.') {
            for (int j = 0; j < 26; j++)
                if (p->c[j] && f(p->c[j], s, i + 1)) return true;
            return false;
        }
        return p->c[s[i] - 'a'] && f(p->c[s[i] - 'a'], s, i + 1);
    }

public:
    WordDictionary() : r(new N) {}
    void addWord(string w) {
        N* p = r;
        for (char x : w) {
            if (!p->c[x - 'a']) p->c[x - 'a'] = new N;
            p = p->c[x - 'a'];
        }
        p->e = 1;
    }
    bool search(string w) { return f(r, w, 0); }
};
