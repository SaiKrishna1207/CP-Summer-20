int Solution::isMatch(const string s, const string p) {
    int i, j, k, m = s.length(), n = p.length();
    if(!m && !n)
        return true;
    if(!m || !n)
        return false;
        
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for(i = 1;i <= n; i++){
        if(p[i - 1] == '*')
            dp[0][i] = dp[0][i - 2];
    }
    
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            if(p[j - 1] == '.' || p[j - 1] == s[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else if(p[j - 1] == '*'){
                dp[i][j] = dp[i][j - 2];
                if(p[j - 2] == '.' || p[j - 2] == s[i - 1])
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
            }
            else
                dp[i][j] = false;
        }
    }
    return dp[m][n];
}
