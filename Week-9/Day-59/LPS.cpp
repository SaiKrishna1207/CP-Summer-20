class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        int i, j, k, len;
        for(i = 0;i < n; i++) 
            dp[i][i] = 1;
        
        for(len = 2;len <= n; len++)
        {
            for(i = 0;i < n - len + 1; i++)
            {
                j = len + i - 1;
                if(len == 2 && s[i] == s[j])
                    dp[i][j] = 2;
                
                else if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                
                else 
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};
