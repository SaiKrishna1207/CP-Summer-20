int Solution::isMatch(const string s, const string B) {
    int m = s.length(), n = B.length(), i, j, k;
    if(!m && !n)
        return true;
    if(!m || !n)
        return false;
    int l = 0;
    bool kk = true;
    string p = B;
    for(i = 0;i < p.length(); i++){
        if(p[i] == '*'){
            if(kk){
                p[l++] = p[i];
                kk = false;
            }
        }
        else{
            p[l++] = p[i];
            kk = true;
        }
    }
    vector<vector<bool>> dp(m + 1, vector<bool>(l + 1, false));
    dp[0][0] = true;
    if(p[0] == '*')
        dp[0][1] = true;
    for(i = 1; i <= m; i++){
        for(j = 1; j <= l; j++){
            if(p[j - 1] == s[i - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if(p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[m][l];
}