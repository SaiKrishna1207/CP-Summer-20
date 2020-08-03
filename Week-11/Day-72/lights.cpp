int Solution::solve(vector<int> &A, int B) {
    int i = 0, j, k;
    if(!A.size())
        return 0;
    int ans = 0;
    while(i < A.size()){
        j = i + B - 1;
        while(A[j] != 1 && j >= 0 && j >= (i - B + 1))
            j--;
        if(j >= 0 && j != (i - B) && A[j]==1){
            ans++;
            i = j + B;
        }
        else
            return -1;
    }
    return ans;
}
