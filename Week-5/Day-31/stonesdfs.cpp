class Solution {
public:
    
    int mn = INT_MAX;
    void dfs(vector<int> stones, int cur, int i)
    {
        if(i == stones.size())
        {
            mn = min(mn, abs(cur));
            return;
        }
        dfs(stones, cur + stones[i], i + 1);
        dfs(stones, cur - stones[i], i + 1);
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() == 0)
            return 0;
        dfs(stones, 0, 0);
        return mn;
    }
};