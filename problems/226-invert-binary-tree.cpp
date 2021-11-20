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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)  return root;
        
        //getting the left and right subtree
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        
        //inverting the tree
        root->left = right;
        root->right = left;
        
        return root;
    }
};