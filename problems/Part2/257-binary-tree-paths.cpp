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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
            vector<string> temp;    
            return temp;
        }
        
        if(!root->left && !root->right){
            vector<string> temp;
            temp.push_back(to_string(root->val));       
            return temp;
        }
        
        vector<string> left = binaryTreePaths(root->left);
        for(int i = 0; i < left.size(); ++i){
            left[i] = to_string(root->val) + "->" + left[i];
        }
        
        vector<string> right = binaryTreePaths(root->right);
        for(int i = 0; i < right.size(); ++i){
            right[i] = to_string(root->val) + "->" + right[i];  
        }
        
        vector<string> ans;
        for(auto x: left) ans.push_back(x);
        for(auto x: right) ans.push_back(x);
        
        return ans;
    }
};