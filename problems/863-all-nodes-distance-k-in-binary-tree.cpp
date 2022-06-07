/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentOf;
        markParents(root, parentOf);
        
        unordered_set<TreeNode *> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited.insert(target);
        
        int lvl = 0;
        
        while (q.size()) {
            int n = q.size();
            if (k == lvl++) break;
            
            for (int i=0; i<n; i++) {
                TreeNode *node = q.front(); q.pop();
                
                if (parentOf.find(node) != parentOf.end() && !visited.count(parentOf[node])) {
                    visited.insert(parentOf[node]);
                    q.push(parentOf[node]);
                }
                
                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
            }
        }
        
        vector<int> ans;
        while (q.size()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
        
    }
    
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentOf) {
        if (!root) return;
        
        if (root->left) {
            parentOf[root->left] = root;
            markParents(root->left, parentOf);
        }
        
        if (root->right) {
            parentOf[root->right] = root;
            markParents(root->right, parentOf);
        }
    }
};