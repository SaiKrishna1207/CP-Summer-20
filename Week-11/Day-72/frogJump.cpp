class Solution {
public:
    bool canCross(vector<int>& A) {
        int i, j, k;
        if(!A.size())
            return true;
        int n = A.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[0][1] = true;
        
        for(i = 1; i < n; i++){
            for(j = 0;j < i; j++){
                k = A[i] - A[j];
                if(k < n && dp[j][k]){
                    if(i == n - 1)
                        return true;
                    dp[i][k] = true;
                    if(k + 1 < n)
                        dp[i][k + 1] = true;
                    if(k - 1 >= 0 && k - 1 < n)
                        dp[i][k - 1] = true;
                }
            }
        }
        return false;
    }
};