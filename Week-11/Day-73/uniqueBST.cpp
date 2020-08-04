/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*> dfs(int cur, int n){
    if(cur > n)
        return {NULL};
    TreeNode* root;
    vector<TreeNode*> ans;
    int i, j, k;
    for(i = cur; i <= n; i++){
        vector<TreeNode*> l = dfs(c, i - 1);
        vector<TreeNode*> r = dfs(i + 1, n);
        for(auto left : l){
            for(auto right : r){
                root = new TreeNode(i);
                root->left = left;
                root->right = right;
                ans.push_back(root);
            }
        }
    }
    return ans;
} 

vector<TreeNode*> Solution::generateTrees(int A) {
    if(A == 0)
        return {};
    return dfs(1, A);
}
