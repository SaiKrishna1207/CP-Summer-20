int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    if(A.size() != B.size())
        return 0;
    if(A.size() == 0)
        return 0;
    int i, j, ans = 0;
    int n = A.size();
    for(i = 0; i < n; i++){
        unordered_map<double, int> mp;
        int k = 0, v = 1, mx = 0;
        for(j = i + 1; j < n; j++){
            if(A[i] == A[j] && B[i] == B[j])
                k++;
            else if(A[i] == A[j])
                v++;
            else{
                double slope = ((double)(B[j] - B[i])) / ((double)(A[j] - A[i]));
                if(!mp[slope])
                    mp[slope] = 2;
                else
                    mp[slope]++;
            }
        }
        for(auto i : mp)
            mx = max(mx, i.second);
        mx = max(mx, v);
        mx += k;
        
        ans = max(ans, mx);
    }
    return ans;
}
