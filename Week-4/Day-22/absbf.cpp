class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int i, j, k;
        int n = arr1.size();
        int sum = 0, max = 0;
        for(i = 0;i < n - 1; i++)
        {
            for(j = i + 1; j < n; j++)
            {
                sum = abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j);
                if(sum > max)
                    max = sum;
            }
        }
        return max;
    }
};