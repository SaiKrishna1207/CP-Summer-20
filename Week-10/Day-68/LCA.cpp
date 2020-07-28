/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> getPath(TreeNode* root, int val, vector<int> path){
    if(!root)
        return {};
    path.push_back(root->val);
    if(root->val == val)
        return path;
    
    if(root->left){
        vector<int> k = getPath(root->left, val, path);
        if(k.size() != 0)
            return k;
    }
    if(root->right){
        vector<int> k = getPath(root->right, val, path);
        if(k.size() != 0)
            return k;
    }
    return {};
}
 
int Solution::lca(TreeNode* A, int B, int C) {
    if(!A)
        return 0;
    int i, j;
    vector<int> pathB = getPath(A, B, {});
    vector<int> pathC = getPath(A, C, {});
    if(pathB.size() == 0 || pathC.size() == 0)
        return -1;
    i = 0;
    while(i < pathC.size() && i < pathB.size()){
        if(pathB[i] == pathC[i])
            i++;
        else
            break;
    }
    return pathC[i - 1];
}
