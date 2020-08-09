class Solution {
public:
    
    int minSubArrayLen(int s, vector<int>& nums) {
        int i, j, k = 0, ans = INT_MAX;
        if(!nums.size())
            return 0;
        int l = 0;
        int n = nums.size();
        for(i = 0;i < n; i++){
            k += nums[i];
            while(k >= s){
                ans = min(ans, i - l + 1);
                k -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};