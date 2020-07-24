void dfs(vector<int> &temp, vector<bool> &visited, unordered_map<int, vector<int>> mp, int x){
    visited[x] = true;
    temp.push_back(x);
    for(auto i : mp[x]){
        if(!visited[i])
            dfs(temp, visited, mp, i);
    }
}

bool compute(vector<int> A, vector<int> B, vector<int> temp){
    set<int> a_comp, b_comp;
    int i;
    for(i = 0;i < temp.size(); i++){
        a_comp.insert(A[temp[i]]);
        b_comp.insert(B[temp[i]]);
    }
    if(a_comp == b_comp)
        return true;
    return false;
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int i, j, k;
    if(!C.size() && A == B)
        return 1;
    unordered_map<int, vector<int>> mp;
    for(i = 0;i < C.size(); i++){
        j = C[i][0];
        k = C[i][1];
        mp[j - 1].push_back(k - 1);
        mp[k - 1].push_back(j - 1);
    }
    vector<bool> visited(A.size(), false);
    for(i = 0;i < A.size(); i++){
        if(!visited[i]){
            vector<int> temp;
            dfs(temp, visited, mp, i);
            if(!compute(A, B, temp))
                return 0;
        }
    }
    return 1;
}
