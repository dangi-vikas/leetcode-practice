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
    unordered_map<int, vector<TreeNode*>> dp;
    
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        return allPossibleFBTRec(n);
    }
    
    vector<TreeNode*> allPossibleFBTRec(int n) {
        if(n % 2 == 0) return {};
        
        if(n == 1) {
            TreeNode* node = new TreeNode(0);
            return {node};
        }
       
        if(dp.find(n) != dp.end()) return dp[n];
        
        vector<TreeNode*> ans;
        
        for(int i = 1; i < n; i+=2) {
            vector<TreeNode*> left = allPossibleFBTRec(i);
            vector<TreeNode*> right = allPossibleFBTRec(n-i-1);
            
            for(TreeNode* l : left) {
                for(TreeNode* r : right) {
                    TreeNode* root = new TreeNode(0);
                    
                    root -> left = l;
                    root -> right = r;
                    
                    ans.push_back(root);
                }
            }
        }
        
        return dp[n] = ans;
    }
};