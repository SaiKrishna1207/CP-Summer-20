int Solution::cntBits(vector<int> &A) {
    int i, j;
    long sum = 0, x, y;
    for(i = 0;i < 32; i++)
    {
        x = 0;
        y = 0;
        for(j = 0; j < A.size(); j++){
            if(A[j]&(1<<i))
                x++;
            else
                y++;
        }
        sum += (2 * x * y);
        sum %= 1000000007;
    }
    return sum%1000000007;
}
