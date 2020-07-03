class Solution {
public:
    
    int findPaths(int m, int n, int N, int r, int c) {
        int i, j;
        long long k = 0;
        if(!N)
            return 0;
        int M = 1000000007;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        grid[r][c] = 1;
        while(N--){
            vector<vector<int>> d(m, vector<int>(n, 0));
            for(i = 0; i < m; i++){
                for(j = 0;j < n; j++){
                    if(i == 0)
                        k = k + grid[i][j];
                    if(i == m - 1)
                        k = k + grid[i][j];
                    if(j == 0)
                        k = k + grid[i][j];
                    if(j == n - 1)
                        k = k + grid[i][j];
                    
                    d[i][j] = (((i > 0 ? grid[i - 1][j] : 0) + (i < m - 1 ? grid[i + 1][j] : 0)) % M + ((j > 0 ? grid[i][j - 1] : 0) + (j < n - 1 ? grid[i][j + 1] : 0)) % M) % M;
                }
            }
            grid = d;
        }
        return k%M;
    }
};