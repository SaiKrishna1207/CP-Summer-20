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
    vector<int> t;
    void dfs(TreeNode* root)
    {
        if(root)
            t.push_back(root->val);
        if(!root->left && !root->right)
        {
            int i, j = 0, n = 0;
            for(i = t.size() - 1; i >= 0; i--){
                n += t[i] * pow(10, j);
                j++;
            }
            sum += n;
            return;
        }
        if(root->left)
        {
            dfs(root->left);
            t.pop_back();
        }
        if(root->right)
        {
            dfs(root->right);
            t.pop_back();
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root);
        return sum;
    }
};