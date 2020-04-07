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
    vector<TreeNode*> allPossibleFBT(int N) 
    {
        int i;
        if(N%2 == 0)
            return {};
        int n = (N+1) / 2;
        vector<TreeNode*> answers;
        if(n == 1)
        {
            answers.push_back(new TreeNode(0));
            return answers;
        }
        for(i = 1;i < n; i++)
        {
            vector<TreeNode*> left = allPossibleFBT((2 * i) - 1);
            vector<TreeNode*> right = allPossibleFBT((2 * (n - i)) - 1);
            for(auto& l : left)
            {
                for(auto& r: right)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    answers.push_back(root);
                }
            }
        }
        return answers;
    }
};