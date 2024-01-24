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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> counts(10, 0);    
        return findAllPaths(root, counts);
    }
    
    int findAllPaths(TreeNode* root, vector<int>& counts){
        if(!root) return 0;
        
        counts[root->val]++;
        
        if(!root->left && !root->right) {
            int odds = 0;
            
            for(auto x : counts) 
                if(x % 2 != 0) odds++;
            
            if(odds <= 1) {
                counts[root->val]--;
                return 1;
            }
        }
        
        int left = findAllPaths(root->left, counts);
        int right = findAllPaths(root->right, counts);
        
        counts[root->val]--;
        
        return left + right;
    }
};
