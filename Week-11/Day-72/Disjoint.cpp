bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
    return v1[1] < v2[1]; 
} 

int Solution::solve(vector<vector<int>> &A) {
    int i, j, k;
    if(!A.size())
        return 0;
    sort(A.begin(), A.end(), sortcol);
    vector<pair<int, int>> ans;
    for(i = 0;i < A.size(); i++){
        if(!ans.size())
            ans.push_back({A[i][0], A[i][1]});
        else{
            pair<int, int> a = ans.back();
            if(a.second < A[i][0])
                ans.push_back({A[i][0], A[i][1]});
        }
    }
    return ans.size();
}
