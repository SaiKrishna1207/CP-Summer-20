class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int i, j;
        int n = arr.size();
        if(n < 2)
            return n;
        vector<int> count(n, 1);
        for(i = 1; i < n; i++)
        {
            for(j = i - 1; j >= 0; j--)
            {
                if(arr[i] - arr[j] == difference)
                    count[i] = max(count[i], count[j] + 1);
            }
        }
        int mx = count[0];
        for(i = 0;i < n; i++)
            mx = max(mx, count[i]);
        return mx;
    }
};