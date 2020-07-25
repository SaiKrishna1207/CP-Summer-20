class Solution {
public:
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
        int i, j, k;        
        if (target < matrix[0][0] || target > matrix[m - 1][ n - 1])
            return false;
        int row = 0;
        for (int i = 0; i < m; i++) {
            if (target > matrix[i][n -1]) 
               continue;
            if (target < matrix[i][0])
                break;
            row = i;
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[row][mid] == target)
                    return true;
                else if (matrix[row][mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};