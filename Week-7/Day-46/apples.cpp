class Solution {
public:
    unordered_map<int, vector<int>> mp;
    
    int dfs(int k, int i, vector<bool>& apple){
        int ans = 0, j;
        for(j = 0;j < mp[i].size(); j++){
            if(mp[i][j] == k)
                continue;
            ans += dfs(i, mp[i][j], apple);
        }
        if(apple[i] || ans){
            if(k != -1)
                ans += 2;
        }
        return ans;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        if(!edges.size())
            return 0;
        if(!n || !hasApple.size())
            return 0;
        int i;
        for(i = 0;i < edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(-1, 0, hasApple);
    }
};