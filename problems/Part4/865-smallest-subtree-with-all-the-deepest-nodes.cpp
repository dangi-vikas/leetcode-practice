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
    int maxDepth = -1;
    TreeNode* ans = nullptr;
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        postOrder(root, 0);
        return ans;
    }
    
    int postOrder(TreeNode* root, int depth) {
        if(!root) return depth;
        
        int leftHeight = postOrder(root->left, depth+1);
        int rightHeight = postOrder(root->right, depth+1);
        
        if(leftHeight == rightHeight) {
            maxDepth = max(maxDepth, leftHeight);
            if(maxDepth == leftHeight) ans = root;
        }
        
        return max(leftHeight, rightHeight);
    }
};