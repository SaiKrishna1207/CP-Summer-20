class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int i, max = nums[0], j = 0;
        vector<int> maxes;
        for(i = 0;i < nums.size(); i++)
        {
            if(i < k && nums[i] > max)
                max = nums[i];
            else if(i >= k)
            {
                maxes.push_back(max);
                j++;
                vector<int>::iterator it = max_element(nums.begin() + j, nums.begin() + i + 1);
                max = *it;
            }
            
        }
        maxes.push_back(max);
        return maxes;
    }
};