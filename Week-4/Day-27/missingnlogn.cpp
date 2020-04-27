class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int i, count = 1, n = nums.size();
        if(n == 0)
            return 1;
        sort(nums.begin(), nums.end());
        for(i = 0;i < n; i++)
        {
            if(nums[i] <= 0)
                continue;
            if(nums[i] == count)
                count++;
        }
        return count;
    }
};