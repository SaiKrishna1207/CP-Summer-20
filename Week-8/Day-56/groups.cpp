class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int i, j, k;
        int n = groupSizes.size();
        if(!n)
            return {};
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for(i = 0;i < n; i++)
            mp[groupSizes[i]].push_back(i);
        
        for(auto i : mp){
            k = i.first;
            vector<int> t;
            for(j = 0; j < i.second.size(); j++){
                t.push_back(i.second[j]);
                if(t.size() == k){
                    ans.push_back(t);
                    t.clear();
                }
            }
        }
        return ans;
        
    }
};