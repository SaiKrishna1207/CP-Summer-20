class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int i, j, k;
        int mx = 0;
        if(low > high)
            return {};
        vector<int> ans;
        for(i = 1; i <= 9; i++){
            int cur = i;
            if(cur >= low && cur <= high)
                ans.push_back(cur);
            for(j = i + 1; j <= 9; j++){
                cur = (cur * 10) + j;
                if(cur >= low && cur <= high)
                    ans.push_back(cur);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};