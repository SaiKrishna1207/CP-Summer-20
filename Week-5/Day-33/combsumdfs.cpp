class Solution {
public:
    int c = 0;
    
    void dfs(vector<int> & nums, int cur, int t)
    {
        if(cur > t)
            return;
        if(cur == t)
        {
            c++;
            return;
        }
        for(int i = 0; i < nums.size(); i++)
            dfs(nums, cur + nums[i], t);
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int i, j, n = nums.size();
        for(i = 0;i < n; i++)
            dfs(nums, nums[i], target);
        return c;
    }
};