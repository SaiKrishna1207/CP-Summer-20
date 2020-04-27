class Solution {
public:
    
    vector<vector<int>> ans;

    void findCombo(vector<int> cur, int rem, int k)
    {
        if(rem == 0 && cur.size() == k)
        {
            ans.push_back(cur);
            return;
        }
        else if (cur.size() > k)
            return;                        
        else
        {
            int i;
            if(cur.size() == 0)
                i = 1;
            else
                i = cur.back() + 1;
            while(i <= 9)
            {
                if (i <= rem)
                {
                    cur.push_back(i);
                    findCombo(cur, rem - i, k);
                    cur.pop_back();
                    i++;
                }
                else
                    return;
            }
        }        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        int i, j;
        if(n == 0 || n > 45)
            return ans;
        vector<int> cur;
        findCombo(cur, n, k);
        return ans;
    }
};