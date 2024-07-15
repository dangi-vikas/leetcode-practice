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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        if(!root->left && !root->right) return -1;
        
        int left = root->left->val, right = root->right->val;
        
        if(root->val == root->left->val) left = findSecondMinimumValue(root->left);
        if(root->val == root->right->val) right = findSecondMinimumValue(root->right);
        
        if(left != -1 && right != -1) return min(left, right);
        if(left != -1) return left;
        return right;
    }
};