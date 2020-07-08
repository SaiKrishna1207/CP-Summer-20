int Solution::solve(vector<int> &A, int B) {
    int i, j, k;
    unordered_map<int, int> mp;
    int ans = 0;
    vector<int> pre(A.size(), 0);
    pre[0] = A[0];
    for(i = 1;i < A.size(); i++)
        pre[i] = pre[i - 1] ^ A[i];
    
    for(i = 0;i < A.size(); i++){
        if(pre[i] == B)
            ans++;
        if(mp[pre[i] ^ B])
            ans += mp[pre[i] ^ B];
        mp[pre[i]]++;
    }
    return ans;
}
