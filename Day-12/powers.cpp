class Solution {
public:
    int getKth(int lo, int hi, int k) 
    {
        vector<pair<int, int>> powers;
        int i;    
        for(i = lo;i <= hi; i++)
        {
            int j = i;
            int c = 0;
            while(j != 1)
            {
                if(j%2 == 0)
                    j /= 2;
                else
                    j = (3 * j) + 1;
                c++;
            }
            powers.push_back(make_pair(c, i));
        }
        sort(powers.begin(), powers.end());
        return powers[k-1].second;
    }
};