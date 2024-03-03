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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //initialising a node which would point to head
        ListNode* start = new ListNode();
        start->next = head;
        
        //initialising two nodes for traversal
        ListNode* fast = start; 
        ListNode* slow = start;
        
        //moving the fast node till it reaches the nth place 
        for(int i=0; i<n; i++) fast = fast->next;
        
        /*moving the fast pointer till it reaches the last node concurrently
          with slow node which would then reach the nth node from end*/
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        //pointing the slow's next to its second next thus removing the node
        slow->next = slow->next->next;
        
        return start->next;
    }
};