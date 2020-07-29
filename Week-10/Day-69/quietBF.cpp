class Solution {
public:
    int q = INT_MAX;
    int person = -1;
    
    void dfs(vector<vector<int>>& mp, vector<int>& quiet, int p){
        if(quiet[p] < q){
            q = quiet[p];
            person = p;
        }
        
        for(auto i : mp[p])
            dfs(mp, quiet, i);
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int i, j, k;
        vector<vector<int>> mp(quiet.size());
        if(!quiet.size())
            return {};
        vector<int> ans(quiet.size());
        for(i = 0;i < richer.size(); i++){
            j = richer[i][0];
            k = richer[i][1];
            mp[k].push_back(j);
        }
        for(i = 0; i < quiet.size(); i++){
            q = INT_MAX;
            person = i;
            dfs(mp, quiet, i);
            ans[i] = person;
        }
        return ans;
    }
};