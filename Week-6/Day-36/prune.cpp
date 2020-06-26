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
    
    void prune(TreeNode* root){
        if(root->left && (root->left->left || root->left->right))
            prune(root->left);
        if(root->right && (root->right->left || root->right->right))
            prune(root->right);
        if(root->left && root->left->val == 0 && !root->left->left && !root->left->right)
            root->left = NULL;
        if(root->right && root->right->val == 0 && !root->right->left && !root->right->right)
            root->right = NULL;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return root;
        if(!root->left && !root->right)
            return root;
        prune(root);
        return root;
    }
};