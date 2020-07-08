class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int i, j, k;
        if(!nums.size())
            return false;
        
        k = nums[0];
        for(i = 1; i < nums.size(); i++){
            k = __gcd(k, nums[i]);
            if(k == 1)
                return true;
        }
        if(k == 1)
            return true;
        return false;
    }
};