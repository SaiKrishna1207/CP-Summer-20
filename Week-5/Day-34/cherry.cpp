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
                    int x = -1, d = grid[a][j];
                    if (j != k)
                        d += grid[b][k];
                    
                    if (j > 0 && k > 0 && dp[j - 1][k - 1] >= 0) 
                        x = max(x, dp[j - 1][k - 1] + d);
                    
                    if (j > 0 && b > 0 && dp[j - 1][k] >= 0) 
                        x = max(x, dp[j - 1][k] + d);
                    
                    if (a > 0 && k > 0 && dp[j][k - 1] >= 0) 
                        x = max(x, dp[j][k - 1] + d);
                    
                    if (a > 0 && b > 0 && dp[j][k] >= 0)
                        x = max(x, dp[j][k] + d);
                    
                    dp[j][k] = x;
                }
            }
        }
        if(dp[n - 1][n - 1] < 0)
            return 0;
        return dp[n - 1][n - 1];
    }
};