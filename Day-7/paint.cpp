bool isOk(int A, int B, vector<int>& C, long long int t)
{
    long long int t1 = t;
    int count = 1, i = 0, n = C.size();
    while(i < n)
    {
        if(count > A)
            return false;
        if(C[i] > t)
        {
            count++;
            t = t1;
        }
        else 
        {
            t -= C[i];
            i++;
        }
    }
    return true;
}


int Solution::paint(int A, int B, vector<int> &C) 
{
    int n = C.size();
    if(n < A)
    {
        int k = *(max_element(C.begin(), C.end()));
        k = k * B;
        return k;
    }
    int i;
    long long int sum = 0;
    for(i = 0;i < n; i++)
        sum = sum + C[i];
    long long int low = 0, high = sum * B;
    long long int ans = high%10000003;
    long long int mid;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(isOk(A, B, C, mid/B))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans%10000003;
    