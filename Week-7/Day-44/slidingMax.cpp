vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int i, j, k;
    if(!A.size())
        return {};
    int n = A.size();
    int mx = A[0];
    for(i = 1;i < n; i++)
        mx = max(mx, A[i]);
    if(B > n)
        return {mx};
    vector<int> ans;
    priority_queue<pair<int, int>> pq;
    for(i = 0;i < B; i++)
        pq.push({A[i], i});
    ans.push_back(pq.top().first);
    for(i = B; i < n; i++){
        pq.push({A[i], i});
        while(pq.top().second < i - B + 1)
            pq.pop();
        ans.push_back(pq.top().first);
    }
    return ans;
}   

