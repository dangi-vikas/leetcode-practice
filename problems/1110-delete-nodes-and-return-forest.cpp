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
    vector<TreeNode*> ans;
    unordered_set<int> st;
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDelete) {
        for(int i=0; i<toDelete.size(); i++) {
            st.insert(toDelete[i]);
        }
        
        deleteNode(root);
        
        if(root) ans.push_back(root);
        
        return ans;
    }
    
    
    void deleteNo de(TreeNode* &root) {
        if(root) {
            deleteNode(root->left);
            deleteNode(root->right);
            
            if(st.find(root->val) != st.end()) {
                if(root->left) ans.push_back(root->left);
                if(root->right) ans.push_back(root->right);
                
                root = nullptr;  
            }
        }
    }
};