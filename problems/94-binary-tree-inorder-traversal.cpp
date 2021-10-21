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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inorderTraversalRec(root, ans);

        return ans;
    }
    
    void inorderTraversalRec(TreeNode* root, vector<int>& ans){
        
        //if root is null
        if(!root) return;
        
        //inorder traversal
        inorderTraversalRec(root->left, ans);
        ans.push_back(root->val);
        inorderTraversalRec(root->right, ans);
    }
};