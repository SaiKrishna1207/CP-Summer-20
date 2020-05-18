class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {

        vector<unsigned long long> ans(target + 1,0); //Unsigned coz signed doesnt fit lmao
        ans[0] = 1;
        int i;
        for(i = 1; i <= target; i++)
        {
            for(auto j: nums)
            {
                if(i - j >= 0)
                    ans[i] += ans[i - j];
            }
        }
        return ans[target];
    }
};