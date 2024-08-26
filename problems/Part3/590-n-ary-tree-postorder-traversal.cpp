/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        
        vector<int> ans; 
        
        for(int i = 0; i<root->children.size(); i++) {
            vector<int> temp = postorder(root->children[i]);
            
            for(int j=0; j<temp.size(); j++) 
                ans.push_back(temp[j]);
        }
        
        ans.push_back(root->val);
        
        return ans;
    }
};