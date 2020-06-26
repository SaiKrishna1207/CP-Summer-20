vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int i, j, l = 0, h = A.size() - 1;
    int a = INT_MAX, b = INT_MIN;
    while(l <= h){
        int m = l + ((h - l) / 2);
        if(A[m] > B)
            h = m - 1;
        else if(A[m] < B)
            l = m + 1;
        else if(A[m] == B && (A[m + 1] != B || m == A.size() - 1))
        {
            b = m;
            break;
        }
        else if(A[m] == B && A[m + 1] == B)
            l = m + 1;
    }
    if(b == INT_MIN)
        b = -1;
    l = 0, h = A.size() - 1;
    while(l <= h){
        int m = l + ((h - l) / 2);
        if(A[m] > B)
            h = m - 1;
        else if(A[m] < B)
            l = m + 1;
        else if(A[m] == B && (A[m - 1] != B || m == 0))
        {
            a = m;
            break;
        }
        else if(A[m] == B && A[m - 1] == B)
            h = m - 1;
    }
    
    if(a == INT_MAX)
        a = -1;
    return {a, b};
}