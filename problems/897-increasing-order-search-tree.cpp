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
    TreeNode* ans = new TreeNode(); 
    TreeNode* curr = ans;
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return ans;
    
        increasingBST(root->left);

        TreeNode* temp = new TreeNode(root->val);
        curr->right = temp;
        curr = curr->right;

        increasingBST(root->right);

        return ans->right;
    }
};