class Solution {
public:
    int ans = 1;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<bool>>& visited, int cur){
        int i, x, y, k = 0;
        visited[r][c] = true;

        for(i = 0;i < 4; i++){
            x = r + dir[i][0];
            y = c + dir[i][1];
            if(x < 0 || y < 0 || x >= matrix.size() || y >= matrix[r].size())
                continue;
            if(matrix[x][y] > matrix[r][c] && !visited[x][y]){
                k++;
                dfs(matrix, x, y, visited, cur + 1);
            }
        }   
        if(k == 0)
            ans = max(ans, cur);
        visited[r][c] = false;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int i, j, k;
        if(!matrix.size())
            return 0;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        for(i = 0;i < matrix.size(); i++){
            for(j = 0; j < matrix[i].size(); j++)
                dfs(matrix, i, j, visited, 1);
        }
        return ans;
    }
};