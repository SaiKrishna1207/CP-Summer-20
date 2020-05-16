class Solution {
public:
    
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size() == 0)
            return 0;
        set<int> sums;
        sums.insert(0);
        int i;
        for(i = 0;i < stones.size(); i++)
        {
            set<int> temp;
            for(auto j : sums)
            {
                temp.insert(stones[i] + j);
                temp.insert(stones[i] - j);
            }
            sums.swap(temp);
        }
        int mn = stones[0];
        for(auto i : sums)
            mn = min(mn, abs(i));
        return mn;
    }
};