class TrieNode{
public:
    string word;
    TrieNode* child[26];
    bool isWord;
    
    TrieNode(){
        for(int i = 0;i < 26; i++)
            this->child[i] = NULL;
        this->isWord = false;
        this->word = "";
    }
};

class Trie{
public:
    TrieNode *root = new TrieNode();
    
    void insert(string word){
        TrieNode* cur = root;
        for(int i = 0;i < word.length(); i++){
            int index = word[i] - 'a';
            if(cur->child[index] == NULL)
                cur->child[index] = new TrieNode();
            cur = cur->child[index];
        }
        cur->isWord = true;
        cur->word = word;
    }
};


class Solution {
public:
    set<string> ans;
    
    void dfs(vector<vector<char>> board, int i, int j, TrieNode* curr, char c){
        if(board[i][j] == '@' || curr->child[c - 'a'] == NULL)
            return;
        char t = board[i][j];
        board[i][j] = '@';
        curr = curr->child[c - 'a'];
        if(curr && curr->isWord)
            ans.insert(curr->word);
        if(i + 1 < board.size() && board[i + 1][j] != '@')
            dfs(board, i + 1, j, curr, board[i + 1][j]);
        if(i - 1 >= 0 && board[i - 1][j] != '@')
            dfs(board, i - 1, j, curr, board[i - 1][j]);
        if(j + 1 < board[i].size() && board[i][j + 1] != '@')
            dfs(board, i, j + 1, curr, board[i][j + 1]);
        if(j - 1 >= 0 && board[i][j - 1] != '@')
            dfs(board, i, j - 1, curr, board[i][j - 1]);
        
        board[i][j] = t;
    }
    
    void search(vector<vector<char>> board, vector<string> words){
        Trie* tr = new Trie();
        TrieNode* r = tr->root;
        int i, j, k;
        for(i = 0; i < words.size(); i++)
            tr->insert(words[i]);
        
        for(i = 0;i < board.size(); i++){
            for(j = 0; j < board[i].size(); j++){
                char c = board[i][j];
                if(r->child[c - 'a'])
                    dfs(board, i, j, r, c);
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(!words.size() || !board.size())
            return {};
        search(board, words);
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};