class Solution {
public:
    int s = 0;
    
    void dfs(int cur, unordered_map<int, vector<int>> mp, int dist, vector<bool>& visited){
        s += dist;
        visited[cur] = true;
        for(auto i : mp[cur]){
            if(!visited[i])
                dfs(i, mp, dist + 1, visited);
        }
    }
    
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        if(!N)
            return {};
        if(N == 1)
            return {0};
        vector<int> ans(N);
        int i, j, k;
        unordered_map<int, vector<int>> mp;
        for(i = 0;i < edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        for(i = 0;i < N; i++){
            vector<bool> visited(N, false);
            s = 0;
            dfs(i, mp, 0, visited);
            ans[i] = s;
        }
        return ans;
    }
};