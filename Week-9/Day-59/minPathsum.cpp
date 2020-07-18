class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int i, j, k;
        if(!A.size())
            return 0;
        int n = A.size();
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));
        dp[0] = A[0];
        int ans = INT_MAX;
        if(n == 1){
            for(i = 0;i < n; i++)
                ans = min(ans, A[0][i]);
            return ans;
        }
        for(i = 1;i < n; i++){
            for(j = 0;j < n; j++){
                if(j == 0)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + A[i][j];
                else if(j == A[i].size() - 1)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + A[i][j];
                else
                    dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i - 1][j + 1]}) + A[i][j];
                if(i == n - 1)
                    ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};