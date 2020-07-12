/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* make(const vector<int> &A, int l, int r){
    if(l > r)
        return NULL;
    int mid = l + ((r - l) / 2);
    TreeNode* root = new TreeNode(A[mid]);
    root->left = make(A, l, mid - 1);
    root->right = make(A, mid + 1, r);
    
    return root;
} 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    if(!A.size())
        return NULL;
    return make(A, 0, A.size() - 1);
}
