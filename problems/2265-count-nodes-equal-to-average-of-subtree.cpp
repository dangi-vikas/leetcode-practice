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
    typedef pair<int, int> pii;
    int ans = 0; 

public:
    int averageOfSubtree(TreeNode* root) {
        averageOfSubtree(root, 0, 0);
        return ans;
    }

    pii averageOfSubtree(TreeNode* root, int count, int sum) {
        if(!root) return {0, 0};

        pii left = averageOfSubtree(root->left, count, sum);
        pii right = averageOfSubtree(root->right, count, sum);

        count = left.first + right.first + 1;
        sum = left.second + right.second + root->val;

        if(root->val == sum / count) ans++;

        return {count, sum};
    }
};