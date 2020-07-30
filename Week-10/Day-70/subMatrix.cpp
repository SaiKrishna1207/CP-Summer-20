int countZeroes(vector<int> t, int n){
    unordered_map<int, int> mp;
   int count = 0, i, sum = 0;
   for(i = 0; i < n; i++)
   {
      sum += t[i];
      if(sum==0)
          count++;
      if(mp.find(sum) != mp.end())
          count += mp[sum];
      mp[sum]++;
  }
  return count;
}

int Solution::solve(vector<vector<int>> &A) {
    int i, j, k;
    int m = A.size();
    if(!m)
        return 0;
    int n = A[0].size();
    int ans = 0;
    for(i = 0;i < n; i++){
        vector<int> t(m, 0);
        for(j = i; j < n; j++){
            for(k = 0;k < m; k++)
                t[k] += A[k][j];
            ans += countZeroes(t, m);
        }
    }
    return ans;
}
