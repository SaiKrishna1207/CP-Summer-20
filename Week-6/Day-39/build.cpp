/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findIndex(vector<int> B, int t, int l, int h){
    int i;
    for(i = l; i <= h; i++){
        if(B[i] == t)
            return i;
    }
}
int k = 0;
TreeNode* build(vector<int> A, vector<int> B, int l, int h, int &i){
    if(l > h)
        return NULL;
    TreeNode* cur = new TreeNode(A[i++]);
    if(l == h)
        return cur;
    int j = findIndex(B, cur->val, l, h);
    cur->left = build(A, B, l, j - 1, i);
    cur->right = build(A, B, j + 1, h, i);
    
    return cur;
}
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    if(!A.size() || !B.size())
        return NULL;
    int i = 0;
    TreeNode* root = build(A, B, 0, B.size() - 1, i);
    return root;
}
