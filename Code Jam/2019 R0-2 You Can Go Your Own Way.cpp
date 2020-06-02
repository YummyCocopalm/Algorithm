#include <bits/stdc++.h>
using namespace std;

string solve(string &s) {
    string out;
    for (auto &it: s) {
        if (it == 'E') out += 'S';
        else out += 'E';
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int i = 1; i <= T; ++i) {
        int n; cin >> n;
        string s; cin >> s;
        string ans = solve(s);
        cout << "Case #" << i << ": " << ans << "\n";
    }
}
