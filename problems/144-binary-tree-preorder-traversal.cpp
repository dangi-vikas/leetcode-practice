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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;

        preorderTraversalRec(root, ans);
        return ans;
    }
    
    void preorderTraversalRec(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        
        //preorder traversal
        ans.push_back(root->val);
        preorderTraversalRec(root->left, ans);        
        preorderTraversalRec(root->right, ans);
    }
};