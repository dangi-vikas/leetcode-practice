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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *start = new ListNode();
        start->next = head;
        
        ListNode *curr=head, *prev=start;

        while(curr){

            //if the current node's next is smaller than current node
            if(curr->next && (curr->next->val < curr->val)){
                
                //placing current's next before the element with greater value

                while(prev->next && (prev->next->val < curr->next->val))
                    prev = prev->next;
                
                ListNode *temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                
                prev = start;
            }
            
            else curr = curr->next;
        }
        
        return start->next;
    }
};