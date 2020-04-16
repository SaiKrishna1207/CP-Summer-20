
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& A) 
    {
        int n = A.size();
        vector<vector<int>> sets;
        int i, j;
        for(i = 0; i < (1<<n); i++)
        {
            vector<int> s;
            for(j = 0; j < n; j++)
            {
                if(i & (1<<j))
                    s.push_back(A[j]);
            }
            sets.push_back(s);
        }
    
        return sets;
    }
};