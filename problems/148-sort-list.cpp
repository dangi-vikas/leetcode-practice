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

//Merge Sort Algorithm
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode *mid = middleNode(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        return mergeList(left, right);
    }
    

    //merging the sorted arrays
    ListNode* mergeList(ListNode* left, ListNode* right){
        ListNode *p = new ListNode(-1), *curr = p;
        
        while(left && right){
            if(left->val <= right->val) {
                curr->next = left;
                left = left->next;
            }
            else {
                curr->next = right;
                right = right->next;
            }
            
            curr = curr->next;
        }
        
        curr->next = left ? left : right;
        
        return p->next;
    }
    
    //finding the middle node of the list and breaking
    ListNode* middleNode(ListNode* head) {
         ListNode *slow=head, *fast=head->next;
         
         while(fast && fast->next){
             slow = slow->next;
             fast = fast->next->next;
         }
         
         ListNode *mid = slow->next;
         slow->next = nullptr;
         
         return mid;
     }
};