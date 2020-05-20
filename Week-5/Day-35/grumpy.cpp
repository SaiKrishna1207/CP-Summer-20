class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int i, j, k;
        int n = customers.size();
        int sm = 0;
        for(i = 0;i < n; i++)
        {
            if(grumpy[i] == 0)
                sm += customers[i];
        }
        if(X == 0)
            return sm;
        int cur = 0;
        int mx = 0;
        for(i = 0;i < n - X + 1; i++)
        {
            if(i == 0)
            {
                for(j = i; j < i + X; j++)
                {
                    if(grumpy[j] == 1)
                        cur += customers[j];
                }
            }
            else
            {
                if(grumpy[i + X - 1] == 1)
                    cur += customers[i + X - 1];
                if(grumpy[i - 1] == 1)
                    cur -= customers[i - 1];
            }
            mx = max(mx, cur);
        }
        return sm + mx;
    }
};