int findMax(vector<int> &dp){
    int i, j, k;
    int maxArea = 0, area = 0;
    stack<int> s;
    for(i = 0;i < dp.size();){
        if(s.empty() || dp[s.top()] <= dp[i])
            s.push(i++);
        else{
            int top = s.top();
            s.pop();
            if(s.empty())
                area = dp[top] * i;
            else
                area = dp[top] * (i - s.top() - 1);
            if(area > maxArea)
                maxArea = area;
        }
    }
    while(!s.empty()){
        int top = s.top();
        s.pop();
        if(s.empty())
            area = dp[top] * i;
        else
            area = dp[top] * (i - s.top() - 1);
        if(area > maxArea)
            maxArea = area;
    }
    return maxArea;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int i, j, k = 0;
    vector<int> dp(A[0].size(), 0);
    for(i = 0;i < A.size(); i++){
        for(j = 0;j < A[i].size(); j++){
            if(A[i][j] == 1)
                dp[j]++;
            else
                dp[j] = 0;
        }
        k = max(findMax(dp), k);
    }
    return k;
}
