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
    ListNode* deleteDuplicates(ListNode* head) {

        //if none or only 1 node is present
        if(!head || !head->next) return head;
        
        ListNode* p = head->next;

        //if the second node is duplicate of head
        if(p->val == head->val){

            //overriding the duplicate
            head = head->next;

            //doing the same procedure by considering p as new head
            return deleteDuplicates(p);
        }
        else{

            //doing the same procedure from second element by considering p as new head
            head->next = deleteDuplicates(p);
            
            return head;
        }
    }
};
