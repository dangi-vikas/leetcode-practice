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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
    
    int maxPathSum(TreeNode* root, int& ans) {
        if(!root) return 0;
        
        int left = maxPathSum(root->left, ans);
        int right = maxPathSum(root->right, ans);
        
        int incRoot = max((max(left, right) + root->val), root->val);
        int excRoot = max(incRoot, (left+right+root->val));
        ans = max(ans, excRoot);
        
        return incRoot;
    }
};