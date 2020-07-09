class Solution {
public:
    int memo(vector<vector<int>>& dp, int dish, int time, vector<int>& sat){
        if(dish == sat.size())
            return 0;
        if(dp[dish][time - 1] == 0){
            int k = (sat[dish] * time) + memo(dp, dish + 1, time + 1, sat);
            int j = memo(dp, dish + 1, time, sat);
            dp[dish][time - 1] = max(j, k);
        }
        
        return dp[dish][time - 1];
    }
    
    int maxSatisfaction(vector<int>& sat) {
        int i, j, k, n = sat.size();
        if(!n)
            return 0;
        sort(sat.begin(), sat.end());
        if(sat[n - 1] <= 0)
            return 0;
        if(sat[0] > 0){
            for(i = 0;i < n; i++)
                k += sat[i] * (i + 1);
            return k;
        }
        vector<vector<int>> dp(n, vector<int> (n + 1, 0));
        j = memo(dp, 0, 1, sat);
        
        return j;
    }
};