class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int i, j, k = 0;
        int n = nums.size();
        if(!n)
            return 0;
        vector<int> inc(n, 1), dec(n, 1);
        int ans = 1;
        for(i = 1;i < n; i++){
            for(j = 0;j < i; j++){
                if(nums[i] > nums[j])
                    inc[i] = max(inc[i], dec[j] + 1);
                else if(nums[i] < nums[j])
                    dec[i] = max(dec[i], inc[j] + 1);
            }
            ans = max({ans, inc[i], dec[i]});
        }
        return ans;
    }
};