class Solution {
public:
    bool canFind(int target, int size, vector<int> &nums){
        int i = 0, j = 0, k = 0;
        while(j < nums.size()){
            k += nums[j++];
            if(j - i < size)
                continue;
            if(k >= target)
                return true;
            k -= nums[i++];
        }
        return false;
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {
        int i, j, k, ans = 0;
        if(!nums.size())
            return 0;
        int n = nums.size();
        int l = 1, h = n;
        while(l <= h){
            int m = l + ((h - l) / 2);
            if(canFind(s, m ,nums)){
                ans = m;
                h = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }
};