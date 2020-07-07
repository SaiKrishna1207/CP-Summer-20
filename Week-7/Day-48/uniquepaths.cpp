class Solution {
public:
    vector<vector<bool>> visited;
    int ans = 0;
    
    bool check(vector<vector<int>> grid){
        int i, j;
        for(i = 0;i < grid.size(); i++){
            for(j = 0;j < grid[0].size(); j++){
                if(grid[i][j] == 0 && visited[i][j] != true)
                    return false;
            }
        }
        return true;
    }
    
    void dfs(vector<vector<int>> grid, int r, int c){
        if(r >= grid.size() || r < 0 || c >= grid[r].size() || c < 0 || grid[r][c] == -1 || visited[r][c])
            return;
        
        if(grid[r][c] == 2){
            if(check(grid))
                ans++;
            return;
        }
        visited[r][c] = true;
        
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
        
        visited[r][c] = false;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int i, j, k;
        if(!grid.size())
            return 0;
        visited.resize(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(i = 0;i < grid.size(); i++){
            for(j = 0;j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    break;
                }
            }
        }
        return ans;
    }
};