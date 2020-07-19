class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int i, j, k;
        if(!A.size())
            return 0;
        int n = A.size();
        vector<vector<long>> dp(n, vector<long> (n, 0));
        bool isThere;
        long ans = INT_MIN;
        dp[0][0] = 0;
        for(i = 2; i < n; i++){
            for(j = i - 1; j > 0; j--){
                k = A[i] - A[j];
                isThere = false;
                int l = 0;
                int r = j - 1;
                int index;
                while(l <= r){
                    int m = l + ((r - l) / 2);
                    if(A[m] == k){
                        index = m;
                        isThere = true;
                        break;
                    }
                    else if(A[m] > k) 
                        r = m - 1;
                    else
                        l = m + 1;
                }
                if(isThere)
                    dp[i][j] = dp[j][index] + 1;
                
                ans = max(ans, dp[i][j]);
            }
        }
        if(ans > 0)
            return ans + 2;
        return ans;
    }
};