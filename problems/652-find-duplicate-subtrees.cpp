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
        unordered_map<string, int> nodeMap;
        vector<TreeNode*> ans;
        
        findDuplicateSubtreesRec(root, nodeMap, ans);
        
        return ans;
    }
    
    string findDuplicateSubtreesRec(TreeNode* root, unordered_map<string, int>& nodeMap, vector<TreeNode*>& ans) {
        if(!root) return " ";
        
        string s = to_string(root->val) + " " + findDuplicateSubtreesRec(root->left, nodeMap, ans)+ " "+ findDuplicateSubtreesRec(root->right, nodeMap, ans);
        
        if(nodeMap[s]++ == 1)
            ans.push_back(root);
        
        return s;
    }
};