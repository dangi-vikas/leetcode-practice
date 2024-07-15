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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> graph;
        unordered_set<int> children;

        for(auto& edge : descriptions) {
            int parent = edge[0];   
            int child = edge[1];    
            int isLeft = edge[2];   
            
            TreeNode* parentNode = graph.count(parent) ? graph[parent] : new TreeNode(parent);
            TreeNode* childNode = graph.count(child) ? graph[child] : new TreeNode(child);

            if(isLeft == 1) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }

            graph[parent] = parentNode;
            graph[child] = childNode;

            children.insert(child);
        }

        for(auto& pair : graph) {
            if(children.find(pair.first) == children.end()) {
                return pair.second; 
            }
        }

        return nullptr; 
    }
};