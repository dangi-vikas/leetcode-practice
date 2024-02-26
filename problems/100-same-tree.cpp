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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        //if both the trees' roots are null
        if(!p && !q) return true;
 
        //if any one of the roots is null
        if(!p || !q) return false;
        
        //if the value of the roots does not match
        if(p->val != q->val) return false;
        
        //recursively checking for the left and right subtrees
        return isSameTree(p->left, q->left)  && isSameTree(p->right, q->right);
    }
};
