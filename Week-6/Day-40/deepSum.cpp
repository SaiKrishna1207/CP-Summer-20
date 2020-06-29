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
    int ans = 0, x;
    
    void findSum(TreeNode* root, int level){
        if(!root)
            return;
        if(level == x)
            ans += root->val;
        findSum(root->left, level + 1);
        findSum(root->right, level + 1);
    }
    
    int findMax(TreeNode* root){
        if(!root)
            return 0;
        int left = findMax(root->left);
        int right = findMax(root->right);
        if(left > right)
            return left + 1;
        return right + 1;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        x = findMax(root);
        findSum(root, 1);
        return ans;
    }
};