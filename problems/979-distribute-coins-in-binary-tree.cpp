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
    int ans;
    
    int distributeCoins(TreeNode* root) {
        ans = 0;
        countSteps(root);
        return ans;
    }
    
    int countSteps(TreeNode* root) {
        if(!root) return 0;
        
        int leftCoins = countSteps(root->left);
        int rightCoins = countSteps(root->right);
        
        ans += abs(leftCoins) + abs(rightCoins);

        return (root->val - 1) + leftCoins + rightCoins;
    }
};
