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
    unordered_map<TreeNode*, int> mp;
    
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        
        if(mp[root]) return mp[root];
        
        int Cmax = root->val;
        
        if(root->left)
            Cmax += (rob(root->left->left) + rob(root->left->right));
        
        if(root->right)
            Cmax += (rob(root->right->left) + rob(root->right->right));
        
        return mp[root] = max(Cmax,rob(root->left)+rob(root->right));
    }
};