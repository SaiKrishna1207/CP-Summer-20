int bfs(vector<vector<int>> &A, int r, int c){
    vector<vector<int>> dir = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    queue<pair<int, int>> q;
    int count = 0;
    q.push({r, c});
    A[r][c] = 0;
    while(!q.empty()){
        auto k = q.front();
        q.pop();
        int x = k.first, y = k.second;
        count++;
        for(int i = 0;i < 8; i++){
            int row = x + dir[i][0];
            int col = y + dir[i][1];
            if(row < 0 || col < 0 || row >= A.size() || col >= A[x].size())
                continue;
            if(A[row][col] == 1){
                q.push({row, col});
                A[row][col] = 0;
            }
        }
    }
    return count;
}

int Solution::solve(vector<vector<int>> &A) {
    int i, j, k;
    if(!A.size())
        return 0;
    int ans = 0;
    int m = A.size(), n = A[0].size();
    for(i = 0;i < m; i++){
        for(j = 0;j < n; j++){
            if(A[i][j] == 1)
                ans = max(ans, bfs(A, i, j));
        }
    }
    return ans;
}
