double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int i, j;
    int m = A.size();
    int n = B.size();
    if(m > n)
        return findMedianSortedArrays(B, A);
    int l = 0,h = m;
    while(l <= h){
        int partx = l + (h - l) / 2;
        int party = (m + n + 1) / 2 - partx;
        int maxlx = (partx == 0) ? INT_MIN : A[partx - 1];
        int minrx = (partx == m) ? INT_MAX : A[partx];
        int maxly = (party == 0) ? INT_MIN : B[party - 1];
        int minry = (party == n) ? INT_MAX : B[party];
        if(maxlx <= minry && maxly <= minrx){
            if((m + n)%2==0)
                return (double)(max(maxlx, maxly) + min(minrx, minry)) / 2;
            else
                return (double)(max(maxlx, maxly));
        }else if(maxlx > minry)
            h = partx - 1;
        else
            l = partx + 1;
    }
    return -1.0;
}