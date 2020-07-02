int Solution::solve(vector<int> &A, int B) {
    int i, j = 0, k = 0, mx = 0;
    for(i = 0;i < A.size(); i++){
        if(A[i] == 0)
            j++;
        while(j > B){
            if(A[k] == 0)
                j--;
            k++;
        }
        mx = max(mx, i - k + 1);
    }
    return mx;
}
