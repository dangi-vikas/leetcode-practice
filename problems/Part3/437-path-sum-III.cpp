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
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<int, int> prefixSum{{0, 1}};
        
        pathSumRec(root, targetSum, 0, prefixSum, ans);
        return ans;
    }
    
    void pathSumRec(TreeNode* root, int& targetSum, int currSum,
             unordered_map<int, int>& prefixSum, int& ans) {
        
        if (root == NULL) return;
        
        currSum += root->val;
        ans += prefixSum[currSum - targetSum];
        prefixSum[currSum]++;
        
        pathSumRec(root->left, targetSum, currSum, prefixSum, ans);
        pathSumRec(root->right, targetSum, currSum, prefixSum, ans);
        
        prefixSum[currSum]--;
    }
};