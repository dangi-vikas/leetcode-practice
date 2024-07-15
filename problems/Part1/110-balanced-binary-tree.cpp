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
    bool isBalanced(TreeNode* root) {
        return isBalancedRec(root) != -1;
    }
    
    int isBalancedRec(TreeNode* root){

        //base condition
        if(!root) return 0;
        
        int lHeight = isBalancedRec(root->left);
        int rHeight = isBalancedRec(root->right);
        
        //if any of the subtree returns height as -1
        if(lHeight==-1 || rHeight==-1) return -1;

        //if the tree is unbalanced returning -1
        if(abs(lHeight-rHeight) > 1) return -1;
        
        //returning maximum height of the tree
        return 1+(lHeight>rHeight ? lHeight : rHeight);
    }
};