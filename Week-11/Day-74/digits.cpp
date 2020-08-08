class Solution {
public:
    int findIntegers(int num) {
        if (num <= 2) 
            return num + 1;
        int i, j, k;
        vector<int> dp(32, 0); 
        dp[0] = 1;
        dp[1] = 2;
        int base = 2; 
        k = 1;
        while (base * 2 <= num + 1) {
            k++;
            dp[k] = dp[k - 1] + dp[k - 2];
            base <<= 1;
        }
        num -= base;
        num = min(num, base/2 - 1);
        return dp[k] + findIntegers(num);
    }
};