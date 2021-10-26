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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> container;

        pathSumRec(root, targetSum, ans, container);
        
        return ans;
    }
    
    void pathSumRec(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int> container){
        
        //if the current node is null
        if(!root) return;

        //pushing the value of current node in temporary container and reducing the target
        container.push_back(root->val);
        targetSum -= root->val;
        
        //if leaf node is reached
        if(!root->right && !root->left){

            //if the target is reached pushing the container in ans vector
            if(targetSum==0) ans.push_back(container);
        }
        
        //traversing the left and right subtree
        else{
            pathSumRec(root->left, targetSum, ans, container);
            pathSumRec(root->right, targetSum, ans, container);
        }
        
        //backtracking step
        container.pop_back();
    }
};