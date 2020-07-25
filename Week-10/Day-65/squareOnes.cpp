class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int i, j, k, m = matrix.size();
        if(!m)
            return 0;
        int n = matrix[0].size(), ans = 0;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(i > 0 && j > 0 && matrix[i][j] > 0)
                    matrix[i][j] = min({matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]}) + 1;
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};