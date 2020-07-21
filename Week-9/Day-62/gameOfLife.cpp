class Solution {
public:
    bool inBoard(int r, int c, int m, int n){
        if(r < m && r >= 0 && c < n && c >= 0)
            return true;
        return false;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int i, j, k;
        int m = board.size();
        if(!m)
            return;
        vector<vector<int>> dir = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        int n = board[0].size();
        for(i = 0;i < m; i++){
            for(j = 0;j < n; j++){
                int sum = 0;
                for(k = 0; k < 8 ;k++){
                    int r = i + dir[k][0];
                    int c = j + dir[k][1];
                    if(inBoard(r, c, m, n)){
                        if(board[r][c] >= 1)
                            sum++;
                    }
                }
                if(board[i][j] == 1)
                    board[i][j] += sum;
                else
                    board[i][j] -= sum;
            }
        }
        for(i = 0;i < m; i++){
            for(j = 0;j < n; j++){
                if(board[i][j] == 0)
                    continue;
                else if(board[i][j] < 0){
                    if(board[i][j] == -3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 0;
                }
                else{
                    if(board[i][j] == 1 || board[i][j] == 2)
                        board[i][j] = 0;
                    else if(board[i][j] == 3 || board[i][j] == 4)
                        board[i][j] = 1;
                    else
                        board[i][j] = 0;
                }
            }
        }
        return;
    }
};