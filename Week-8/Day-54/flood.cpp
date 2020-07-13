class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int i, j, k;
        vector<int> ans(rains.size(), -1);
        unordered_map<int, int> mp;
        set<int> zero;
        for(i = 0; i < rains.size(); i++)
        {
            if(rains[i] == 0)
            {
                zero.insert(i);
                ans[i] = 1;
            }
            else
            {
                if(mp.count(rains[i]))
                {
                    int li = mp[rains[i]];
                    auto zi = zero.upper_bound(li);
                    if(zi == zero.end())
                        return {};
                    
                    ans[*zi] = rains[i];
                    zero.erase(zi);
                }
                mp[rains[i]] = i;
            }
        }
        return ans;
    }
};