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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bstFromPreorder(preorder, index, INT_MAX);
    }
    
    TreeNode* bstFromPreorder(vector<int> preorder, int& index, int upperBound) {
        if(index == preorder.size() || preorder[index] > upperBound) 
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = bstFromPreorder(preorder, index, root->val);
        root->right = bstFromPreorder(preorder, index, upperBound);
        
        return root;
    }
};