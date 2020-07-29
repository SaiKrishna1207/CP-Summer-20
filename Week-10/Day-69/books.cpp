class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int i, j, k = 0;
        int n = books.size();
        if(!n || !shelf_width)
            return 0;
        vector<int> dp(n + 1, 0);
        for(i = 1; i <= n; i++){
            int width = books[i - 1][0];
            int height = books[i - 1][1];
            dp[i] = dp[i - 1] + height;
            for(j = i - 1; j >= 1 && width + books[j - 1][0] <= shelf_width; j--){
                width += books[j - 1][0];
                height = max(height, books[j - 1][1]);
                dp[i] = min(dp[i], height + dp[j - 1]);
            }
        }       
        return dp[n];
    }
};