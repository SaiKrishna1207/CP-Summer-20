int Solution::minDistance(string A, string B) {
    int i, j, k;
    int l1 = A.length();
    int l2 = B.length();
    vector<vector<int>> dp(l1 + 1, vector<int> (l2 + 1, 0));
    
    for(i = 0; i <= l1; i++)
        dp[i][0] = i;
    for(i = 0;i <= l2; i++)
        dp[0][i] = i;
    dp[0][0] = 0;
    for(i = 1; i <= l1; i++){
        for(j = 1; j <= l2; j++){
            if(A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
        }
    }
    return dp[l1][l2];
}
