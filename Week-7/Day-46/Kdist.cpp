/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> mp;
    
    void makeGraph(TreeNode* root){
        if(!root)
            return;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if(root->right){
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        makeGraph(root->left);
        makeGraph(root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!root || !target)
            return {};
        if(K == 0)
            return {target->val};
        int i, j, k;
        vector<int> ans;
        makeGraph(root);
        queue<pair<int, int>> q;
        unordered_map<int, int> visited;
        q.push({target->val, 0});
        while(!q.empty()){
            int node = q.front().first;
            int l = q.front().second;
            q.pop();
            if(l == K)
                ans.push_back(node);
            visited[node] = true;
            for(j = 0;j < mp[node].size(); j++){
                if(!visited[mp[node][j]])
                    q.push({mp[node][j], l + 1});
            }
        }
        return ans;
    }
};