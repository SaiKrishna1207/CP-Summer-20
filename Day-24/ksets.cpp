class Solution {
public:
    int sum = 0, sumPerSet;

    bool isPossible(vector<int> & nums, vector<bool> visited, int k, int sum)
    {
        if(k == 1)
            return true;
        if(sum == sumPerSet) 
            return isPossible(nums, visited, k - 1, 0);
        
        int i, j, last = -1;
        for(i = 0; i < nums.size(); i++) 
        {
            if(!visited[i] && last != nums[i] && sum + nums[i] <= sumPerSet) 
            {
                visited[i] = true;
                if(isPossible(nums, visited, k, sum + nums[i])) 
                    return true;
                visited[i] = false;
                last = i;
            }
        }
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
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        vector<bool> visited(n, false);
        if(nums[0] > sumPerSet)
            return false;
        return isPossible(nums, visited, k, 0);
    }
};