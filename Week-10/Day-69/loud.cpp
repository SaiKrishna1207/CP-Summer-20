class Solution {
public:

    vector<int> ans;
    vector<bool> visited;

    int dfs(vector<vector<int>>& mp, vector<int>& quiet, int p){
        if(visited[p])
            return ans[p];
        visited[p] = true;
        int mn = p, x;
        
        for(auto i : mp[p]){
            x = dfs(mp, quiet, i);
            if(quiet[mn] > quiet[x])
                mn = x;
        }
        ans[p] = mn;
        return mn;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int i, j, k;
        vector<vector<int>> mp(quiet.size());
        if(!quiet.size())
            return {};
        ans.resize(quiet.size(), -1);
        visited.resize(quiet.size());
        for(i = 0;i < richer.size(); i++){
            j = richer[i][0];
            k = richer[i][1];
            mp[k].push_back(j);
        }
        for(i = 0; i < quiet.size(); i++)
            dfs(mp, quiet, i);
        return ans;
    }
};