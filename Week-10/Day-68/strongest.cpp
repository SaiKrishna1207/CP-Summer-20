class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int i, j;
        if(!arr.size() || !k)
            return {};
        if(k == arr.size())
            return arr;
        if(k > arr.size())
            return {};
        sort(arr.begin(), arr.end());
        int n = arr.size();
        double median = arr[(n - 1) / 2];
        vector<int> ans;
        i = 0, j = n - 1;
        while(k--){
            double k1 = arr[i];
            double k2 = arr[j];
            if(abs(k1 - median) > abs(k2 - median))
                ans.push_back(arr[i++]);
            else
                ans.push_back(arr[j--]);
        }
        return ans;
    }
};