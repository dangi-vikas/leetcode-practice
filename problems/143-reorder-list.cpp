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
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head;
        
        //finding the middle node
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *prev = nullptr, *curr = slow, *temp;
        
        //reversing the later half of the list
        while(curr) {
            temp = curr->next;
            curr->next =  prev;
            prev = curr;
            curr = temp;
        }
        
        ListNode *n1 = head, *n2 = prev;
        
        //placing the node in required position
        while(n2->next) {
            temp  = n1->next;
            n1->next = n2;
            n1 = temp;
            
            temp = n2->next;
            n2->next = n1;
            n2 = temp; 
        }
    }
};
