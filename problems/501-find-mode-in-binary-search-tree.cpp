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
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};
        
        vector<int> ans;
        int curr = 0, max = 0, prev = 0;
        
        findModeRec(root, prev, max, curr, ans);
        
        return ans;
    }
    
    void findModeRec(TreeNode* root, int& prev, int& max, int& curr, vector<int>& ans) {
        if (!root) return;
        
        findModeRec(root->left, prev, max, curr, ans);
        
        if (prev == root->val) curr++;
        else {
            prev = root->val;
            curr = 1;
        }
        
        if (curr == max) ans.push_back(root->val);
        else if (curr > max) {
            ans = {root->val};
            max = curr;
        }
        
        findModeRec(root->right, prev, max, curr, ans);
    }
};