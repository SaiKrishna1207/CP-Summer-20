class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int plen = (2 * n) - 1;
        vector<vector<int> > dp(n, vector<int>(n, -1));
        dp[0][0] = grid[0][0];
        int i, j, k;
        
        for (i = 2; i <= plen; i++) \
        {
            for (int j = n - 1; j >= 0; j--) 
            {
                for (k = j; k >= 0; k--) 
                {
                    int a = i - 1 - j;
                    int b = i - 1 - k;
                    if (a < 0 || b < 0 || a >= n || b >= n)
                        continue;
                    if (grid[a][j] < 0 || grid[b][k] < 0) 
                    {
                        dp[j][k] = -1;
                        continue;
                    }   
                    int best = -1, delta = grid[a][j];
                    if (j != k)
                        delta += grid[b][k];
                    
                    if (j > 0 && k > 0 && dp[j - 1][k - 1] >= 0) 
                        best = max(best, dp[j - 1][k - 1] + delta);
                    
                    if (j > 0 && b > 0 && dp[j - 1][k] >= 0) 
                        best = max(best, dp[j - 1][k] + delta);
                    
                    if (a > 0 && k > 0 && dp[j][k - 1] >= 0) 
                        best = max(best, dp[j][k - 1] + delta);
                    
                    if (a > 0 && b > 0 && dp[j][k] >= 0)
                        best = max(best, dp[j][k] + delta);
                    
                    dp[j][k] = best;
                }
            }
        }
        if(dp[n - 1][n - 1] < 0)
            return 0;
        return dp[n - 1][n - 1];
    }
};