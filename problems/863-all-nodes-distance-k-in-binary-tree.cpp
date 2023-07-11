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
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        int level = 0;
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent;

        markParents(root, parent);

        q.push(target);
        visited.insert(target);

        while(!q.empty()) {
            int size = q.size();
            if(level++ == k) break;

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(parent.count(node) && !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }

                if(node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }
        }

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(!root) return;

        if(root->left) {
            parent[root->left] = root;
            markParents(root->left, parent);
        }

        if(root->right) {
            parent[root->right] = root;
            markParents(root->right, parent);
        }
    }
};