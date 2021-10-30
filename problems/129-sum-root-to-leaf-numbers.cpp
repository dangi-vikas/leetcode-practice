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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;

        long long ans=0;

        sumNumbersRec(root, 0, ans);
        return ans;
    }
    
    void sumNumbersRec(TreeNode* root, long long curr, long long& ans){
        
        //if the node is null
        if(!root) return;
        
        //adding the value of node in the current sum
        curr *= 10;
        curr += root->val;
        
        //if the leaf node is reached than adding the current sum to total sum
        if(!root->left && !root->right){
            ans += curr; return;
        }

        //traversing different path of the tree
        sumNumbersRec(root->left, curr, ans);
        sumNumbersRec(root->right, curr, ans);

    }
};