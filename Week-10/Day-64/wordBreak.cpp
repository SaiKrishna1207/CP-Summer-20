struct TrieNode{
public:    
    TrieNode* child[26];
    bool ending; 
    TrieNode(){
        for(int i =0; i<26; i++)
            child[i] = NULL;
        ending = false;
    }
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    string s;
    int len;
    map<int, vector<string>>dp;
    
    void insert(string word){
        TrieNode* cur = root;
        int i, j, k;
        int size = word.size();
        for(i = 0; i < size; i++){
            int val = word[i] - 'a';
            if(cur->child[val] == NULL)
                cur->child[val] = new TrieNode();
                cur = cur->child[val];
        }
        cur->ending = true;
        return;
    }

    vector<string> rec(int pos){
        if(pos == len)
            return vector<string> (1, "");
        
        if(dp.find(pos) != dp.end())
            return dp[pos];
        
        int i, j;
        vector<string> ans;
        TrieNode* cur = root;
        
        string prefix = "";
        for(i = pos; i < len;i++){
            cur = cur->child[s[i] - 'a'];
            prefix += s[i];
            if(cur == NULL)
                break;
            if(cur->ending){
                vector<string> result = rec(i + 1);
                for(auto suffix: result)
                    ans.push_back(prefix + (suffix.size() > 0? " " : "") + suffix);
                
            } 
        }
        return dp[pos] = ans;
        
    }
    vector<string> wordBreak(string S, vector<string>& wordDict) {
        s = S;
        len = s.size();
        for(string word: wordDict)
           insert(word);
    
        return rec(0);
    }
};