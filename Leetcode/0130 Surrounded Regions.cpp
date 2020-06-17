const int DIR[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

class Solution {
    int row = 0, col = 0;
public:
    void dfs(int r, int c, vector<vector<bool>> &visited, vector<vector<char>> &board) {
        for (int i = 0; i < 4; ++i) {
            int nextr = r + DIR[i][0];
            int nextc = c + DIR[i][1];
            if (!(0 <= nextr && nextr < row && 0 <= nextc && nextc < col)) continue;
            if (board[nextr][nextc] == 'X') continue;
            if (visited[nextr][nextc]) continue;
            visited[nextr][nextc] = true;
            dfs(nextr, nextc, visited, board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        row = board.size();
        col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col));
        for (int i = 0; i < row; ++i) {
            if (visited[i][0] || board[i][0] == 'X') continue;
            visited[i][0] = true;
            dfs(i, 0, visited, board);
        }
        for (int i = 0; i < row; ++i) {
            if (visited[i][col-1] || board[i][col-1] == 'X') continue;
            visited[i][col-1] = true;
            dfs(i, col-1, visited, board);
        }
        for (int i = 0; i < col; ++i) {
            if (visited[0][i] || board[0][i] == 'X') continue;
            visited[0][i] = true;
            dfs(0, i, visited, board);
        }
        for (int i = 0; i < col; ++i) {
            if (visited[row-1][i] || board[row-1][i] == 'X') continue;
            visited[row-1][i] = true;
            dfs(row-1, i, visited, board);
        }
        for (int i = 1; i < row-1; ++i) {
            for (int j = 1; j < col-1; ++j) {
                if (visited[i][j] || board[i][j] == 'X') continue;
                board[i][j] = 'X';
            }
        }
    }
};