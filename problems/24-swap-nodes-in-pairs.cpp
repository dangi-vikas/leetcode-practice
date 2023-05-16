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
    ListNode* swapPairs(ListNode* head) {

        //if linked list doesnt have sufficient node to swap
        if(!head || !head->next) return head;
        
        ListNode* p, *q;
        p = head;
        ListNode* ans;
        ans = head->next;                       //will be new head of resultant linked list
        
        while(q){

            //initialising a new node to store p's next in given linked list
            q = p->next;

            //initialising a temporary node to store the address of q's next
            ListNode* temp = q->next;

            //swaping the first two nodes
            q->next = p;
            
            //breaking condition of loop
            if(!temp || !temp->next){
                p->next = temp; break;
            }
            
            //pointing p's next to q's second next so as to swap both p and (q's next)
            p->next = temp->next;

            //moving p to next pair of nodes
            p = temp;
        }
        
        return ans;
    }
};