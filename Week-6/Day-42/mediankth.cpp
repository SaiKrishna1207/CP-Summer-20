int kth(int *arr1, int *arr2, int *end1, int *end2, int k) 
{ 
    if (arr1 == end1) 
        return arr2[k]; 
    if (arr2 == end2) 
        return arr1[k]; 
    int mid1 = (end1 - arr1) / 2; 
    int mid2 = (end2 - arr2) / 2; 
    if (mid1 + mid2 < k) 
    { 
        if (arr1[mid1] > arr2[mid2]) 
            return kth(arr1, arr2 + mid2 + 1, end1, end2, 
                k - mid2 - 1); 
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2, 
                k - mid1 - 1); 
    } 
    else
    { 
        if (arr1[mid1] > arr2[mid2]) 
            return kth(arr1, arr2, arr1 + mid1, end2, k); 
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k); 
    } 
} 
  

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m = A.size();
    int n = B.size();
    int a[m], b[n];
    for(int i = 0;i < m; i++)
        a[i] = A[i];
    for(int i = 0;i < n; i++)
        b[i] = B[i];
    int k = (m + n) / 2;
    double ans = 0;
    if((m + n)%2)
        ans = kth(a, b, a + m, b + n, k);
    else{
        double a1 = kth(a, b, a + m, b + n, k);
        double a2 = kth(a, b, a + m, b + n, k - 1);
        ans = (a1 + a2) / 2;
    }
    return ans;
}
