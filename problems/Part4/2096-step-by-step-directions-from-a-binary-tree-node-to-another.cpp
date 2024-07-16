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
    bool dfs(TreeNode* node, int val, string& path) {
        if(node->val == val)  return true;
        
        if(node->left && dfs(node->left, val, path)) {
            path.push_back('L');
        } else if(node->right && dfs(node->right, val, path)) {
            path.push_back('R');
        }
        
        return !path.empty();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath;
        
        dfs(root, startValue, startPath);
        dfs(root, destValue, destPath);
        
        while(!startPath.empty() && !destPath.empty() && startPath.back() == destPath.back()) {
            startPath.pop_back();
            destPath.pop_back();
        }
        
        return string(startPath.size(), 'U') + string(rbegin(destPath), rend(destPath));
    }
};