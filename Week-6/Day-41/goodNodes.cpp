/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    vector<int> t;
    void dfs(TreeNode* root){
        if(!root)
            return;
        t.push_back(root->val);
        int i;
        for(i = 0;i < t.size(); i++){
            if(t[i] > root->val)
                break;
        }
        if(i == t.size())
            count++;
        if(root->left){
            dfs(root->left);
            t.pop_back();
        }
        if(root->right){
            dfs(root->right);
            t.pop_back();
        }
    }
    
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root);
        return count;
    }
};