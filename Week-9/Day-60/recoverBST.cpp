void dfs(TreeNode* root, TreeNode* &a1, TreeNode* &a2, TreeNode* &p){
    if(root == NULL)
        return;
    dfs(root->left, a1, a2, p);
    if(p){
        if(p->val > root->val){
            if(!a1)
                a1 = p;
            a2 = root;
        }
    }
    p = root;
    dfs(root->right, a1, a2, p);
}
 
 
vector<int> Solution::recoverTree(TreeNode* A) {
    if(!A || (!A->left && !A->right))
        return {};
    TreeNode* a1 = NULL, *a2 = NULL, *p = NULL;
    dfs(A, a1, a2, p);
    if(a1->val < a2->val)
        return {a1->val, a2->val};
    return {a2->val, a1->val};
}