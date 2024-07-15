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
    int minDifference = INT_MAX;
    TreeNode* last = nullptr;
        
public:
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        getMinimumDifferenceRec(root);
        return minDifference;
        
    }
    
    void getMinimumDifferenceRec(TreeNode* root){
        if (!root) return;
         
        getMinimumDifferenceRec(root->left);
        
        if(last) {
            int currDifference = abs(last->val - root->val);
            minDifference = min(minDifference, currDifference);
        }
        
        last = root;
        getMinimumDifferenceRec(root->right);
    }
};