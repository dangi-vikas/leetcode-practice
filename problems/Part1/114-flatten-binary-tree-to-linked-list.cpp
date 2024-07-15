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
    void flatten(TreeNode* root) {
        TreeNode* curr =  root;

        while(curr){

            if(curr->left){

                TreeNode* prev = curr->left;

                //reaching the last node of the left subtree
                while(prev->right) prev = prev->right; 

                //connecting the first node of the right subtree to the last node  
                prev->right = curr->right;

                //connecting the first node to second 
                curr->right = curr->left;

                curr->left = nullptr;
            }

            //traversing to the second element
            curr = curr->right;
        }
        
    }
};