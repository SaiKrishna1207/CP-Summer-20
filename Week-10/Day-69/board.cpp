int Solution::solve(int A) {
    int i, j;
    if(!A)
        return 0;
    long long color_3 = 24;
    long long color_2 = 12;
    long long ans = 36;
    for(i = 1;i < A; i++){
        long long k = color_3;
        color_3 = ((11 * color_3) + (10 * color_2))%1000000007;
        color_2 = ((7 * color_2) + (5 * k))%1000000007;
    }
    ans = (color_3 + color_2)%1000000007;
    return ans;
}
