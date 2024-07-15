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
    int mod = 1e9 + 7;

public:
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*, int> prefix;
        runPostOrder(root, prefix);

        long long ans = 0;
        int total = prefix[root]; 

        for (const auto& pair : prefix) {
            if (pair.first == root)  continue;
           
            long long src = pair.second;
            long long dst = total - src;
            long long test = src * dst;

            ans = max(ans, test);
        }
        
        return ans % mod;
    }

    int runPostOrder(TreeNode* curr, unordered_map<TreeNode*, int>& prefix) {
            if(!curr) return 0;

            int left = runPostOrder(curr->left, prefix);
            int right = runPostOrder(curr->right, prefix);

            prefix[curr] = left + right + curr->val;

            return prefix[curr];
    }
};
