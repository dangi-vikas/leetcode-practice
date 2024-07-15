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

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;   
        maxPathSum(root, maxSum);
        return maxSum;
    }

    int maxPathSum(TreeNode* root, int& maxSum) {
        if(!root) return 0;

        int leftSum = max(maxPathSum(root->left, maxSum), 0);
        int rightSum = max(maxPathSum(root->right, maxSum), 0);

        maxSum = max(maxSum, (leftSum + rightSum + root->val));

        return max(leftSum, rightSum) + root->val;
    }
};
