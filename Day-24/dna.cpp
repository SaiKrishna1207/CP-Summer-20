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
            if(!m[sub])
                m[sub] = 1;
            else if(m[sub] == 1)
            {
                m[sub] = 2;
                ans.push_back(sub);
            }
        }
        return ans;
    }
};