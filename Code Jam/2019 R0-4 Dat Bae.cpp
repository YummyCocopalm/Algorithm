#include <bits/stdc++.h>
using namespace std;

int solve(const int &N) {
    string in[5];
    int p = 16;
    for (int i = 0; i < 5; ++i) {
        string out = "";
        char l = '0';
        int total = N;
        while (total) {
            out += string(min(total, p), l);
            if (l == '0') l = '1';
            else l = '0';
            total -= min(total, p);
        }
        cout << out << endl;
        cin >> in[i];
        p /= 2;
    }
    vector<int> broken;
    vector<int> ok;
    int times = 0, prev = -1;
    for (int i = 0; i < in[0].size(); ++i) {
        int curr = 0;
        for (int j = 0; j < 5; ++j) {
            curr <<= 1;
            curr += (in[j][i] - '0');
        }
        if (curr < prev) ++times;
        prev = curr;
        ok.push_back(curr + 32*times);
    }
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        if (idx >= ok.size() || ok[idx] != i) {
            broken.push_back(i);
        } else {
            ++idx;
        }
    }
    for (auto& it: broken) {
        cout << it << " ";
    }
    cout << endl;

    int verdict;
    cin >> verdict;
    return verdict;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, B, F;
        cin >> N >> B >> F;
        if (solve(N) == -1) break;
    }
}
