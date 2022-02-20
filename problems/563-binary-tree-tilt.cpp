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
    int tilt = 0;
    
public:
    int findTilt(TreeNode* root) {
        subTreeSum(root);
        return tilt;
    }
    
    int subTreeSum(TreeNode* root) {
        if(!root) return 0;
        
        int leftTreeSum = subTreeSum(root->left);        
        int rightTreeSum = subTreeSum(root->right);
        
        tilt += abs(leftTreeSum - rightTreeSum);
            
        return leftTreeSum + rightTreeSum + root->val;
    }
};