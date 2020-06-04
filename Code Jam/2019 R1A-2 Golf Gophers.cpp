#include <bits/stdc++.h>
using namespace std;
const int DAY_MAX = 7;
const int WM_MAX = 18;
const int BLADE[DAY_MAX] = {12, 13, 14, 15, 16, 17, 18};

int solve() {
    int rest[DAY_MAX];
    for (int i = 0; i < DAY_MAX; ++i) {
        for (int j = 0; j < WM_MAX; ++j) {
            cout << BLADE[i] << " ";
        }
        cout << endl;
        int restSum = 0, r;
        for (int j = 0; j < WM_MAX; ++j) {
            cin >> r;
            restSum += r;
        }
        restSum %= BLADE[i];
        rest[i] = restSum;
    }
    int tar = !rest[DAY_MAX-1] ? BLADE[DAY_MAX-1] : rest[DAY_MAX-1];
    bool found = true;
    while (true) {
        found = true;
        for (int i = 0; i < DAY_MAX; ++i) {
            if (rest[i] != (tar % BLADE[i])) {
                found = false;
                break;
            }
        }
        if (found) break;
        tar += BLADE[DAY_MAX-1];
    }
    return tar;
}

int main() {
    ios::sync_with_stdio(false);

    int t, n, m;
    cin >> t >> n >> m;
    while (t--) {
        cout << solve() << endl;
        int verdict;
        cin >> verdict;
        if (verdict == -1) break;
    }
}
