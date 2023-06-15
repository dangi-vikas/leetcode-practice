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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> q;
        int maxSum = INT_MIN;
        int currLevel = 0, maxLevel = 0;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int currSum = 0;
            

            for(int i=0; i<size; i++) {
                TreeNode* node = q.front(); 
                q.pop();

                currSum += (node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            currLevel++;

            if (maxSum < currSum) {
                maxSum = currSum;
                maxLevel = currLevel;
            }
        }

        return maxLevel;
    }
};