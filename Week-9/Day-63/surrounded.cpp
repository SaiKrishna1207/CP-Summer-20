class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>> &board, int r, int c, int m, int n){
        int i, j;
        board[r][c] = '.';
        for(i = 0;i < 4; i++){
            int x = r + dir[i][0];
            int y = c + dir[i][1];
            if(x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O')
                dfs(board, x, y, m, n);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int i, j, k;
        int m = board.size();
        if(!m)
            return;
        int n = board[0].size();
        for(i = 0;i < m; i++){
            if(board[i][0] == 'O')
                dfs(board, i, 0, m, n);
            if(board[i][n - 1] == 'O')
                dfs(board, i, n - 1, m, n);
        }
        
        for(i = 0;i < n; i++){
            if(board[0][i] == 'O')
                dfs(board, 0, i, m, n);
            if(board[m - 1][i] == 'O')
                dfs(board, m - 1, i, m, n);
        }
        
        for(i = 0;i < m; i++){
            for(j = 0;j < n; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '.')
                    board[i][j] = 'O';
            }
        }
        return;
    }
};