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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        //if the tree does not have any node
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int flag = 1; 

        //BFS
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            
            for(int i=0; i<size; i++){
                TreeNode* node = q.front(); 
                q.pop();
                
                //filling the level alternatively changing the direction
                int idx = flag ? i : (size-1-i);
                
                //traversing level wise
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); 
                
                temp[idx] = node->val;
            }

            flag = !flag;
            ans.push_back(temp);
        }
        
        return ans;
    }
};