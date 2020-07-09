int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int i, j, k = 0, isPoss = 0;
    for(i = 0;i < A.size(); i++)
        isPoss += (A[i] - B[i]);
    if(isPoss < 0)
        return -1;
        
    int ans = 0;
    for(i = 0; i < A.size(); i++){
        k += A[i] - B[i];
        if(k < 0){
            ans = i + 1;
            k = 0;
        }
    }
    return ans;
}
