class Solution {
public:
    static bool sortcol( const vector<int>& v1, const vector<int>& v2 ) { 
        return v1[1] < v2[1]; 
    } 
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int i, j, k;
        if(!startTime.size() || !endTime.size() || !profit.size())
            return 0;
        vector<vector<int>> times;
        for(i = 0;i < startTime.size(); i++)
            times.push_back({startTime[i], endTime[i], profit[i]});
        sort(times.begin(), times.end(), sortcol);
        vector<int> dp(times.size(), 0);
        dp[0] = times[0][2];
        for(i = 1;i < profit.size(); i++)
        {
            dp[i] = max(dp[i - 1], times[i][2]);
            for(int j = i - 1 ;j >= 0;j--)
            {
                if(times[i][0] >= times[j][1]) 
                {
                    dp[i] = max(dp[i], dp[j] + times[i][2]);
                    break;
                }
            }
        }
        int mx = INT_MIN;
        for(i = 0; i < dp.size(); i++)
            mx = max(mx, dp[i]);
        return mx;
    }
};