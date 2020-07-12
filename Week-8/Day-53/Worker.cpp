class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int i, j, k;
        map<int,int> mp;
        for(i = 0;i < profit.size(); i++) 
            mp[difficulty[i]] = max(mp[difficulty[i]],profit[i]);
        
        mp[INT_MAX]=0;
        sort(worker.begin(),worker.end());
        
        i = 0, k = 0, j = 0; 
        for(auto it : mp)
        {
            while(i < worker.size() && it.first > worker[i])
            {
                j += k;
                i++;
            }
            if(i >= worker.size()) 
                break;
            k = max(k, it.second);
        }
        return j;
    }
}; 