class Solution {
public:
    
    int l, m;
    int visited[205][205];
    
    bool dfs(vector<vector<char>> & grid, string word, int x, int y, int i)
    {
        if(i < l)
        {
            bool ans;
            visited[x][y] = 1;
            if(y + 1 < grid[x].size() && grid[x][y + 1] == word[i] && !visited[x][y + 1])
            {
                ans = dfs(grid, word, x, y + 1, i + 1);
                if(ans)
                    return ans;
                visited[x][y + 1] = 0;
            }
            if(y - 1 >= 0 && grid[x][y - 1] == word[i] && !visited[x][y - 1])
            {
                ans = dfs(grid, word, x, y - 1, i + 1);
                if(ans)
                    return ans;
                visited[x][y - 1] = 0;
            }
            if(x + 1 < m && grid[x + 1][y] == word[i] && !visited[x + 1][y])
            {
                ans = dfs(grid, word, x + 1, y, i + 1);
                if(ans)
                    return ans;
                visited[x + 1][y] = 0;
            }
            if(x - 1 >= 0 && grid[x - 1][y] == word[i] && !visited[x - 1][y])
            {
                ans = dfs(grid, word, x - 1, y, i + 1);
                if(ans)
                    return ans;
                visited[x - 1][y] = 0;
            }
        }
        if(i == l)
            return true;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        int i, j, k;
        l = word.length();
        m = board.size();
        char a = word[0];
        bool res;
        for(i = 0;i < m; i++)
        {
            for(j = 0;j < board[i].size(); j++)
            {
                if(board[i][j] == a)
                {
                    if(dfs(board, word, i, j, 1))
                        return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};