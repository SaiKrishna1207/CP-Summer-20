vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(vector<vector<bool>>& v, int r, int c, vector<vector<int>> &A){
    queue<pair<int, int>> q;
    int i, j;
    q.push({r, c});
    while(!q.empty()){
        auto k = q.front();
        q.pop();
        int r = k.first, c = k.second;
        v[r][c] = true;
        for(i = 0;i < 4; i++){
            int x = r + dir[i][0];
            int y = c + dir[i][1];
            if(x >= A.size() || x < 0 || y >= A[r].size() || y < 0)
                continue;
            if(!v[x][y] && A[x][y] >= A[r][c])
                q.push({x, y});
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int i, j, k;
    int m = A.size();
    if(!m)
        return 0;
    int n = A[0].size();
    vector<vector<bool>> visited1(m, vector<bool>(n, false)), visited2(m, vector<bool>(n, false));
    for(i = 0; i < m; i++){
        if(!visited1[i][0])
            bfs(visited1, i, 0, A);
    }
    
    for(i = 0;i < n; i++){
        if(!visited1[0][i])
            bfs(visited1, 0, i, A);
    }
    
    for(i = m - 1; i >= 0; i--){
        if(!visited2[i][n - 1])
            bfs(visited2, i, n - 1, A);
    }
    
    for(i = n - 1;i >= 0; i--){
        if(!visited2[m - 1][i])
            bfs(visited2, m - 1, i, A);
    }
    int ans = 0;
    for(i = 0;i < m; i++){
        for(j = 0;j < n; j++){
            if(visited1[i][j] && visited2[i][j])
                ans++;
        }
    }
    return ans;
}
