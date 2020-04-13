class Solution {
public:
    string giveAnagramString(string y)
    {
        string x = "";
        if(y.length() == 0)
            return x;
        int arr[26] = {0};
        int i;
        for(i = 0;i < y.length(); i++)
            arr[y[i] - 97]++;
        for(i = 0;i < 26; i++)
            x += to_string(arr[i]);
        return x;
    }
    
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {   
        int n = strs.size();
        int i, j;
        vector<string> ar;
        for(i = 0;i < n; i++)
        {
            string s = giveAnagramString(strs[i]);
            ar.push_back(s);
        }
        unordered_map<string, vector<int>> m;
        for(i = 0;i < n; i++)
        {
            m[ar[i]].push_back(i);
        }
        int l = m.size();
        cout << l;
        vector<vector<string>> ans(l);
        int k = 0;
        for(auto i : m)
        {
            for(j = 0;j < i.second.size(); j++)
                ans[k].push_back(strs[i.second[j]]);
            k++;
        }
        return ans;
        
    }
};