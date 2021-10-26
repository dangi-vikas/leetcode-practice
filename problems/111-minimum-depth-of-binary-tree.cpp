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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
    
        queue<TreeNode*> q;
        q.push(root);

        int depth = 1;

        //level order traversal
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){

                TreeNode* cur = q.front(); q.pop();

                //if the root is the leaf node 
                if(!cur->left && !cur->right) return depth;

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right); 
            }

            depth++;
        }

        return depth;   
    }
};