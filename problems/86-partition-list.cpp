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
    ListNode* partition(ListNode* head, int x) {
        
        //if none or only 1 node is present
        if(!head || !head->next) return head;
        
        ListNode* small = new ListNode(0);
        ListNode* great = new ListNode(0);
        
        ListNode* p = small;
        ListNode* q = great;
        
        //traversing through the list
        while(head){

            //if the val of node is less than target
            if(head->val < x){

                //adding the node to the small list
                p->next = head;
                p = p->next;
            }
            
            else{

                //else, adding the node to the great list
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        
        //connecting both the lists
        q->next = nullptr;
        p->next = great->next;
        
        return small->next;
    }
};