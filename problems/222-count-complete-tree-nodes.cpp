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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        
        int leftHeight = findHeight(root->left, 0);
        int rightHeight = findHeight(root->right, 1);
        
        /*if left height and right height is equal
          then the tree is perfect*/
        if(leftHeight == rightHeight)
            return (pow(2, leftHeight+1) -1);
        
        
        //root + nodes on left + nodes on right
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    //finding the right or left subtree height
    int findHeight(TreeNode* root, int isRight) {
        if(!root) return 0;
        
        if(isRight) return 1 + findHeight(root->right, 1);
        
        return 1 + findHeight(root->left, 0);
    }
};