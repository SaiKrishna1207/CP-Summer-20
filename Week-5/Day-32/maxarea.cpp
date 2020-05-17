class Solution {
public:
    int mx = 0;
    int cur;
    void dfs(vector<vector<int>> & grid, vector<vector<int>> & visited, int row, int col)
    {
        cur++;
        visited[row][col] = 1;
        if(row + 1< grid.size() && !visited[row + 1][col] && grid[row + 1][col])
            dfs(grid, visited, row + 1, col);
        if(row - 1 >= 0 && !visited[row - 1][col] && grid[row - 1][col])
            dfs(grid, visited, row - 1, col);
        if(col + 1 < grid[0].size() && !visited[row][col + 1] && grid[row][col + 1])
            dfs(grid, visited, row, col + 1);
        if(col - 1 >= 0 && !visited[row][col - 1] && grid[row][col - 1])
            dfs(grid, visited, row, col - 1);
        mx = max(mx, cur);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i, j, k;
        int m = grid.size(), n = grid[0].size();
        if(m == 0 || n == 0)
            return 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(i = 0;i < m; i++)
        {
            for(j = 0;j < n; j++)
            {
                if(!visited[i][j] && grid[i][j])
                {
                    cur = 0;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return mx;
    }
};