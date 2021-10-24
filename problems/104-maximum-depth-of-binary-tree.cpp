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
    int maxDepth(TreeNode* root) {
        
        //edge cases
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        //checking depth of left and right subtrees
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        
        //returning the maximum of depths added with the root
        return 1 + (lDepth>rDepth ? lDepth : rDepth);
    }
};