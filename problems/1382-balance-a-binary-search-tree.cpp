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
    vector<int> arr;
    
    void inOrder(TreeNode* root){
        vector<TreeNode*> st;
        TreeNode* node=root;
        
        while(node || !st.empty()) {
            while(node) {
                st.push_back(node);
                node = node->left;
            }
            
            node = st.back();
            st.pop_back();
            
            arr.push_back(node->val);

            node = node->right;
        }
    }
    
    TreeNode* balanceBST(const int left, const int right) {
        if(left > right) return NULL;
        
        const int mid = left + ((right - left) >> 1);
        
        TreeNode* const leftSubTree = balanceBST(left, mid - 1);
        TreeNode* const rightSubTree = balanceBST(mid + 1, right);
        
        return new TreeNode(arr[mid], leftSubTree, rightSubTree);
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return balanceBST(0, arr.size() - 1);
    }
};
