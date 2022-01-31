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
    unordered_map<int, int> counts;
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        findFrequentTreeSumRec(root);
        
        int maxFrequency = INT_MIN;
        vector<int> ans;
        
        for(auto it : counts) {
            if(it.second > maxFrequency){
                ans.clear();
                maxFrequency = it.second;
                ans.push_back(it.first);
            }
            
            else if(maxFrequency == it.second) ans.push_back(it.first);
        }
        
        return ans;
    }
    
    int findFrequentTreeSumRec(TreeNode* root) {
        if(!root) return 0;
        
        int left = findFrequentTreeSumRec(root->left);
        int right = findFrequentTreeSumRec(root->right);
        int sum = left + right + root->val;
        
        counts[sum]++;
        
        return sum;
    }
};