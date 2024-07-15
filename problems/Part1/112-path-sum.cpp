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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //if the root is null
        if(!root) return false;

        //if the leaf node is reached
        if(!root->left && !root->right)
            return (targetSum - root->val) == 0;                //return whether or not or target id is reached
        
        //traversing left and right subtree
        return (hasPathSum(root->left, targetSum-root->val)) ||
               (hasPathSum(root->right, targetSum-root->val));
    }
};