class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int i, j, k;
        int n = wordDict.size();
        if(!n)
            return false;
        int l = s.length();
        vector<bool> dp(l);
        for(i = 0;i < l; i++)
        {
            for(j = 0; j < n; j++)
            {
                int k = wordDict[j].length();
                if(k - 1 > i)
                    continue;
                string t = s.substr(i - k + 1, k);
                if(i < k && t == wordDict[j])
                    dp[i] = true;
                else if(i >= k && t == wordDict[j] && dp[i - k])
                    dp[i] = true;
            }
        }
        if(dp[l - 1])
            return true;
        return false;
    }
};