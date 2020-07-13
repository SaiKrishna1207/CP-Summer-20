class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, int r, int c){
        visited[r][c] = true;
        if(r + 1 < board.size() && !visited[r + 1][c] && board[r + 1][c] == 'X')
            dfs(board, visited, r + 1, c);
        
        if(c + 1 < board[r].size() && !visited[r][c + 1] && board[r][c + 1] == 'X')
            dfs(board, visited, r, c + 1);
        
        if(r - 1 >= 0 && !visited[r - 1][c] && board[r - 1][c] == 'X')
            dfs(board, visited, r - 1, c);
        
        if(c - 1 >= 0 && !visited[r][c - 1] && board[r][c - 1] == 'X')
            dfs(board, visited, r, c - 1);
        
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int i, j, k;
        if(!board.size())
            return 0;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        k = 0;
        for(i = 0; i < m; i++){
            for(j = 0;j < n; j++){
                if(board[i][j] == 'X' && !visited[i][j]){
                    dfs(board, visited, i, j);
                    k++;
                }
            }
        }
        return k;
    }
};