class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i, j, k;
        if(nums.size() < 3)
            return false;
        int n = nums.size();
        int f = INT_MAX, s = INT_MAX, t = INT_MAX;
        for(i = 0;i < n; i++){
            if(nums[i] < f)
                f = nums[i];
            else if(nums[i] > f && nums[i] < s)
                s = nums[i];
            else if(nums[i] > s)
                return true;
        }
        return false;
    }
};