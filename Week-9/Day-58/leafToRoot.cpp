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
    string ans = "";
    void dfs(TreeNode* root, string cur){
        if(!root->left && !root->right){
            char x = root->val + 'a';
            string s = cur + x;
            reverse(s.begin(), s.end());
            if(ans == "")
                ans = s;
            else{
                if(ans > s)
                    ans = s;
            }
            return;
        }
        char c = root->val + 'a';
        if(root->left)
            dfs(root->left, cur + c);
        if(root->right)
            dfs(root->right, cur + c);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root)
            return "";
        dfs(root, "");
        return ans;
    }
};