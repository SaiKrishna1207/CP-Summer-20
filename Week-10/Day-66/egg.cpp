class Solution {
public:
    int superEggDrop(int K, int N) {
        int i, j, k;
        if(N == 0)
            return 0;
        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        for(i = 0;i <= N; i++)
            dp[1][i] = i;
        for(i = 2; i <= K; i++){
            for(j = 1; j <= N; j++){
                if(i > j)
                    dp[i][j] = dp[i - 1][j];
                else{
                    int mn = INT_MAX;
                    for(k = 1;k <= j; k++){
                        int mx = max(dp[i - 1][k - 1], dp[i][j - k]) + 1;
                        mn = min(mn, mx);
                    }
                    dp[i][j] = mn;
                }
            }
        }
        return dp[K][N];
    }
};