class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int i, j, k = 0;
        int n = nums.size();
        if(n < 2)
            return n;
        int prev = nums[1] - nums[0];
        int cur, ans = 2;
        if(prev == 0)
            ans = 1;
        for(i = 2; i < n; i++){
            cur = nums[i] - nums[i - 1];
            if((prev >= 0 && cur < 0) || (prev <= 0 && cur > 0)){
                ans++;
                prev = cur;
            }
        }
        return ans;
    }
};