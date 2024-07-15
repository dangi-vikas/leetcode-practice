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
    vector<vector<string>> printTree(TreeNode* root) {
        int m= getHeight(root);
        int n = pow(2, m) - 1;
        int row=0, col=(n-1)/2;
        
        vector<vector<string>> ans(m, vector<string>(n));   
        ans[row][col] = to_string(root->val);
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, col});
        
        int posLeft, posRight;                 
     
        while(!q.empty()){
            for(int i=0, sz=q.size(); i<sz; i++){
                auto [node, pos] = q.front();
                q.pop();
                
                if(node->left){
                    posLeft = pos - pow(2, m-2-row);     
                    ans[row+1][posLeft] = to_string(node->left->val);
                    q.push({node->left, posLeft});
                }
                if(node->right){
                    posRight = pos + pow(2, m-2-row);    
                    ans[row+1][posRight] = to_string(node->right->val);
                    q.push({node->right, posRight});
                }
            }
            
            row++;  
        }
        
        return ans;   
    }
    
    int getHeight(TreeNode* root){        
        if(!root)return 0;
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        return max(left, right) + 1;
    }
};