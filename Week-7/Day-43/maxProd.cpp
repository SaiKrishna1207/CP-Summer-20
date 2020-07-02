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
    long long ans = INT_MIN;
    long long total;
    
    long long solve(TreeNode* root){
        if(!root)
            return 0;
        long long k = root->val;
        k += solve(root->left) + solve(root->right);
        ans = max(ans, k * (total - k));
        
        return k;
    }
    
    long long findSum(TreeNode* root){
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