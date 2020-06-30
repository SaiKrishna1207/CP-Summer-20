class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int i, j, k = 0;
        if(!A.size() || !B.size())
            return 0;
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(i = m - 1; i >= 0; i--){
            for(j = n - 1;j >= 0; j--){
                if(A[i] == B[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                k = max(k, dp[i][j]);
            }
        }
        return k;
    }
};