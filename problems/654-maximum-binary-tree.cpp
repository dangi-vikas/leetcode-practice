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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTreeRec(nums, 0, nums.size()-1);
    }
    
    TreeNode* constructMaximumBinaryTreeRec(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        
        int maxIndex = start, maxValue = INT_MIN;
        
        for(int i=start; i<=end; i++) {
            if(maxValue < nums[i]) {
                maxValue = nums[i];
                maxIndex = i;
            }
        }
        
        TreeNode* node = new TreeNode(maxValue);
        node->left = constructMaximumBinaryTreeRec(nums, start, maxIndex-1);
        node->right = constructMaximumBinaryTreeRec(nums, maxIndex+1, end);
        
        return node;
    }
};