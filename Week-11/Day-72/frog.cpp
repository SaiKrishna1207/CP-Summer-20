class Solution {
public:
    bool canCross(vector<int>& A) {
        int i, j, k;
        if(!A.size())
            return true;
        int step = 1; 
        int n = A.size();
        vector<bool> dp(n, false);
        unordered_map<int, vector<int>> mp;
        mp[0] = {0};        
        dp[0] = true;
        
        for(i = 1; i < n; i++){
            for(j = i - 1; j >= 0; j--){
                for(auto k : mp[j]){
                    if(A[i] - A[j] >= k - 1 && A[i] - A[j] <= k + 1 && dp[j]){
                        mp[i].push_back(A[i] - A[j]);
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};