class Solution {
public:
    double new21Game(int N, int K, int W) {
        int last_score = min(N, K + W - 1);
        vector<double> dp(last_score + 2);
        dp[0] = 1;
        double wsum = 0;
        int i;
        for (i = 0; i <= last_score; ++i) { 
            if (i < K) 
                wsum += dp[i];
            if (i - W >= 0) 
                wsum -= dp[i - W];
            dp[i+1] = wsum/W;
        }
        double ans = 0;
        for(i = K; i <= N; i++)
            ans += dp[i];
        return ans;
    }
};