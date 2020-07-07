class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int i, j, k;
        vector<int> ans(nums.size());
        if(!nums.size())
            return ans;
        for(i = 0;i < nums.size(); i++){
            ans[i] = -1;
            k = 0;
            for(j = i + 1; k < nums.size() - 1; j++){
                if(j == nums.size())
                    j = 0;
                k++;
                if(nums[j] > nums[i]){
                    ans[i] = nums[j];
                    break;
                }
            }
        }
        return ans;
    }
};