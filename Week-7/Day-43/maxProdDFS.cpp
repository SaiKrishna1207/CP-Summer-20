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
    long long int ans = INT_MIN;
    long long total;
    
    void solve(TreeNode* root){
        if(!root)
            return;
        int left = findSum(root->left);
        int right = findSum(root->right);
        ans = max({(total - right) * right, (total - left) * left, ans});
        
        solve(root->left);
        solve(root->right);
    }
    
    int findSum(TreeNode* root){
        if(!root)
            return 0;
        int cur = root->val;
        cur += findSum(root->left);
        cur += findSum(root->right);
        
        return cur;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        total = findSum(root);
        solve(root);
        return ans%1000000007;
    }
};