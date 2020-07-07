class Solution {
public:
    vector<vector<bool>> visited;
    int ans = 0, zeros = 0;

    void dfs(vector<vector<int>> grid, int r, int c, int count){
        if(grid[r][c] == -1)
            return;
        
        if(grid[r][c] == 2){
            if(count == zeros)
                ans++;
            return;
        }
        count++;
        visited[r][c] = true;
        
        if(r + 1 < grid.size() && !visited[r + 1][c])
            dfs(grid, r + 1, c, count);
        if(r - 1 >= 0 && !visited[r - 1][c])
            dfs(grid, r - 1, c, count);
        if(c + 1 < grid[r].size() && !visited[r][c + 1])
            dfs(grid, r, c + 1, count);
        if(c - 1 >= 0 && !visited[r][c - 1])
            dfs(grid, r, c - 1, count);
        
        visited[r][c] = false;
        count--;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int i, j, x, y;
        if(!grid.size())
            return 0;
        visited.resize(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(i = 0;i < grid.size(); i++){
            for(j = 0;j < grid[i].size(); j++){
                if(grid[i][j] == 0)
                    zeros++;
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                    zeros++;
                    grid[i][j] = 0;
                }
            }
        }
        dfs(grid, x, y, 0);
        return ans;
    }
};