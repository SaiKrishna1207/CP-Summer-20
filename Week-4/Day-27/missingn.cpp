class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int i, count, n = nums.size();
        if(n == 0)
            return 1;
        if(n == 1)
        {
            if(nums[0] == 1)
                return 2;
            else 
                return 1;
        }
        for(i = 0;i < n; i++)
        {
            if(nums[i] <= 0)
                nums[i] = INT_MAX;
        }
        for(i = 0;i < n; i++)
        {
            if(abs(nums[i]) <= n)
                nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);              //Using the array itself as a hashmap
        }
        count = n + 1;
        for(i = 0;i < n; i++)
        {
            if(nums[i] > 0)
            {
                count = i + 1;
                break;
            }
        }
        return count;
    }
};