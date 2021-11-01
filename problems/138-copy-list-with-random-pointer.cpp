/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head, *front = head;

        /*first round: make copy of each node and link them together 
          side-by-side in a single list*/
        while (iter) {
            front = iter->next;

            Node *newNode = new Node(iter->val);
            iter->next = newNode;
            newNode->next = front;

            iter = front;
        }

        iter = head;

        //second round: assign random pointers to the copied nodes.
        while (iter) {
            if (iter->random)
                iter->next->random = iter->random->next;
                
            iter = iter->next->next;
        }

        iter = head;
        Node *temp = new Node(0);
        Node *newNode = temp;

         //third round: restore the original list; and extract the copied list.
        while (iter) {
            front = iter->next->next;

            newNode->next = iter->next;                  // extract the copy
            iter->next = front;                         // restore the original list
                
            newNode = newNode -> next; 
            iter = front;
        }

        return temp->next;
    }
};