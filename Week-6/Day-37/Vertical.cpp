class Solution {
public:
    
    map <int,vector<pair<int,int>>> mp;

    void dfs(TreeNode* root, int s,int l){
        if(!root)
            return;
        
        mp[s].push_back({l, root->val});
        dfs(root->left, s - 1, l + 1);
        dfs(root->right, s + 1, l + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {};
        int i, j;
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for(auto i = mp.begin();i != mp.end(); i++){
            sort(i->second.begin(), i->second.end());
        }
    
        for(auto i = mp.begin();i != mp.end();i++){
            vector <int> temp;
            for(auto j = 0;j < i->second.size(); j++)
                temp.push_back(i->second[j].second);
            ans.push_back(temp);
        }
        return ans;
    }
};
