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
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root,  k);
    }
    
    bool dfs(TreeNode* root, TreeNode* curr, int k) {  
        if(!curr) return false;
         
        if(search(root, curr, k - curr->val))
            return true;
         
        return dfs(root, curr->left, k) || dfs(root, curr->right, k);
    }
    
    bool search(TreeNode* root, TreeNode* curr, int k) { 
        while(root) {
            if(k > root->val)
                root = root->right;
            
            else if(k < root->val)
                root = root->left;
            
            else return root != curr;  
        } 
        
        return false;
    }
};