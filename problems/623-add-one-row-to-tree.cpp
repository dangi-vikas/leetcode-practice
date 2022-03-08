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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        
        if(depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        
        insert(root, depth, val, 1);
        return root;
    }
    
    void insert(TreeNode* root, int depth, int val, int currDepth) {
        if(!root) return;
        
        if(currDepth == depth-1) {
            TreeNode* temp = root->left;
            root->left = new TreeNode(val);
            root->left->left = temp;
            temp = root->right;
            root->right = new TreeNode(val);
            root->right->right = temp;
        }
        
        else {
            insert(root->left, depth, val, currDepth+1);                                 insert(root->right, depth, val, currDepth+1);
        }
    }
};