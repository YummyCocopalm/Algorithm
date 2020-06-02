#include <bits/stdc++.h>
using namespace std;

struct Output {
    string a, b;
    Output(): a(""), b("") {}
};

Output solve(string &s) {
    Output ans;
    for (int i = 0; i < s.size(); ++i) {
        int n, m;
        if ('0' <= s[i] && s[i] <= '6') {
            n = (s[i]-'0')/2;
            m = s[i]-'0'-n;
        } else {
            n = 6;
            m = s[i]-'0'-n;
        }
        if (!ans.a.empty() || n) ans.a += (n+'0');
        if (!ans.b.empty() || m) ans.b += (m+'0');
    }
    if (ans.a.empty()) {
        ans.a += '1';
        ans.b.back() = '0';
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int i = 1; i <= T; ++i) {
        string s;
        cin >> s;
        Output ans = solve(s);
        cout << "Case #" << i << ": " << ans.a << " " << ans.b << "\n";
    }
}
