#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<bool>> visited;
    int R, C, oR, oC, pR, pC;
public:
    Solution(): R(0), C(0), oR(0), oC(0), pR(0), pC(0), visited(vector<vector<bool>>(1)) {}
    Solution(int _R, int _C, int _oR, int _oC, int _pR, int _pC)
        : R(_R), C(_C), oR(_oR), oC(_oC), pR(_pR), pC(_pC) {
        visited = vector<vector<bool>>(R, vector<bool>(C));
    }

    bool dfs(int count, int cR, int cC, vector<pair<int, int>> &ans) {
        if (count == R*C) return true;
        for (int i = 0; i < R; ++i) {
            if (i == cR) continue;
            for (int j = 0; j < C; ++j) {
                if (j == cC) continue;
                if (i-j == cR-cC) continue;
                if (i+j == cR+cC) continue;
                if (visited[i][j]) continue;
                visited[i][j] = true;
                ans.push_back({oR+i+1, oC+j+1});
                if (dfs(count+1, i, j, ans)) return true;
                ans.pop_back();
                visited[i][j] = false;
            }
        }
        return false;
    }

    vector<pair<int, int>> solve() {
        vector<pair<int, int>> ans;
        for (int i = 0; i < R; ++i) {
            if (oR+i == pR) continue;
            for (int j = 0; j < C; ++j) {
                if (oC+j == pC) continue;
                if (oR+i-oC-j == pR-pC) continue;
                if (oR+i+oC+j == pR+pC) continue;
                visited[i][j] = true;
                ans.push_back({oR+i+1, oC+j+1});
                if (dfs(1, i, j, ans)) return ans;
            }
        }
        return ans;
    }
};

void splitRC(vector<int>& vec, int size, int sp) {
    while (size > 0) {
        vec.push_back(size > sp ? sp:size);
        size -= vec[vec.size()-1];
    }
    if (vec.back() < sp && vec.size() > 1) {
        int v = vec.back();
        vec.pop_back();
        vec[vec.size()-1] += v;
    }
}

void showAns(vector<pair<int, int>> &ans, bool &sw) {
    if (!sw) {
        for (auto &it: ans) cout << it.first << " " << it.second << "\n";
    } else {
        for (auto &it: ans) cout << it.second << " " << it.first << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        int R, C;
        cin >> R >> C;
        cout << "Case #" << t << ": ";
        bool sw = false;
        if (C < R) {
            swap(R, C);
            sw = true;
        }
        if ((R == 2 && C < 5) || (R == 3 && C < 4)) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << "POSSIBLE\n";
        vector<int> rows, cols;
        splitRC(rows, R, 3);
        if (R == 2) splitRC(cols, C, 5);
        else        splitRC(cols, C, 4);
        vector<pair<int, int>> ans;
        ans.push_back({0,0});
        int rSum = 0, cSum = 0;
        for (int i = 0; i < rows.size(); ++i) {
            cSum = 0;
            for (int j = 0; j < cols.size(); ++j) {
                Solution sol(rows[i], cols[j], rSum, cSum, ans.back().first-1, ans.back().second-1);
                ans = sol.solve();
                showAns(ans, sw);
                cSum += cols[j];
            }
            rSum += rows[i];        
        }
    }
}
