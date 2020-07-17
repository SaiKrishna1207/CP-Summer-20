
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        if(!A.size())
            return 0;
        int i, j, k = 1, mx = 0;
        for(i = 0;i < A.size(); i++)
            mx = max(mx, A[i]);
        while (mx >= k)
            k <<= 1;
        k -= 1;
        unordered_set<int> ans;
        for (i = 0; i < A.size(); i++) {
            int val =  A[i];
            ans.insert(val);
            for (j = i - 1; j >= 0 && val != k; j--) {
                val |= A[j];
                ans.insert(val);
            }
        }
        
        return ans.size();
    }
};