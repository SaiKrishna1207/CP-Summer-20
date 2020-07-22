class Solution {
public:
    vector<vector<string>> ans;
    vector<string> t;
    
    bool isPali(string x){
        int i, l = x.length();
        for(i = 0;i < l / 2; i++){
            if(x[i] != x[l - i - 1])
                return false;
        }
        return true;
    }
    
    void dfs(string s, int ind){
        
        if(ind == s.length())
        {
            ans.push_back(t);
            return;
        }
        
        int i, j, len;
        for(len = 1;len <= s.length() - ind; len++){
            string sub = s.substr(ind, len);
            if(isPali(sub)){
                t.push_back(sub);
                dfs(s, ind + len);
                t.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int i, j, k;
        if(!s.length())
            return {};
        if(s.length() < 2)
            return {{s}};
        
        dfs(s, 0);
        return ans;
    }
};