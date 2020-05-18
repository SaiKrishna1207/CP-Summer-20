class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int i, j;
        long long n = A.size();
        if(!n)
            return 0;
        long long sum = 0, msum = 0;
        long long mx = 0;
        for(i = 0;i < n; i++)
        {
            sum += A[i];
            msum += (A[i] * i);
        }
        mx = msum;
        for(i = n - 1; i >= 0; i--)
        {
            msum += sum - (n * A[i]);
            mx = max(mx, msum);
        }
        return mx;
    }
};