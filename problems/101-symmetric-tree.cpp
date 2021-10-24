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
    bool isSymmetric(TreeNode* root) {
        return isSymmetricRec(root, root);
    }
    
    bool isSymmetricRec(TreeNode* root1, TreeNode* root2){
        
        //if both the roots are null
        if(!root1 && !root2) return true;
        
        //checking if the values are same for mirror nodes
        if(root1 && root2 && (root1->val == root2->val))
            return isSymmetricRec(root1->left, root2->right) && isSymmetricRec(root1->right, root2->left);
        
        return false;
    }
};