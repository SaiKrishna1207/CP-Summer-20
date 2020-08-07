vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int i, j, k;
    int m = A.size();
    if(!m)
        return {};
    int n = A[0].size();
    vector<vector<int>> ans;
    for(i = 0; i < n; i++){
        vector<int> temp;
        j = 0;
        k = i;
        while(k >= 0 && j < m){
            temp.push_back(A[j][k]);
            j++;
            k--;
        }
        ans.push_back(temp);
    }
    for(i = 1; i < m; i++){
        vector<int> temp;
        j = n - 1;
        k = i;
        while(k < m && j >= 0){
            temp.push_back(A[k][j]);
            k++;
            j--;
        }
        ans.push_back(temp);
    }
    return ans;
}
