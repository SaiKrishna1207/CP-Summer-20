class Solution {
public:
    int characterReplacement(string s, int k) {
        int i, j;
        if(!s.length())
            return 0;
        int n = s.length();
        vector<int> count(26, 0);
        i = 0, j = 0;
        int mx = 0;
        int ans = 0;
        while(j < n){
            count[s[j] - 'A']++;
            mx = max(mx, count[s[j] - 'A']);
            if((j - i + 1) - mx <= k)
                ans = max(ans, (j - i + 1));
            else{
                count[s[i] - 'A']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};