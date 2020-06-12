#include <bits/stdc++.h>

using namespace std;

struct Info{
    int x, y, dir, step;
    Info(): x(0), y(0), dir(0), step(0) {}
    Info(int _x, int _y, int _dir, int _step):
        x(_x), y(_y), dir(_dir), step(_step) {}
};

const int B_MAX = 100;
const int DIR[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int n;
bool visited[B_MAX][B_MAX][4];
vector<vector<int>> board;

bool isIn(const int& x, const int& y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void markVisited(const int& x, const int& y, const int& dir) {
    visited[x][y][dir] = true;
    visited[x + DIR[dir][0]][y + DIR[dir][1]][(dir + 2) % 4] = true;
}

bool isVisited(const int& x, const int& y, const int& dir) {
    return visited[x][y][dir]
        || visited[x + DIR[dir][0]][y + DIR[dir][1]][(dir + 2) % 4];
}

bool isPushMoving(const int& x1, const int& y1,
                  const int& x2, const int& y2, const int& dir) {
    return !board[x1][y1] && !board[x2][y2] && !isVisited(x1, y1, dir);
}

bool isPushRotating(const int& x1, const int& y1,
                    const int& dir1, const int& dir2) {
    bool pt1 = !board[x1+DIR[dir1][0]][y1+DIR[dir1][1]];
    bool pt2 = !board[x1+DIR[dir2][0]][y1+DIR[dir2][1]];
    bool pt3 = !board[x1+DIR[dir1][0]+DIR[dir2][0]][y1+DIR[dir1][1]+DIR[dir2][1]];
    return pt1 && pt2 && pt3 && !isVisited(x1, y1, dir2);
}

void checkMoving(const Info &curr, queue<Info> &q) {
    for (int i = 0; i < 4; ++i) {
        int x1 = curr.x + DIR[i][0];
        int y1 = curr.y + DIR[i][1];
        int x2 = x1 + DIR[curr.dir][0];
        int y2 = y1 + DIR[curr.dir][1];
        if (isIn(x1, y1) && isIn(x2, y2)) {
            if (isPushMoving(x1, y1, x2, y2, curr.dir)) {
                q.push(Info(x1, y1, curr.dir, curr.step+1));
                markVisited(x1, y1, curr.dir);
            }
        }
    }
}

void checkRotating(const Info &curr, queue<Info> &q) {
    int checkDir[2] = {1, -1};
    for (int i = 0; i < 2; ++i) {
        int dir = (curr.dir + checkDir[i] + 4) % 4;
        int x = curr.x + DIR[dir][0];
        int y = curr.y + DIR[dir][1];
        if (isIn(x, y)) {
            if (isPushRotating(curr.x, curr.y, curr.dir, dir)) {
                q.push(Info(curr.x, curr.y, dir, curr.step+1));
                markVisited(curr.x, curr.y, dir);
            }
        }
    }
}

bool isEnd(const Info &curr) {
    int x2 = curr.x + DIR[curr.dir][0];
    int y2 = curr.y + DIR[curr.dir][1];
    return (curr.x == n-1 && curr.y == n-1) || (x2 == n-1 && y2 == n-1);
}

int solution(vector<vector<int>> _board) {
    board = _board;
    n = _board.size();
    
    queue<Info> q;
    Info curr;
    q.push(curr);
    markVisited(curr.x, curr.y, curr.dir);
    while (!q.empty()) {
        curr = q.front();
        if (isEnd(curr)) break;
        q.pop();
        checkMoving(curr, q);
        checkRotating(curr, q);
        curr.x += DIR[curr.dir][0];
        curr.y += DIR[curr.dir][1];
        curr.dir = (curr.dir + 2) % 4;
        checkRotating(curr, q);
    }
    return curr.step;
}