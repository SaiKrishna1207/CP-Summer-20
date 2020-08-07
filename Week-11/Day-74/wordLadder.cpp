int distance(string A, string B){
    int i, c = 0;
    for(i = 0;i < A.length(); i++){
        if(A[i] != B[i])
            c++;
    }
    return c;
}
int ans_size = INT_MAX;
void dfs(vector<int> &ans, vector<int> &temp, vector<vector<int>> &adj, vector<bool> &visited, int s, int d){
    if(s == d){
        if((int)temp.size() < ans_size){
            ans = temp;
            ans_size = ans.size();
        }
        return;
    }
    temp.push_back(s);
    visited[s] = true;
    for(auto j : adj[s]){
        if(!visited[j])
            dfs(ans, temp, adj, visited, j, d);
    }
    temp.pop_back();
    visited[s] = false;
}

int Solution::solve(string A, string B, vector<string> &dict) 
{
    int i, j, k, n;
    dict.push_back(B);
    dict.insert(dict.begin(), A);
    n = dict.size();
    vector<vector<int>> adj(n);
    ans_size = INT_MAX;
    for(i = 0;i < n; i++){
        for(j = i + 1;j < n; j++){
            if(distance(dict[i], dict[j]) == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<bool> visited(n, 0);
    vector<int> ans, temp;
    dfs(ans, temp, adj, visited, 0, n - 1);
    return (int)ans.size() + 1;
}
