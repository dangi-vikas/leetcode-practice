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
    typedef long long ll;

public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;

        ll ans = 0;

        sumNumbers(root, 0, ans);

        return ans;
    }

    void sumNumbers(TreeNode* root, ll currNum, ll& ans) {
        
        //if the node is null
        if(!root) return;
        
        //adding the value of node in the current sum
        currNum *= 10;
        currNum += root->val;

        
        //if the leaf node is reached than adding the current sum to total sum
        if(!root->left && !root->right) {
            ans += currNum;
            return;
        }

        //traversing different path of the tree
        sumNumbers(root->left, currNum, ans);
        sumNumbers(root->right, currNum, ans);
    }
};