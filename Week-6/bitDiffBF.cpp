int findDiff(int k){
    int i, count = 0;
    for(i = 0; i < 32; i++){
        if((1<<i)&k)
            count++;
    }
    return count;
}

int Solution::cntBits(vector<int> &A) {
    int i, j, k;
    int sum = 0;
    for(i = 0;i < A.size() - 1; i++){
        for(j = i + 1; j < A.size(); j++){
            k = A[i] ^ A[j];
            sum += findDiff(k);
            sum %= 1000000007;
        }
    }
    return (sum * 2)%1000000007;
}