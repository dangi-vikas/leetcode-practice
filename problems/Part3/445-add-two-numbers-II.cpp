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
        ListNode a(0), *a1 = &a;
        stack<int> s1,s2,s3;
        
        while(l1||l2){
            if(l1) s1.push(l1->val);
            if(l2) s2.push(l2->val);
            
            l1 = l1 ? l1 -> next : l1;
            l2 = l2 ? l2 -> next : l2;
        }
        
        int rem=0;
        
        while(!s1.empty() || !s2.empty() || rem){
            int sum = (!s1.empty() ? s1.top() : 0) + (!s2.empty() ? s2.top() : 0) + rem;
            
            rem = sum / 10;
            s3.push(sum % 10);

            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
        }
        
        while(!s3.empty()){
            a1->next = new ListNode(s3.top());
            a1 = a1->next;
            s3.pop();  
        }
        
        return a.next;
    }
};