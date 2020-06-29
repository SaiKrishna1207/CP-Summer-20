class Solution {
public:
    int isPossible(vector<int> b, int d, int k){
        int i, j = 0;
        int count = 0;
        
        for(i = 0;i < b.size(); i++){
            if(b[i] <= d){
                j++;
                if(j == k){
                    count++;
                    j = 0;
                }
            }
            else
                j = 0;
        }
        return count;
    }
    
    int minDays(vector<int>& b, int m, int k) {
        int i;
        if(!b.size())
            return -1;
        if((m * k) > b.size())
            return -1;
        int mn = b[0], mx = b[0];
        for(i = 1;i < b.size(); i++){
            mn = min(mn, b[i]);
            mx = max(mx, b[i]);
        }
        int l = mn, h = mx, ans = -1;
        while(l <= h)
        {
            int mid = l + ((h - l) / 2);
            if(isPossible(b, mid, k) >= m)
            {
                ans = mid;
                h = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};