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

class CBTInserter {
    queue<TreeNode*> q;
    TreeNode* head;
    
public:
    CBTInserter(TreeNode* root) {
        head = root;
        q.push(root);
    }
    
    int insert(int val) {
        while(!q.empty()) {
            TreeNode* node = q.front();
            
            if(!node->left) {
                node->left = new TreeNode(val);
                return node->val;
            }
            
            q.push(node->left);
            
            if(!node->right) {
                node->right = new TreeNode(val);
                return node->val;
            }
            
            q.push(node->right);
            q.pop();
        }
        
        return 0;
    }
    
    TreeNode* get_root() {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */