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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return nullptr;
        
        unordered_map<int, int> traversal;

        for(int i=0; i<inorder.size(); i++){
            traversal[inorder[i]] = i;
        }

        TreeNode* root = buildTreeRec(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, traversal);

        return root;
    }
    
    TreeNode* buildTreeRec(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, 
                           unordered_map<int, int>& traversal){
        
        //if all the elements of inorder or preorder array are traversed
        if(postStart>postEnd || inStart>inEnd) return nullptr;

        //assigning starting element of preorder array as root
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot =  traversal[root->val];
        int numsLeft = inRoot - inStart;

        //constructing the left and right subtree of the tree
        root->left = buildTreeRec(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, traversal);
        root->right = buildTreeRec(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd, traversal);

        return root;
    }
};