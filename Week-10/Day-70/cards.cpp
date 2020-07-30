class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int i, j;
        int n = arr.size();
        if(!n)
            return 0;
        int tot = 0;
        for(i = 0;i < n; i++)
            tot += arr[i];
        if(k == n)
            return tot;
        
        int size = n - k;
        int s = 0, e = 0, sum = 0, ans = 0;
        while(e < n){
            sum += arr[e++];
            if(e - s + 1 <= size)
                continue;
            ans = max(ans, tot - sum);
            sum -= arr[s++];
        }
        return ans;
    }
};
