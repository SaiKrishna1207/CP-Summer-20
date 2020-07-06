class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int i, j, k;
        if(!A.size() || !B.size())
            return 0;
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for(i = 1; i <= A.size(); i++){
            for(j = 1; j <= B.size(); j++){
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if(A[i - 1] == B[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                else
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            }
        }
        return dp[A.size()][B.size()];
    }
};