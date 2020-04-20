class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(), pairs.end());
        int i, j, k;
        int n = pairs.size();
        int arr[n];
        for(i = 0;i < n; i++)
        {
            cout << pairs[i][0] << " " << pairs[i][1] << endl;
            arr[i] = 1;
        }
        for(i = 1;i < n; i++)
        {
            for(j = i - 1; j >= 0; j--)
            {
                if(pairs[j][1] < pairs[i][0] && arr[j] >= arr[i])
                    arr[i] = arr[j] + 1;
            }
        }
        int max = arr[0];
        for(i = 0;i < n; i++)
        {
            if(arr[i] > max)
                max = arr[i];
        }
        return max;
    }
};