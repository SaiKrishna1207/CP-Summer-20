/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void Zigzag(vector<vector<int>> & ans, TreeNode *root) 
    { 
        int h = height(root); 
        int i;
        bool ltr = true; 
        for (i = 1; i <= h; i++) 
        { 
            printLevel(ans, root, i, ltr, 0);
            ltr = !ltr; 
        } 
    } 
  
    void printLevel(vector<vector<int>> & ans, TreeNode* root, int level, int ltr, int k) 
    { 
        if (root == NULL) 
            return; 
        if (level == 1) 
            ans[k].push_back(root->val);
        else if (level > 1) 
        { 
            if (ltr) 
            { 
                printLevel(ans, root->left, level - 1, ltr, k + 1); 
                printLevel(ans, root->right, level - 1, ltr, k + 1); 
            } 
            else 
            { 
                printLevel(ans, root->right, level - 1, ltr, k + 1); 
                printLevel(ans, root->left, level - 1, ltr, k + 1); 
            } 
        } 
    } 
    int height(TreeNode* node)  
    {  
        if (node == NULL)  
            return 0;  
        else
        {  
            int lheight = height(node->left);  
            int rheight = height(node->right);  
            if (lheight > rheight)  
                return (lheight + 1);  
            else return (rheight + 1);  
        }  
    }  
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        int maxheight = height(root);
        vector<vector<int>> ans(maxheight);
        Zigzag(ans, root);
        return ans;
    }
};