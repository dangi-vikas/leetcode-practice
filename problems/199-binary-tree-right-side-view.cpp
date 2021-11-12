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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        rightSideViewRec(root, 0, ans);

        return ans;
    }
    
    void rightSideViewRec(TreeNode* root, int level, vector<int>& ans){
        if(!root) return;

        //if its the first node in the level then pushing in ans 
        if(ans.size() == level) ans.push_back(root->val); 

        //recursively traversing the tree 
        rightSideViewRec(root->right, level+1, ans);
        rightSideViewRec(root->left, level+1, ans);
    }
};