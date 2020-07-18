vector<vector<int>> ans;
void dfs(vector<int> &a, int n, int i, vector<int> temp){
    if (i == n){
        ans.push_back(temp);
        return;
    }
    int j;
    for(j = 0;j < n; j++)
    {
        if(temp[j] == -1)
        {
            temp[j] = a[i];
            dfs(a, n, i + 1, temp);
            temp[j] = -1;
        }
    }
}

vector<vector<int>> Solution::permute(vector<int> &A) {
    ans.resize(0);
    int n = A.size();
    vector<int> temp(n, -1);
    dfs(A, n, 0, temp);
    return ans;
}