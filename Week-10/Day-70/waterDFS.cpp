vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(vector<vector<bool>>& v, int r, int c, vector<vector<int>> &A, vector<vector<short>> &count){
    int i;
    v[r][c] = true;
    count[r][c]++;
    for(i = 0;i < 4; i++){
        int x = r + dir[i][0];
        int y = c + dir[i][1];
        if(x >= A.size() || x < 0 || y >= A[r].size() || y < 0)
            continue;
        if(!v[x][y] && A[x][y] >= A[r][c])
            dfs(v, x, y, A, count);
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int i, j, k;
    int m = A.size();
    if(!m)
        return 0;
    int n = A[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<short>>count(m, vector<short> (n, 0));
    for(i = 0; i < m; i++){
        if(!visited[i][0])
            dfs(visited, i, 0, A, count);
    }
    
    for(i = 0;i < n; i++){
        if(!visited[0][i])
            dfs(visited, 0, i, A, count);
    }
    visited.assign(m, vector<bool>(n, false));
    for(i = m - 1; i >= 0; i--){
        if(!visited[i][n - 1])
            dfs(visited, i, n - 1, A, count);
    }
    
    for(i = n - 1;i >= 0; i--){
        if(!visited[m - 1][i])
            dfs(visited, m - 1, i, A, count);
    }
    int ans = 0;
    for(i = 0;i < m; i++){
        for(j = 0;j < n; j++){
            if(count[i][j] == 2)
                ans++;
        }
    }
    return ans;
}
