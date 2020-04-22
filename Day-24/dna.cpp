class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        int i, j, k, l = s.length();
        string sub = "";
        unordered_map<string, int> m;
        vector<string> ans;
        if(l < 9)   
            return ans;
        for(i = 0;i < l - 9; i++)
        {
            sub = s.substr(i, 10);
            m[sub]++;
        }
        for(auto i : m)
        {
            if(i.second > 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};