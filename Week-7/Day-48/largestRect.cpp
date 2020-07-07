    int Solution::largestRectangleArea(vector<int> &A) {
    int i = 0, j, k = 0;
    stack<int> s;
    while(i < A.size()){
        if(s.empty() || A[s.top()] <= A[i])
            s.push(i++);
        else{
            j = s.top();
            s.pop();
            int a;
            if(s.empty())
                a = A[j] * i;
            else
                a = A[j] * (i - s.top() - 1);
            k = max(k, a);
        }
    }
    while(!s.empty()){
        j = s.top();
        s.pop();
        int a;
        if(s.empty())
            a = A[j] * i;
        else
            a = A[j] * (i - s.top() - 1);
        k = max(k, a);
    }
    return k;
}
