class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, k;
        int m = matrix.size();
        if(!m)
            return;
        int n = matrix[0].size();
        for(i = 0;i < m; i++){
            for(j = i + 1; j < n; j++){
                k = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = k;
            }
        }
        for(i = 0;i < m; i++){
            for(j = 0;j < n / 2; j++){
                k = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = k;
            }
        }
        return;
    }
};