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
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right) 
            return root->val == 1;
        
        bool lTree = evaluateTree(root->left);
        bool rTree = evaluateTree(root->right);

        if(root->val == 2) 
            return lTree || rTree;
        
        else if(root->val == 3) 
            return lTree && rTree;

        return false;
    }
};
