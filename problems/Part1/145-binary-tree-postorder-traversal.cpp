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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;

        postorderTraversalRec(root, ans);
        return ans;
    }
    
    void postorderTraversalRec(TreeNode* root, vector<int>& ans) {
        if(!root) return;

        //postorder traversal 
        postorderTraversalRec(root->left, ans);
        postorderTraversalRec(root->right, ans);
        ans.push_back(root->val);
    }
};