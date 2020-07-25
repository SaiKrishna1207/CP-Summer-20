bool dfs(vector<vector<bool>> &dp, const string &A, const string &B, int i, int j) {
    if(i < 0 && j < 0) 
        return true;
    if(j < 0) 
        return false;
    if(i < 0) {
        while(j >= 0) {
            if(B[j] != '*') 
                return false;
            j--;
        }
        return true;
    }
    if(dp[i][j] == false) 
        return false;
    
    bool check = false;
    
    if(B[j] == '*') 
        check = dfs(dp, A, B, i-1, j) || dfs(dp, A, B, i, j-1);
    else if(B[j] == A[i] || B[j] == '?') 
        check = dfs(dp, A, B, i-1, j-1);
    
    if(check) 
        return true;
    return dp[i][j] = false;
} 
int Solution::isMatch(const string A, const string B) {
    int i, j, k, m = A.length(), n = B.length();
    if(m == 0 || n == 0) 
        return 0;
    vector<vector<bool>> dp(m, vector<bool>(n, true));
    return dfs(dp, A, B, m - 1, n - 1);
}