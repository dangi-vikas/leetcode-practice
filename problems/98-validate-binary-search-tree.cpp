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
    bool isValidBST(TreeNode* root) {
        return isValidBSTRec(root,
            std::numeric_limits<long>::min(),
            std::numeric_limits<long>::max());
        
    }
    
    bool isValidBSTRec(TreeNode* root, long min, long max){
        
        //if tree has no node
        if(!root) return true;
        
        const long val = root->val;
        
        //recursively checking for the left and right subtrees' validity
        return ((val > min) && (val < max)) &&
            isValidBSTRec(root->left, min, val) &&
            isValidBSTRec(root->right, val, max);
    }
};