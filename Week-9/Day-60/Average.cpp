class Solution {
public:
    bool dfs(int i, int sumN, int N, vector<int>& A) {
        int n = A.size();
        if(N == 0) 
            return sumN == 0;
        if(A[i] > sumN / N) 
            return false;
        int j;
        for(j = i; j < n - N + 1; j++) {
            if(j > i && A[j] == A[j - 1])
                continue;
            if(dfs(j + 1, sumN - A[j], N - 1, A))
                return true;
        }
        return false;
    }
    bool splitArraySameAverage(vector<int>& A) {
        int i, j, k;
        int n = A.size(), sum = 0;
        for(i = 0;i < n; i++) 
            sum += A[i];
        
        sort(A.begin(), A.end());
        for(j = 1; j <= n/2; j++) {
            if((sum * j) % n)
                continue;
            if(dfs(0, (sum * j) / n, j, A)) 
                return true;
        }
        return false;
    }
};