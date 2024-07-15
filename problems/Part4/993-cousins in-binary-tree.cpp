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
    bool isCousins(TreeNode* root, int x, int y) {
        int flag = 0; 
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size(); 
            
            for(int i=0; i<n; i++) {
                TreeNode *temp = q.front();
                q.pop();
                
                if(temp->left && temp->right && (temp->left->val == x || temp->right->val == x) &&(temp->left->val == y || temp->right->val == y))
                    return 0;
                
                if(temp->left) {
                    if(temp->left->val == x || temp->left->val == y) 
                        flag++;
                    q.push(temp->left); 
                }
                
                if(temp->right) {
                    if(temp->right->val == x || temp->right->val == y) 
                        flag++;
                    
                    q.push(temp->right);
                }
                
                if(flag == 2) return 1;
            }
            
            if(flag == 1) return 0;
        }

        return 0;
    }
};