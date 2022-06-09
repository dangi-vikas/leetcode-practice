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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        
        vector<int> leaves1, leaves2;
        
        setLeafArray(root1 , leaves1);        
        setLeafArray(root2 , leaves2);
		
        return leaves1 == leaves2;
    }
    
    void setLeafArray(TreeNode* root, vector<int>& leaves) {
        if(!root->left && !root->right) 
            leaves.push_back(root->val);        
        
        if(root->left) setLeafArray(root->left, leaves);
        if(root->right) setLeafArray(root->right, leaves);
    }
};