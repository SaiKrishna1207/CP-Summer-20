vector<vector<int> > Solution::prettyPrint(int A) {
    int i, j, k;
    if(A == 0)
        return {};
    int n = (2 * A) - 1;
    vector<vector<int>> ans (n, vector<int> (n));
    int l = 0, r = n - 1, t = 0, b = n - 1;
    while(t <= b && l <= r){
        for(i = l; i <= r; i++)
            ans[t][i] = A;
        t++;
        for(i = t; i <= b; i++)
            ans[i][r] = A;
        r--;
        for(i = r; i >= l; i--)
            ans[b][i] = A;
        b--;
        for(i = b; i >= t; i--)
            ans[i][l] = A;
        l++;
        A--;
    }
    return ans;
}
