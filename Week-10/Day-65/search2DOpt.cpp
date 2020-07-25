class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {        
        if (!matrix.size())
            return false;
        int n = matrix[0].size();
        int m = matrix.size();         
        int i = 0, j = n - 1, k;      
        while(i < m && j >= 0){         
            if (matrix[i][j] == target) 
               return true;
            else if (matrix[i][j] > target) 
                j--;                        
            else 
                i++;
        }            
        return false;
    }
};