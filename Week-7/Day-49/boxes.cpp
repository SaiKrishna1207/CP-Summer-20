class Solution {
public:
    
    int dfs(vector<vector<vector<int>>>& dp, vector<int>& boxes, int left, int right, int count){
        if(left > right) 
            return 0;
        if(dp[left][right][count]!=-1) 
            return dp[left][right][count];
        int i, j;
        int ans = (count + 1) * (count + 1) + dfs(dp, boxes,left + 1, right, 0);  
        
        for(i = left + 1;i <= right; i++)
        {
            if(boxes[i] == boxes[left])
                ans = max(ans,dfs(dp, boxes, left + 1,i - 1, 0) + dfs(dp, boxes, i, right, count + 1));  
        }
        dp[left][right][count] = ans;
        return ans;
    }
    
    int removeBoxes(vector<int>& boxes) {
        if(!boxes.size())
            return 0;
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n, -1)));
        int ans = dfs(dp, boxes, 0, n - 1, 0);
        return ans;
    }
};