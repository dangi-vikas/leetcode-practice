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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        //edge cases
        if(!head || (left == right)) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* nodeBeforeSublist = &dummy;
        int pos = 1;

        //finding the node just before the sublist
        while(pos<left) {
            nodeBeforeSublist = nodeBeforeSublist->next;
            pos++;
        }

        auto workingPtr = nodeBeforeSublist->next;

        while (left<right) {

            auto nodeExtracted = workingPtr->next;
            
            //changing the next pointers of the nodes
            workingPtr->next = nodeExtracted->next;
            nodeExtracted->next = nodeBeforeSublist->next;

            //incrementing the node before sublist
            nodeBeforeSublist->next = nodeExtracted;

            left++;
        }
        
        return dummy.next;
    }
};
