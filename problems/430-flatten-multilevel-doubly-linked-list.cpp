/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head) flattenRec(head);
        return head;
    }
    
    Node* flattenRec(Node* head){
        Node *curr=head, *tail=head;
        
        while(curr){
            Node *child = curr->child;
            Node *next = curr->next;
            
            if(child){
                Node* tailTemp = flattenRec(child);
                
                tailTemp->next = next;
                if(next) next->prev = tailTemp;
                
                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
                    
                curr = tail;
            }
            
            else curr = next;
            
            if(curr) tail = curr;
        }   
        
        return tail;
    }
};