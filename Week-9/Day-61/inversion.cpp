class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int i, j, k;
        if(A.size() < 3)
            return true;
        int mx = A[0];
        for(i = 2;i < A.size(); i++){
            mx = max(mx, A[i - 2]);
            if(mx > A[i])
                return false;
        }
        return true;
    }
};