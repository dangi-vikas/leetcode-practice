/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            
            if(!node) s.append("#,");
            else s.append(to_string(node->val)+ ',');
            
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        stringstream ss(data);
        string token;
        
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            
            getline(ss, token, ',');
                
            if(token == "#")  node->left = NULL;

            else{
                TreeNode* leftNode = new TreeNode(stoi(token));
                node->left = leftNode;
                q.push(leftNode);
            }
                
            getline(ss, token, ',');
                
            if(token == "#")  node->right = NULL;

            else{
                TreeNode* rightNode = new TreeNode(stoi(token));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;