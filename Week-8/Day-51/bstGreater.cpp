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
    int sum = 0;
    void traverse(TreeNode* root, bool q){
        if(root == NULL)
            return;
        traverse(root->left, q);
        if(!q)
            sum += root->val;
        else{
            int t = root->val;
            root->val = sum;
            sum -= t;
        }
        traverse(root->right, q);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return root;
        TreeNode* t = root;
        traverse(root, false);
        traverse(root, true);
        return root;
    }
};