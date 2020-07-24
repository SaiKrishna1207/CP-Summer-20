class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j) {
        if (visited[i][j] > 0) 
            return visited[i][j];
        
        int l = check(matrix, i, j - 1) > matrix[i][j] ? dfs(matrix, visited, i, j - 1) : 0;
        int r = check(matrix, i, j + 1) > matrix[i][j] ? dfs(matrix, visited, i, j + 1) : 0;
        int u = check(matrix, i - 1, j) > matrix[i][j] ? dfs(matrix, visited, i - 1, j) : 0;
        int d = check(matrix, i + 1, j) > matrix[i][j] ? dfs(matrix, visited, i + 1, j) : 0;
        
        int mx = max({l, r, u, d});
        visited[i][j] = mx + 1;
        
        return visited[i][j];
    }
    
    int check(vector<vector<int>>& matrix, int i, int j) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) 
            return INT_MIN;
        return matrix[i][j];
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) 
            return 0;
        int i, j, k;
        vector<vector<int>> visited(matrix.size(), vector(matrix[0].size(), 0));

        int ans = 0;
        for (i = 0; i < visited.size(); i++) {
            for (j = 0; j < visited[i].size(); j++) {
                dfs(matrix, visited, i, j);
            }
        }
        
        for (i = 0; i < visited.size(); i++) {
            for (j = 0; j < visited[i].size(); j++) 
                ans = max(ans, visited[i][j]);
        }
        return ans;
    }
};