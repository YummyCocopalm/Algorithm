#include <string>
#include <vector>

using namespace std;
using vvi = vector<vector<int>>;

vvi rotateCCW(vvi& key) {
    int m = key.size();
    vvi out(m, vector<int>(m));
    for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j)
        out[i][j] = key[j][m-1-i];
    return out;
}

vvi padLock(vvi& lock, int pad) {
    int n = lock.size();
    vvi out(2*pad+n, vector<int>(2*pad+n));
    for (int i = 0; i < pad; ++i) for (int j = 0; j < 2*pad+n; ++j)
        out[i][j] = 2;
    for (int i = pad; i < pad+n; ++i) {
        for (int j = 0; j < pad; ++j) out[i][j] = 2;
        for (int j = pad; j < pad+n; ++j) out[i][j] = lock[i-pad][j-pad];
        for (int j = pad+n; j < 2*pad+n; ++j) out[i][j] = 2;
    }
    for (int i = pad+n; i < 2*pad+n; ++i) for (int j = 0; j < 2*pad+n; ++j)
        out[i][j] = 2;
    return out;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size();
    int count = 0, keys = 0;
    for (auto& it1: lock) for (auto& it2: it1) if (it2 == 0)
        ++count;
    for (auto& it1: key) for (auto& it2: it1) if (it2 == 1)
        ++keys;
    if (count == 0) return true;
    if (count > keys) return false;
    lock = padLock(lock, m-1);
    int n = lock.size();
    bool ans = false, fail;
    for (int rot = 0; rot < 4; ++rot) {
        for (int i = 0; i < n-m+1 && !ans; ++i) for (int j = 0; j < n-m+1 && !ans; ++j) {
            int localCnt = 0;
            fail = false;
            for (int k = 0; k < m && !fail; ++k) for (int l = 0; l < m && !fail; ++l) {
                if (lock[i+k][j+l] == 2) continue;
                if (lock[i+k][j+l] == 1 && key[k][l] == 1) {
                    fail = true;
                    break;
                }
                if (lock[i+k][j+l] == 0 && key[k][l] == 0) {
                    fail = true;
                    break;
                }
                if (lock[i+k][j+l] == 0 && key[k][l] == 1) ++localCnt;
            }
            if (fail) continue;
            if (localCnt == count) {
                ans = true;
                break;
            }
        }
        if (ans) break;
        key = rotateCCW(key);
    }
    return ans;
}