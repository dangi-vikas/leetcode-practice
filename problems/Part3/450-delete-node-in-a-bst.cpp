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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val == key)
            return deleteNodeRec(root);
        
        TreeNode* node = root;
        
        while(root){
            if(root->val > key){
                if(root->left && root->left->val == key)
                    root->left = deleteNodeRec(root->left);
                else root = root->left;
            }
            
            else{
                if(root->right && root->right->val == key)
                    root->right = deleteNodeRec(root->right);
                else root = root->right;
            }
        }
        
        return node;
    }
    
    TreeNode* deleteNodeRec(TreeNode* root){
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        
        TreeNode* rightNode = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightNode;
        return root->left;
    }
    
    TreeNode* findLastRight(TreeNode* root){
        if(!root->right) return root;
        return findLastRight(root->right);
    }
};