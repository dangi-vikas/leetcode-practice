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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        
        queue<TreeNode*> q;
        bool isOddLevel = true;
      
        q.push(root);

        while(!q.empty()) {
            int size = q.size() ;
            int prevNode = isOddLevel ? INT_MIN : INT_MAX;

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop(); 

                if(isOddLevel) {
                    if(node->val % 2 == 0 || node->val <= prevNode)
                        return false;
                }

                else {
                    if(node->val % 2 != 0  || node->val >= prevNode)
                        return false;
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                prevNode = node->val;
            }

            isOddLevel =! isOddLevel;
        }
        
        return true;
    }
};
