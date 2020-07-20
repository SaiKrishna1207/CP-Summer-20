class Solution {
public:
    int numWays(int steps, int arrLen) {
        int i, j, k;
        if(steps == 1)
            return 1;
        int maxIndex = min(arrLen, (steps / 2) + 1);
        vector<vector<int>> dp(maxIndex, vector<int> (steps + 1, 0));
        dp[0][0] = 1;
        for(i = 1; i <= steps; i++){
            for(j = 0; j < maxIndex; j++){
                if(j > 0)
                    dp[j][i] = (dp[j][i] + dp[j - 1][i - 1]) % 1000000007;
                if(j < maxIndex - 1)
                    dp[j][i] = (dp[j][i] + dp[j + 1][i - 1]) % 1000000007;
                dp[j][i] = (dp[j][i] + dp[j][i - 1])%1000000007;
            }
        }
        return dp[0][steps];
    }
};