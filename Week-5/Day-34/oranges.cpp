class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int i, j, k;
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        for(i = 0;i < m; i++)
        {
            for(j = 0;j < n; j++)
            {
                if(grid[i][j] == 2)
                    q.push(make_pair(make_pair(i, j), 0));
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            pair<pair<int, int>, int> a = q.front();
            q.pop();
            int x = a.first.first;
            int y = a.first.second;
            int t = a.second;
            ans = max(ans, t);
            if(x + 1 < m && grid[x + 1][y] == 1)
            {
                grid[x + 1][y] = 2;
                q.push(make_pair(make_pair(x + 1, y), t + 1));
            }
            if(x - 1 >= 0 && grid[x - 1][y] == 1)
            {
                grid[x - 1][y] = 2;
                q.push(make_pair(make_pair(x - 1, y), t + 1));
            }
            if(y + 1 < n && grid[x][y + 1] == 1)
            {
                grid[x][y + 1] = 2;
                q.push(make_pair(make_pair(x, y + 1), t + 1));
            }
            if(y - 1 >= 0 && grid[x][y - 1] == 1)
            {
                grid[x][y - 1] = 2;
                q.push(make_pair(make_pair(x, y - 1), t + 1));
            }
        }
        for(i = 0;i < m; i++)
        {
            for(j = 0;j < n; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};