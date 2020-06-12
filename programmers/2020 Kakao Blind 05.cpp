#include <bits/stdc++.h>
using namespace std;

enum {VER = 0, HOR = 1, DEL = 0, ADD = 1};
const int N_MAX = 100;
bool st[N_MAX+1][N_MAX+1][2] = {false};

bool addVer(int &x, int &y, int &n) {
    if (st[x][y][VER] || y == n) return false;
    if (y == 0) {
        return true;
    }
    else if (st[x][y-1][VER]) {
        return true;
    }
    else if (x == 0) {
        return st[x][y][HOR];
    }
    else if (x == n) {
        return st[x-1][y][HOR];
    }
    else {
        return st[x][y][HOR] || st[x-1][y][HOR];
    }
}

bool addHor(int &x, int &y, int &n) {
    if (st[x][y][HOR] || x == n || y == 0) return false;
    if (st[x][y-1][VER] || st[x+1][y-1][VER]) {
        return true;
    }
    else if (x == 0 || x == n-1) {
        return false;
    }
    else {
        return st[x-1][y][HOR] && st[x+1][y][HOR];
    }
}

bool eraseVer(int &x, int &y, int &n) {
    if (!st[x][y][VER]) return false;
    bool left = false, right = st[x][y+1][HOR];
    if (x != 0) left = st[x-1][y+1][HOR];
    if (left && right) {
        bool leftSafe = false, rightSafe = false;
        if (st[x+1][y+1][HOR] || st[x+1][y][VER]) rightSafe = true;
        if (st[x-1][y][VER]) leftSafe = true;
        else if (x < 2) leftSafe = false;
        else leftSafe = st[x-2][y+1][HOR];
        return leftSafe && rightSafe;
    }
    else if (left) {
        return st[x-1][y][VER];
    }
    else if (right) {
        return st[x+1][y][VER];
    }
    else {
        return !st[x][y+1][VER];
    }
}

bool eraseHor(int &x, int &y, int &n) {
    if (!st[x][y][HOR]) return false;
    bool left = false, right = st[x+1][y][HOR];
    if (x != 0) left = st[x-1][y][HOR];
    if (left) {
        if (!st[x-1][y-1][VER] && !st[x][y-1][VER]) return false;
    }
    if (right) {
        if (!st[x+1][y-1][VER] && !st[x+2][y-1][VER]) return false;
    }
    if (y != n) {
        if (!left && st[x][y][VER] && !st[x][y-1][VER]) return false;
        if (!right && st[x+1][y][VER] && !st[x+1][y-1][VER]) return false;
    }
    return true;
}

void updatest(int &x, int &y, int &a, int &b, int &n) {
    if (a == VER && b == ADD) {
        if (addVer(x, y, n)) st[x][y][VER] = true;
    }
    else if (a == VER && b == DEL) {
        if (eraseVer(x, y, n)) st[x][y][VER] = false;
    }
    else if (a == HOR && b == ADD) {
        if (addHor(x, y, n)) st[x][y][HOR] = true;
    }
    else {
        if (eraseHor(x, y, n)) st[x][y][HOR] = false;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for (auto &it: build_frame)
        updatest(it[0], it[1], it[2], it[3], n);
    vector<vector<int>> ans;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (st[i][j][VER]) ans.push_back({i, j, VER});
            if (st[i][j][HOR]) ans.push_back({i, j, HOR});
        }
    }
    return ans;
}