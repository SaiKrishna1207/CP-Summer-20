class Solution {
public:
    int integerBreak(int n) {
        int i, j, k;
        vector<int> ans(n + 1);
        ans[0] = 0;
        ans[1] = 1;
        for(i = 2; i <= n; i++)
        {
            for(j = i - 1; j >= 1; j--)
                ans[i] = max(ans[i], max(j * (i - j), j * ans[i - j]));
        }
        return ans[n];
    }
};