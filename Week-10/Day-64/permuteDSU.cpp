int find(int x, vector<int> &parent){
    if(parent[x] == -1) 
        return x;
    return parent[x] = find(parent[x], parent);
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();
    int i, j, k; 
    vector<int> parent(n + 1, -1);
    int s, d;
    for(i = 0; i < C.size(); i++){
        s = A[C[i][0] - 1];
        d = A[C[i][1] - 1];
        j = find(s, parent);
        k = find(d, parent);
        if(j != k) 
            parent[k] = j;
    }
    
    for(i = 0; i < n; i++){
        if(A[i] != B[i]){
            j = find(A[i], parent);
            k = find(B[i], parent);
            if(j != k)
                return 0;
        }
    }
    return 1;
}