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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        
        sumOfLeftLeavesRec(root, 0, sum);  
        
        return sum;
    }
    
    void sumOfLeftLeavesRec(TreeNode *root, int flag, int sum){
        if(root){
            if(!root->left && !root->right && flag)
                sum += root->val;
        
                sumOfLeftLeavesRec(root->left, 1, sum);       
                sumOfLeftLeavesRec(root->right, 0, sum);   
        }
    }
};