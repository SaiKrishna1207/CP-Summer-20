class Solution {
public:
    
    bool dfs(vector<int> nums, int sum1, int sum2, int turn, int start, int end)
    {
        if(start > end)
        {
            if(sum1 >= sum2)
                return true;
            return false;
        }
        if(turn%2 == 0)
            return dfs(nums,sum1+nums[start],sum2,turn+1,start+1,end) || dfs(nums,sum1+nums[end],sum2,turn+1,start,end-1); 
        else
            return dfs(nums,sum1,sum2+nums[start],turn+1,start+1,end) && dfs(nums,sum1,sum2+nums[end],turn+1, start,end-1);
    }   
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        return dfs(nums, 0, 0, 0, 0, n - 1);
    }
};

