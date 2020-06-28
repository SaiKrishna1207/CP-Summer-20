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
    
    int diff = 0;
    void find(TreeNode* root, int mx,int mn){
        if(!root)
            return;
        diff = max(diff, max(abs(mx - root->val), abs(mn - root->val)));
        mx = max(root->val, mx);
        mn = min(root->val, mn);
        find(root->left, mx, mn);
        find(root->right, mx, mn);
    } 
    
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        find(root, root->val, root->val);
        return diff;
    }
};