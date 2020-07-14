class Solution {
public:
    
    int tot(vector<string>& v, unordered_map<char, int> mp, vector<int>& score){
        int i, j, k = 0;
        for(i = 0;i < v.size(); i++){
            string s = v[i];
            for(j = 0; j < s.length(); j++){
                char c = s[j];
                k += score[c - 'a'];
                mp[c]--;
                if(mp[c] < 0)
                    return 0;
            }
        }
        return k;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int i, j, k;
        if(!words.size() || !letters.size())
            return 0;
        int ans = 0;
        int n = words.size();
        unordered_map<char, int> mp;
        for(i = 0;i < letters.size(); i++)
            mp[letters[i]]++;
            
        for(i = 0; i < (1<<n); i++){
            vector<string> v;
            for(j = 0;j < n; j++){
                if(i&(1<<j))
                    v.push_back(words[j]);
            }
            k = tot(v, mp, score);
            ans = max(ans, k);
        }
        return ans;
    }
};