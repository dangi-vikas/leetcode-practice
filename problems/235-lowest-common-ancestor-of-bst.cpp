    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        int curr = root->val;
        
        if(curr<p->val && curr<q->val) return lowestCommonAncestor(root->right, p, q);
        if(curr>p->val && curr>q->val) return lowestCommonAncestor(root->left, p, q);
        
        //if both the p and q do not lie on left or right of curr
        return root;
    }
};