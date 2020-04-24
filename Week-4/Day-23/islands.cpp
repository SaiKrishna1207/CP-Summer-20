
class Solution {
public:
    
    int count = 0;
    
    void dfs(vector<vector<char>> & grid, int x, int y, vector<vector<int>> & visited)
    {
        visited[x][y] = 1;
        if(y + 1 < grid[x].size() && grid[x][y + 1] == '1' && !visited[x][y + 1])
            dfs(grid, x, y + 1, visited);
        if(y - 1 >= 0 && grid[x][y - 1] == '1' && !visited[x][y - 1])
            dfs(grid, x, y - 1, visited);
        if(x + 1 < grid.size() && grid[x + 1][y] == '1' && !visited[x + 1][y])
            dfs(grid, x + 1, y, visited);
        if(x - 1 >= 0 && grid[x - 1][y] == '1' && !visited[x - 1][y])
            dfs(grid, x - 1, y, visited);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int i, j, k;
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(i = 0;i < grid.size(); i++)
        {
            for(j = 0;j < grid[i].size(); j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
};