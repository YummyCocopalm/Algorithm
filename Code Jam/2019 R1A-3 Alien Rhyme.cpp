#include <bits/stdc++.h>
using namespace std;

class Trie{
    public:
    Trie* ch[26];
    int n;
    Trie(): n(0) {
        for (int i = 0; i < 26; ++i) ch[i] = nullptr;
    }
    void add(string &in) {
        Trie* curr = this;
        ++curr->n;
        for (int i = in.size()-1; i >= 0; --i) {
            int c = in[i]-'A';
            if (!(curr->ch[c])) {
                curr->ch[c] = new Trie();
            }
            curr = curr->ch[c];
            ++curr->n;
        }
    }
    
};

int findPair(Trie *node) {
    if (node->n < 2) {
        return 0;
    } else if (node->n == 2) {
        return 2;
    } else {
        int sum = 0;
        for (int i = 0; i < 26; ++i) {
            if (node->ch[i]) sum += findPair(node->ch[i]);
        }
        return (node->n)-sum >= 2 ? sum+2 : sum;
    }
}

int solve() {
    int num; cin >> num;
    vector<string> words(num);
    for (auto& it: words) cin >> it;
    Trie *root = new Trie();
    for (auto& it: words) root->add(it);
    int sum = 0;
    for (int i = 0; i < 26; ++i) if (root->ch[i])
        sum += findPair(root->ch[i]);
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << "\n";
    }
}
