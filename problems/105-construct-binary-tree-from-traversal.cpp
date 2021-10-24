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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> traversal;

        for(int i=0; i<inorder.size(); i++){
            traversal[inorder[i]] = i;
        }

        TreeNode* root = buildTreeRec(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, traversal);

        return root;
    }

    TreeNode* buildTreeRec(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, 
                           unordered_map<int, int> traversal){
        
        //if all the elements of inorder or preorder array are traversed
        if(preStart>preEnd || inStart>inEnd) return nullptr;

        //assigning starting element of preorder array as root
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot =  traversal[root->val];
        int numsLeft = inRoot - inStart;

        //constructing the left and right subtree of the tree
        root->left = buildTreeRec(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, traversal);
        root->right = buildTreeRec(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, traversal);

        return root;
    }
};