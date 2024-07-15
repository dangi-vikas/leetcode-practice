/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        
        ListNode* fast=head, *slow=head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            //when cycle is detected 
            if(slow == fast) break;
        }
        
        //if a null pointer is encountered; this implies that no cycle is present
        if(!fast || !fast->next) return nullptr;
                
        fast = head;
        
        //when fast and slow collide, it is a point of cycle start
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    }
}; 