/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* curr = p;
        
        //starting the iteration from a node before the head
        while(curr->next){

            //if node's next has value equal to val
            if(curr->next->val == val) 

                //changing the next pointer of the node to node's second next
                curr->next = curr->next->next;  

            else
                curr = curr->next;
        }
        
        return p->next;
    }
};