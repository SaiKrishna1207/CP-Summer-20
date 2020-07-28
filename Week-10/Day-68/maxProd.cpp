int Solution::maxProduct(const vector<int> &A) {
    int i, j, k = 0;
    int n = A.size();
    if(!n)
        return 0;
    vector<int> t(n);
    t[0] = A[0];
    for(i = 1;i < n; i++)
    {
        if(A[i - 1] == 0)
        {
            t[i] = A[i];
            k = 1;
        }
        else
            t[i] = t[i - 1] * A[i];
    }
    int ans = INT_MIN;
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(i = 0;i < n;i++)
    {
        while(i < n && t[i] != 0)
        {
            mx = max(mx, t[i]);
            mn = min(mn, A[i]);
            i++;
        }
        if(t[i - 1] != mn)
            mx = max(mx, (t[i - 1] / mn));
        ans = max(ans, mx);
    }
    if(k == 1)
        ans = max(ans, 0);
    return ans;
}