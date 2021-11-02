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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        
        ListNode* fast=head, *slow=head;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            
            //if there exist a cycle at some point fast and slow will concide
            if(slow == fast) return true;
        }
        
        return false;
    }
};