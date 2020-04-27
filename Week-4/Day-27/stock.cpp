class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int i, ans = 0, max = prices[0], min = prices[0], n = prices.size();
        for(i = 0;i < n; i++)
        {
            if(max - prices[i] > fee && max - min > fee)
            {
                ans += max - min - fee;
                max = prices[i];
                min = prices[i];
                continue;
            }
            if(min > prices[i])
            {
                min = prices[i];
                max = prices[i];
            }
            else 
            {
                if(max < prices[i])
                    max = prices[i];
            }
        }
        if(max - min - fee > 0)
            ans += max - min - fee;
        return ans;
            
    }
};