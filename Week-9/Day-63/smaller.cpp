class Solution {
public:
    struct bstNode {
        int val, count;
        bstNode* left;
        bstNode* right;
    };
    
    // return the smaller number count
    int insertNode(bstNode* &root, int val, int k) {
        if (!root) {
            root = new bstNode();
            root->val = val;
            root->count = 0;
            return k;
        }
        if (val > root->val) 
            return root->count + insertNode(root->right, val, k + 1);
        
        else {
            root->count++;
            return insertNode(root->left, val, k);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return {};
        if(n == 1)
            return {0};
        vector<int> ans(n, 0);
        int i, j, k;
        
        bstNode* root = NULL;
        
        for (i = n - 1; i >= 0; i--) 
            ans[i] = insertNode(root, nums[i], 0);
        
        return ans;
    }
};