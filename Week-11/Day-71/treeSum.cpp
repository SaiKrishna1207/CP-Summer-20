int dfs(TreeNode* root, int &ans){
    if(!root)
        return 0;
    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);
    
    int mx = max({max(l, r) + root->val, root->val, l + r + root->val});
    ans = max(ans, mx);
    
    return max(max(l, r) + root->val, root->val);
}

int Solution::maxPathSum(TreeNode* A) {
    if(!A)
        return 0;
    int ans = INT_MIN;
    dfs(A, ans);
    return ans;
}
