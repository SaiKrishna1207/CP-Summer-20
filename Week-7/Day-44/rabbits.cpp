class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int i, j = 0, k;
        if(!answers.size())
            return 0;
        unordered_map<int, int> mp;
        for(i = 0;i < answers.size(); i++)
            mp[answers[i]]++;
        
        for(auto i : mp){
            k = i.first;
            int count = i.second;
            j += (k + 1) * ((k + count) / (k + 1));
        }
        return j;
    }
};