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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node = new ListNode;                      //initialising a dummy node
        ListNode* temp = node;          
        int carry = 0; 
        
        while(l1 || l2 || carry){                           //runs till all of l1, l2 and carry is equal to null
            int sum = 0;
            
            if(l1){
                sum+= l1->val;                              //adding from first linked list if its node exists
                l1 = l1->next;
            }
            
            if(l2){
                 sum+= l2->val;                             //adding from second linked list if its node exists
                 l2 = l2->next;
            }
            
            sum += carry;                                   //adding the carried number
            carry = sum/10;                                 //resetting the carried number after adding
            
            //creating a new node for storing the sum
            ListNode* result = new ListNode(sum%10);
            temp->next = result;
            temp = temp->next;
        }
         return node->next;   
    }
};

