class Solution {
public:
    
    
    int countServers(vector<vector<int>>& grid) 
    {
        int i, j, k, m = grid.size(), n = grid[0].size(), ans = 0, col;
        unordered_map<int, int> mp;
        for(i = 0; i < m; i++)
        {
            int rc = 0;
            for(j = 0;j < n; j++)
            {
                if(grid[i][j])
                {
                    rc++;
                    col = j;
                }
            }
            if(rc > 1)
                ans += rc;
            else if(rc == 1)
                mp[col]++;
        }
        for(auto i : mp)
        {
            if(i.second > 1)
                ans += i.second;
            else if(i.second == 1)
            {
                int c = 0;
                for(j = 0; j < m; j++)
                {
                    if(grid[j][i.first])
                        c++;
                }
                if(c > 1)
                    ans++;
            }
        }
        return ans;
    }
};