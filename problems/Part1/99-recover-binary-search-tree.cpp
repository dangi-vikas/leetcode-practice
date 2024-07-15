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
    TreeNode* a,*b; // first mistake, second mistake
	TreeNode* prev;
    
    void recoverTree(TreeNode* root) {
        traversal(root);
        if(a != nullptr && b != nullptr) swap(a->val, b->val);
    }
    
    void traversal(TreeNode* n){
        if(n == nullptr) return;
        
        traversal(n->left);
        
        if(prev != nullptr && prev->val > n->val) {
            if(a == nullptr) {a = prev; b = n;} 
            else b = n;
        }
        prev = n;
        traversal(n->right);
    }
};
