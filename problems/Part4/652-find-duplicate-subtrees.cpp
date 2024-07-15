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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtreeHashMap;
        vector<TreeNode*> ans;

        findDuplicateSubtrees(root, subtreeHashMap, ans);

        return ans;
    }

    string findDuplicateSubtrees(TreeNode* root, unordered_map<string, int>& subtreeHashMap, vector<TreeNode*>& ans) {
        if(!root) return " ";

        string subtreeHash = to_string(root->val) + " " + findDuplicateSubtrees(root->left, subtreeHashMap, ans) + " " + findDuplicateSubtrees(root->right, subtreeHashMap, ans);

        if(subtreeHashMap[subtreeHash]++ == 1) ans.push_back(root);

        return subtreeHash;
    }
};