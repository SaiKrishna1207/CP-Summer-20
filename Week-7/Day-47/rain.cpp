int Solution::trap(const vector<int> &A) {
    int i, j, k = 0;
    vector<int> l(A.size());
    vector<int> r(A.size());
    int mx = INT_MIN;
    for(i = 0;i < A.size(); i++){
        mx = max(mx, A[i]);
        l[i] = mx;
    }
    mx = INT_MIN;
    for(i = A.size() - 1; i >= 0; i--){
        mx = max(mx, A[i]);
        r[i] = mx;
    }
    for(i = 0; i < A.size(); i++){
        k += min(l[i], r[i]) - A[i];
    }
    return k;
}
