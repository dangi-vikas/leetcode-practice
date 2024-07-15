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
    ListNode* rotateRight(ListNode* head, int k) {

        //if the linked is empty or has only one node
        if(!head || !head->next) return head;
        
        //initialised an iterating pointer
        ListNode* p = head;
        int len = 1;
        
        //to find the length of linked list
        while(p->next && len++) p = p->next;
        p->next = head;
        
        //finding the endpoint of the resultant list
        k = k % len; k = len-k;
        while(k--) p = p->next;
        
        //breaking the link 
        head = p->next;
        p->next = nullptr;
        
        return head;
    }
};