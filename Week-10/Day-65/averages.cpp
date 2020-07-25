class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if(A.empty() || K == 0)
            return 0;
        int i, j, k;
        vector<vector<double>> dp(K+1,vector<double>(A.size(),0));
        vector<int> sum;
        sum.push_back(A[0]);
        for(i = 1; i < A.size(); i++)
            sum.push_back(A[i] + sum[i - 1]);
    
        for(k = 1; k <= K; k++){
            for(i = k - 1; i < A.size(); i++){
                if(k == 1)
                    dp[k][i] = double(sum[i]) / (i + 1);
                else{
                    for(j = k - 2 ; j < i; j++){
                        dp[k][i] = max(dp[k - 1][j] + double(sum[i] - sum[j]) / (i - j), dp[k][i]);
                    }
                }
            }
        }
        return dp[K][A.size() - 1];
    }
};