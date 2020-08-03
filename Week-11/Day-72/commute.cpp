bool sortcol(const vector<int> &A, const vector<int> &B){
    return A[2] < B[2];
}

int find(vector<int> &parent, int i){
    if(parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(vector<int> &parent, int x, int y){
    int x_parent = find(parent, x);
    int y_parent = find(parent, y);
    if(x_parent != y_parent)
        parent[x_parent] = y_parent;
}

int Solution::solve(int A, vector<vector<int>> &B) {
    int i = 0, j, k;
    if(!B.size() || A < 2)
        return 0;
    if(A == 2)
        return B[0][2];
    sort(B.begin(), B.end(), sortcol);
    k = A - 1;
    vector<int> parent(A + 1, -1);
    int ans = 0;
    while(i < B.size() && k){
        int x = B[i][0];
        int y = B[i][1];
        if(find(parent, x) == find(parent, y))
            continue;
        Union(parent, x, y);
        ans += B[i][2];
        k--;
        i++;
    }
    return ans;
}
