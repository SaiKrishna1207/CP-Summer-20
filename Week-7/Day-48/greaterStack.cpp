class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int i, j, k;
        vector<int> ans(nums.size());
        if(!nums.size())
            return ans;
        stack<int> s;
        for(i = nums.size() - 1; i >= 0; i--){
            while(!s.empty() && nums[s.top()] <= nums[i])
                s.pop();
            if(s.empty())
                ans[i] = -1;
            else
                ans[i] = nums[s.top()];
            s.push(i);
        }
        for(i = nums.size() - 1; i >= 0; i--){
            while(!s.empty() && nums[s.top()] <= nums[i])
                s.pop();
            if(s.empty())
                ans[i] = -1;
            else
                ans[i] = nums[s.top()];
            s.push(i);
        }
        return ans;
    }
};