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
    int ans = 0;
    
public:
    int longestUnivaluePath(TreeNode* root) {
        longestUnivaluePathRec(root); 
        return ans;
    }
    
    int longestUnivaluePathRec(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = longestUnivaluePathRec(root->left);
        int right = longestUnivaluePathRec(root->right);
        
        int leftcheck = 0, rightcheck = 0;
        
        if(root->left && root->val == root->left->val) leftcheck = left+1;
        if(root->right && root->val == root->right->val) rightcheck = right+1;
        
        ans = max(ans, leftcheck + rightcheck);
        
        return max(leftcheck, rightcheck);
    }
};