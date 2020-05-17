class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i, j, count = 0;
        int n = A.size();  
        if(!n)
            return 0;
        for(i = 0;i < n - 2; i++)
        {
            int dif = A[i + 1] - A[i];
            for(j = i + 2; j < n; j++)
            {
                if(A[j] - A[j - 1] == dif)
                    count++;
                else 
                    break;
            }
        }
        return count;
    }
};