class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        if(arr.size() < 2)
            return 0;
        int i, j, k;
        int ans = 0;
        while(arr.size() > 2){
            j = INT_MAX;
            for(i = 0;i < arr.size(); i++){
                if(j > arr[i]){
                    j = arr[i];
                    k = i;
                }
            }
            int x, y;
            if(k == 0)
                x = INT_MAX;
            else
                x = arr[k] * arr[k - 1];
            
            if(k > arr.size() - 2)
                y = INT_MAX;
            else
                y = arr[k] * arr[k + 1];
                
            int mn = min(x, y);
            ans += mn;
            arr.erase(arr.begin() + k);
        }
        ans += arr[0] * arr[1];
        return ans;
    }
};