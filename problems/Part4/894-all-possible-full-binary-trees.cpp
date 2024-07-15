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
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> dp;
        return allPossibleFBT(n, dp);
    }

    vector<TreeNode*> allPossibleFBT(int n, unordered_map<int, vector<TreeNode*>>& dp) {
        if(n % 2 == 0) return {};
        if(n == 1) return {new TreeNode(0)};

        if(dp.find(n) != dp.end()) return dp[n];

        vector<TreeNode*> ans;

        for(int i=1; i<n; i+=2) {
            vector<TreeNode*> left = allPossibleFBT(i, dp);
            vector<TreeNode*> right = allPossibleFBT(n-i-1, dp);

            for(TreeNode* l : left) {
                for(TreeNode* r : right) {
                    TreeNode* root = new TreeNode(0);

                    root->left = l;
                    root->right = r;

                    ans.push_back(root);
                }
            }
        }

        return dp[n] = ans;
    }
};