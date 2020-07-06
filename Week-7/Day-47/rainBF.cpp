int Solution::trap(const vector<int> &A) {
    int i, j, k = 0;
    for(i = 1; i < A.size() - 1; i++){
        int l = A[i];
        for(j = i - 1; j >= 0; j--)
            l = max(l, A[j]);
        int r = A[i];
        for(j = i + 1; j < A.size(); j++)
            r = max(r, A[j]);
        k += min(l, r) - A[i];
    }
    return k;
}
