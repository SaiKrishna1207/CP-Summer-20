vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int i, j, k;
    if(A.size() != B.size())
        return {};
    if(!A.size())
        return {};
    vector<int> ans(A.size()), temp;
    vector<pair<int, int>> t(A.size());
    for(i = 0;i < A.size(); i++){
        t[i] = {A[i], B[i]};
        temp.push_back(i);
    }
    sort(t.begin(), t.end());
    for(i = 0; i < A.size(); i++){
        ans[temp[t[i].second]] = t[i].first;
        auto it = temp.begin();
        temp.erase(it + t[i].second);
    }
    return ans;
}
