int Solution::cnttrue(string A) {
    int i, j, k, l = A.length();
    if(l%2 == 0)
        return 0;
    if(l == 1) 
        return A[0] == 'T';
    vector<vector<int>> t(l, vector<int> (l, 0)), f(l, vector<int> (l, 0));
    t[l - 1][l - 1] = A[l - 1] == 'T';
    f[l - 1][l - 1] = A[l - 1] == 'F';
    int m = 1003;
    for(i = l - 3; i >= 0;i = i - 2)
    {
        for(j = i; j < l;j += 2)
        {
            if(j == i)
            {
                t[i][j] = A[i] == 'T';
                f[i][j] = A[i] == 'F';
                continue;
            }
            for(k = i;k <= j - 2;k += 2)
            {
                if(A[k + 1] == '&'){
                    t[i][j] += (t[i][k] * t[k + 2][j])%m;
                    f[i][j] += ((t[i][k] * f[k + 2][j])%m + (f[i][k] * t[k + 2][j])%m + (f[i][k] * f[k + 2][j])%m)%m;
                }
                else if(A[k+1]=='|'){
                    t[i][j] += ((t[i][k] * t[k + 2][j])%m + (t[i][k] * f[k + 2][j])%m + (f[i][k] * t[k + 2][j])%m)%m;
                    f[i][j] += (f[i][k] * f[k + 2][j])%m;
                }
                else {
                    t[i][j] += ((t[i][k] * f[k + 2][j])%m + (f[i][k] * t[k + 2][j])%m)%m;
                    f[i][j] += ((t[i][k] * t[k + 2][j])%m + (f[i][k] * f[k + 2][j])%m)%m;
                }
            }
            t[i][j] = t[i][j]%m;
            f[i][j] = f[i][j]%m;
        }
    }
    return t[0][l - 1];
}
