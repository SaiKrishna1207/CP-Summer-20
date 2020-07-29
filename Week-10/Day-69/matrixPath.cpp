int Solution::solve(vector<vector<int>> &A) {
    int i, j, k;
    if(!A.size())
        return 0;
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> dp(m, vector<int> (n, -1));
    dp[0][0] = 1;
    int ans = 1;
    for(i = 1; i < m; i++){
        if(A[i][0] > A[i - 1][0])
            dp[i][0] = dp[i - 1][0] + 1;
        else
            break;
        ans = max(ans, dp[i][0]);
    }
    for(i = 1; i < n; i++){
        if(A[0][i] > A[0][i - 1])
            dp[0][i] = dp[0][i - 1] + 1;
        else
            break;
        ans = max(ans, dp[0][i]);
    }
    for(i = 1; i < m; i++){
        for(j = 1; j < n; j++){
            if(A[i][j] > A[i - 1][j] && dp[i - 1][j] != -1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
            if(A[i][j] > A[i][j - 1] && dp[i][j - 1] != -1)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
            ans = max(ans, dp[i][j]);
        }
    }
    return dp[m - 1][n - 1];
}
