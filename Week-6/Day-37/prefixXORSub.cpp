class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int i, j, k, ans = 0;
        if(arr.size() < 2)
            return 0;
        vector<int> dp;
        dp.push_back(0);
        for(i = 0; i < arr.size(); i++)
            dp.push_back(dp[i] ^ arr[i]);
        
        for(i = 0;i < arr.size() - 1; i++){
            for(j = i + 1; j < arr.size(); j++){
                if(dp[i] == dp[j + 1])
                    ans += (j - i);
            }
        }
        return ans;
    }
};