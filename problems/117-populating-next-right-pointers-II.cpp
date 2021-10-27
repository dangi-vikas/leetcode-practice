/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* p = root;
        
        //traversing the tree
        while (p)
        {
            Node* q = p;
            p = nullptr;
            Node* r = nullptr;

            for (; q!=nullptr; q=q->next)
            {
                //assigning the next level wise
                if (q->left){
                    if (!r){
                        p = q->left;
                        r = p;
                    }
                    else{
                        r->next = q->left;
                        r = r->next;
                    }
                }
                
                if (q->right){
                    if (!r){
                        p = q->right;
                        r = p;
                    }
                    else{
                        r->next = q->right;
                        r = r->next;
                    }
                }
            }
        }
        
        return root;
    }
};