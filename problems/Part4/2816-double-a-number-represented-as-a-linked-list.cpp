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
    ListNode* doubleIt(ListNode* head) {
        stack<int> s;
        
        while(head) {
            s.push(head->val);
            head = head->next;
        }
        
        ListNode* tail = nullptr;
        int res = 0;

        while(!s.empty() || res != 0) {
            tail = new ListNode(0, tail);

            if(!s.empty()) {
                res += s.top() * 2; 
                s.pop();  
            }
            
            tail->val = res % 10;     
            res /= 10; 
        }

        return tail;
    }
}
