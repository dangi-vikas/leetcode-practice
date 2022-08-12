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
    int x = INT_MAX;

public:
    bool isUnivalTree(TreeNode* root) {
        if(x == INT_MAX) x = root->val;
        if(!root) return true;
        if(root->val != x) return false;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};