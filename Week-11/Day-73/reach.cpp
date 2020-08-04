class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int i, j, k = 0;
        if(!grid.size())
            return 0;
        int mx = 0, n = grid.size();
        queue<pair<pair<int, int>, int>> q;
        for(i = 0;i < n; i++){
            for(j = 0;j < n; j++){
                if(grid[i][j] == 1)
                    q.push({{i, j}, 0});
                else
                    k++;
            }
        }
        if(k == 0 || k == (n * n))
            return -1;
        
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int ans = INT_MIN;
        while(!q.empty()){
            auto a = q.front();
            int r = a.first.first;
            int c = a.first.second;
            int level = a.second;
            q.pop();
            if(visited[r][c])
                continue;
            visited[r][c] = true;
            ans = max(ans, level);
            for(i = 0;i < 4; i++){
                int x = r + dir[i][0];
                int y = c + dir[i][1];
                if(x >= n || y >= n || x < 0 || y < 0)
                    continue;
                if(!visited[x][y] && grid[x][y] == 0)
                    q.push({{x, y}, level + 1});
            }
        }
        return ans;
    }
};