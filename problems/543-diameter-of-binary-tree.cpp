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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        diameterOfBinaryTreeRec(root);
        return ans;
    }
    
    int diameterOfBinaryTreeRec(TreeNode* root) {
        if(!root) return -1;
        
        int left = diameterOfBinaryTreeRec(root->left) + 1;
        int right = diameterOfBinaryTreeRec(root->right) + 1;
        
        ans = max(ans, left + right); 
        
        return max(left, right);    
    }
};
