bool sortcol(const vector<int> &A, const vector<int> &B){
    return A[2] < B[2];
}

int find(vector<int> &parent, int i){
    if(parent[i] == -1)
        return i;
    int k = find(parent, parent[i]);
    parent[i] = k;
    return k;
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
        int x = find(parent, B[i][0]);
        int y = find(parent, B[i][1]);
        if(x != y){
            ans += B[i][2];
            k--;
            parent[x] = y;
        }
        i++;
    }
    return ans;
}
