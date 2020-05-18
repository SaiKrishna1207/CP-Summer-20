class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long i, j;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ind = n / 2;
        long long ans = 0;
        for(i = 0;i < n; i++)
            ans += abs(nums[ind] - nums[i]);
        return ans;
    }
};