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
    int longestZigZag(TreeNode* root) {
        int ans = 0;

        longestZigZag(root, 1, ans);
        longestZigZag(root, 0, ans);

        return ans ;
    }

    int longestZigZag(TreeNode* root, int dir, int& ans) {
        if(!root) return 0;

        int leftMax, rightMax;

        leftMax = longestZigZag(root->left, 1, ans);
        rightMax = longestZigZag(root->right, 0, ans);
        ans = max(ans, max(leftMax, rightMax));

        return (dir == 0) ? (leftMax + 1) : (rightMax + 1);
    }
};