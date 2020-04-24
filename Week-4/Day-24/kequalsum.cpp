class Solution {
public:
    unordered_map<int, int> mp;
    int sum = 0, sumPerSet;

    bool isPossible(vector<int> & nums, int i, int k)
    {
        int j, flag = 0;
        if(i < nums.size())
        {
            for(j = 0;j < k;j++)
            {
                if(mp[j] + nums[i] <= sumPerSet)
                {
                    mp[j] += nums[i];
                    if(isPossible(nums, i + 1, k))
                        return true;
                    mp[j] -= nums[i];
                }
            }
        }
        if(i == nums.size())
        {
            flag = 1; 
            for(auto j : mp)
            {
                if(j.second != sumPerSet)
                    return false;
            }
        }
        if(flag)
            return true;
        return false;    
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int i, j;
        int n = nums.size();
        for(i = 0;i < n; i++)
            sum += nums[i];
        if(sum%k != 0)
            return false;
        sumPerSet = sum / k;
        for(i = 0;i < k; i++)
            mp[i] = 0;
        return isPossible(nums, 0, k);
    }
};