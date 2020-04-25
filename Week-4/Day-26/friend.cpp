class Solution {
public:
    
    int Find(int x, vector<int> & groups)
    {
        if(groups[x] == -1)
            return x;
        return Find(groups[x], groups);
    }
    
    void Union(int x, int y, vector<int> & groups)
    {
        int a, b;
        a = Find(x, groups);
        b = Find(y, groups);
        if(a != b)
            groups[b] = x;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> groups(n, -1);
        int i, j, k;
        for(i = 0;i < n; i++)
        {
            for(j = 0;j < n; j++)
            {
                if(M[i][j])
                    Union(i, j, groups);
            }
        }
        int count = 0;
        for(i = 0;i < n; i++)
        {
            if(groups[i] == -1)
                count++;
        }
        return count;
    }
};