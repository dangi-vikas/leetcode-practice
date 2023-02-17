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
    int prev = INT_MAX, ans = INT_MAX;
    
public:
    int minDiffInBST(TreeNode* root) {
        if(!root) return INT_MAX;
        return inorder(root);
    }
    
    int inorder(TreeNode* root) {
        if(!root) return INT_MAX;
        
        inorder(root->left);
        ans = min(ans, abs(root->val - prev));
        prev = root->val;
        inorder(root->right);
        
        return ans;
    }
};