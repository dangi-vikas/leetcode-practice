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
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf)
            return quadTree1->val ? quadTree1 : quadTree2;
        
        if(quadTree2->isLeaf) 
            return quadTree2->val ? quadTree2 : quadTree1;
       
        Node *node, *tl, *tr, *bl, *br;
        
        tl = intersect (quadTree1->topLeft, quadTree2->topLeft);
        tr = intersect (quadTree1->topRight, quadTree2->topRight);
        bl = intersect (quadTree1->bottomLeft, quadTree2->bottomLeft);
        br = intersect (quadTree1->bottomRight, quadTree2->bottomRight);
        
        if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && tl->val==tr->val && tr->val==bl->val && bl->val==br->val) 
            node = new Node(true, true);
        
        else  node = new Node(false, false, tl, tr, bl, br);
        
        return node;
    }
};