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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        //if the vector is empty
        if(!nums.size()) return nullptr;
        
        return sortedArrayToBSTRec(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedArrayToBSTRec(vector<int>& nums, int low, int high){
        
        //when the vector is fully traversed
        if(low>high) return nullptr;
        
        //binary search traversal
        int mid = low + ((high-low)>>1);
        
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBSTRec(nums, low, mid-1);
        node->right = sortedArrayToBSTRec(nums, mid+1, high);
        
        return node;
    }
};