#include <string>
#include <vector>

using namespace std;

int charToint(char in) {
    if ('a' <= in && in <= 'z') return in-'a';
    return 26;
}

class Trie {
public:
    Trie *chid[27] = {NULL};
    int val = 0;
    Trie() {}
    ~Trie() {
        for (int i = 0; i < 27; ++i) delete(this->chid[i]);
    }
    void insert(const char* s) {
        if (this->chid[charToint(s[0])] == NULL) this->chid[charToint(s[0])] = new Trie();
        if (s[1] == 0) return;
        this->chid[charToint(s[0])]->insert(s+1);
    }
    void add(const char* s) {
        if (this->chid[charToint(s[0])] != NULL) {
            if (s[1] == 0) ++(this->chid[charToint(s[0])]->val);
            else this->chid[charToint(s[0])]->add(s+1);
        }
        if (this->chid[26] != NULL) {
            if (s[1] == 0) ++(this->chid[26]->val);
            else this->chid[26]->add(s+1);
        }
    }
    int getVal(const char* s) {
        if (this->chid[charToint(s[0])] == NULL) return 0;
        if (s[1] == 0) return this->chid[charToint(s[0])]->val;
        return this->chid[charToint(s[0])]->getVal(s+1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    int maxLen = 0;
    for (auto &it: queries) maxLen = maxLen > it.size() ? maxLen : it.size();
    vector<Trie*> save(maxLen, new Trie());
    for (auto &it: queries) {
        //if (save[it.size()-1] == NULL) save[it.size()-1] = new Trie();
        save[it.size()-1]->insert(it.c_str());
    }
    for (auto &it: words) {
        //if (save[it.size()-1] == NULL) continue;
        save[it.size()-1]->add(it.c_str());
    }
    
    vector<int> ans;
    for (auto &it: queries) ans.push_back(save[it.size()-1]->getVal(it.c_str()));
    return ans;
}