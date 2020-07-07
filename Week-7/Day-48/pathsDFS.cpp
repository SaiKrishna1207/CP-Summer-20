class Solution {
public:
    vector<vector<bool>> visited;
    int ans = 0, zeros = 0;

    void dfs(vector<vector<int>> grid, int r, int c, int count){
        if(r >= grid.size() || r < 0 || c >= grid[r].size() || c < 0 || grid[r][c] == -1 || visited[r][c])
            return;
        
        if(grid[r][c] == 2){
            if(count == zeros)
                ans++;
            return;
        }
        count++;
        visited[r][c] = true;
        
        dfs(grid, r + 1, c, count);
        dfs(grid, r - 1, c, count);
        dfs(grid, r, c + 1, count);
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