class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        vector<int> numbers;
        int i, j;
        for(i = 0;i < matrix.size(); i++)
        {
            for(j = 0;j < matrix[i].size(); j++)
                numbers.push_back(matrix[i][j]);
        }
        sort(numbers.begin(), numbers.end());
        return numbers[k-1];
    }
};