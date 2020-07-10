class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        int i, j, k;
        vector<vector<int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        vector<vector<double>> dp(N, vector<double>(N, 1.0)), prev;
        
        for(int steps = 1; steps <= K; steps++){
            prev = dp;
            for(i = 0; i < N; i++){
                for(j = 0; j < N; j++){
                    double prob = 0;
                    for(k = 0;k < 8; k++){
                        int row = i + directions[k][0];
                        int col = j + directions[k][1];
                        if(row < 0 || col < 0 || row >= N || col >= N)
                            continue;
                        prob += prev[row][col] / 8;
                    }
                    dp[i][j] = prob;
                }
            }
        }
        return dp[r][c];
    }
};