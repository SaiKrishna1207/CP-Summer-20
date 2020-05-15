class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int i, j;
        int n = arr.size();
        if(n < 2)
            return n;
        unordered_map<int, int> mp;
        int mx = 1;
        mp[arr[0]] = 1;
        for(i = 1; i < n; i++)
        {
            if(mp[arr[i] - difference])
            {
                mp[arr[i]] = mp[arr[i] - difference] + 1;
                mx = max(mx, mp[arr[i]]);
            }
            else
                mp[arr[i]] = 1;
        }
        return mx;
    }
};