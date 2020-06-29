vector<int> Solution::dNums(vector<int> &A, int B) {
    int i, j, n = A.size();
    vector<int> ans;
    unordered_map<int, int> mp;
    if(B == 1)
    {
        vector<int> kk(n, 1);
        return kk;
    }
    for(i = 0;i < B; i++)
        mp[A[i]]++;
    j = 0;
    for(i = B; i <= n; i++){
        ans.push_back(mp.size());
        if (mp[A[j]] == 1)
            mp.erase(A[j]);
        else
            mp[A[j]]--;
        mp[A[i]]++;
        j++;
    }
    return ans;
}
