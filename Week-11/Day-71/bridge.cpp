
class Solution {
public:
    vector<vector<pair<int, int>>> mp;
    int k;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<int>> &A, int r, int c){
        A[r][c] = 0;
        mp[k].push_back({r, c});
        int i;
        for(i = 0;i < 4; i++){
            int x = r + dir[i][0];
            int y = c + dir[i][1];
            if(x < 0 || y < 0 || x >= A.size() || y >= A[r].size())
                continue;
            if(A[x][y] == 1)
                dfs(A, x, y);
        }
    }
    
    int distance(pair<int, int> a, pair<int, int> b){
        int ans = abs(a.first - b.first) + abs(a.second - b.second);
        return ans;
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int i, j;
        if(!A.size())
            return 0;
        int m = A.size();
        int n = A[0].size();
        mp.resize(2);
        k = 0;
        for(i = 0;i < m; i++){
            for(j = 0;j < n; j++){
                if(A[i][j] == 1){
                    dfs(A, i, j);
                    k++;
                }
            }
        }
        int ans = INT_MAX;
        for(i = 0;i < mp[0].size(); i++){
            for(j = 0;j < mp[1].size(); j++)
                ans = min(ans, distance(mp[0][i], mp[1][j]));
        }        
        return ans - 1;
    }
};