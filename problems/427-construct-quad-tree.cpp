/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructRec(grid, 0, grid.size(), 0, grid[0].size());
    }
    
    Node* constructRec(vector<vector<int>> &grid, int rs, int re, int cs, int ce) {
        if(rs >= re || cs >= ce) return nullptr;
        
        int val = grid[rs][cs];
        int i = 0, j = 0;
        
        for(i = rs; i < re; ++i) {
            for(j = cs; j < ce; ++j) 
                if(grid[i][j] != val) break;
            
            if(j < ce) break;
        }
        
        if(i == re && j == ce) return new Node(val, true);
        
        int rm = rs + (re-rs) / 2, cm = cs + (ce-cs) / 2;
        
        Node *topLeft = constructRec(grid, rs, rm, cs, cm);
        Node *topRight = constructRec(grid, rs, rm, cm, ce);
        Node *bottomLeft = constructRec(grid, rm, re, cs, cm);
        Node *bottomRight = constructRec(grid, rm, re, cm, ce);
        
        return new Node(val, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};