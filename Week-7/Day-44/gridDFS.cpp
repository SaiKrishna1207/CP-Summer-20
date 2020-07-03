class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>& grid, int N, int r, int c){
        if(!N)
            return;
        grid[r][c] = 1;
        
        if(r == 0)
            ans++;
        if(r == grid.size() - 1)
            ans++;
        if(c == 0)
            ans++;
        if(c == grid[r].size() - 1)
            ans++;
        
        if(r + 1 < grid.size())
        {
            dfs(grid, N - 1, r + 1, c);
            grid[r + 1][c] = 0;
        }
        if(c + 1 < grid[r].size())
        {
            dfs(grid, N - 1, r, c + 1);
            grid[r][c + 1] = 0;
        }
        if(r > 0)
        {
            dfs(grid, N - 1, r - 1, c);
            grid[r - 1][c] = 0;
        }
        if(c > 0)
        {
            dfs(grid, N - 1, r, c - 1);
            grid[r][c - 1] = 0;
        }
    }
    
    int findPaths(int m, int n, int N, int r, int c) {
        int i, j, k;
        if(!N)
            return 0;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        dfs(grid, N, r, c);
        return ans;
    }
};