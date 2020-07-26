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
    int ans = 0;

    int countPairs(TreeNode* root, int distance) {
        if(!root)
            return 0;
        
        dfs(root, distance);
        return ans;
    }
    
    vector<int> dfs(TreeNode* root, int d) {
        vector<int> res(11);
        if(!root) 
            return res;
        
        if(!root->left && !root->right) {
            res[1] = 1;
            return res;
        }
        int i, j;
        
        vector<int> l = dfs(root->left, d);
        vector<int> r = dfs(root->right, d);
    
        for(int i = 1; i <= 10; i++) {
            if(l[i]) {
                for(j = 1; j <= d - i; j++) 
                    ans += l[i] * r[j]; 
            }
        }

        //for my parent node, set number of node at distance+1 position
        //discard those whose distance is already exceeding the limit
        for(i = 0; i < d; i++) {
            res[i + 1] += l[i] + r[i];
        }
        
        return res;
    }
    
};