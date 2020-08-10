int Solution::mice(vector<int> &A, vector<int> &B) {
    int i, j, k;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = INT_MIN, n = A.size();
    for(i = 0;i < n; i++)
        ans = max(ans, abs(A[i] - B[i]));
    return ans;
}
