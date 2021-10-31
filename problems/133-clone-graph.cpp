/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        
        vector<Node*> visited(1000, nullptr);
        Node* clone = new Node(node->val);
        visited[node->val] = clone;
        
        for(auto curr : node->neighbors){
            if(!visited[curr->val]){
                Node* newNode = new Node(curr->val);
                (clone->neighbors).push_back(newNode);
                dfs(curr, newNode, visited);
            }
            
            else (clone->neighbors).push_back(visited[curr->val]);
        }
        
        return clone;
    }
    
    void dfs(Node* curr, Node* node, vector<Node*>& visited){
        visited[node->val] = node;
        
        for(auto n: curr->neighbors){
            if(!visited[n->val]){
                Node* newNode = new Node(n->val);
                (node->neighbors).push_back(newNode);
                dfs(n, newNode, visited);
            }
            
            else (node->neighbors).push_back(visited[n->val]);
        }
    }
};