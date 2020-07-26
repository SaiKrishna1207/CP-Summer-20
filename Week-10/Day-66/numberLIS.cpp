class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int i, j, k;
        int n = nums.size();
        if(n < 2)
            return n;
        vector<int> counts(n, 1);
        vector<int> t(n, 1);
        
        for(i = 1; i < n; i++){
            for(j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(t[i] <= t[j]){
                        t[i] = t[j] + 1;
                        counts[i] = counts[j];
                    }
                    else if(t[i] == t[j] + 1)
                        counts[i] += counts[j];
                }
            }
        }
        int mx = 0, ans = 0;
        for(auto i : t)
            mx = max(mx, i);
        
        for(i = 0;i < n; i++){
            if(t[i] == mx)
                ans += counts[i];
        }
        return ans;
    }
};