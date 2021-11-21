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
    bool isPalindrome(ListNode* head) {
        string sum="";
        
        while(head){
            string s=to_string(head->val);
            sum+=s;
            head=head->next;
        }
        
        string s=sum;
        reverse(s.begin(),s.end());
        
        if(s==sum) return true;
        return false;
    }
};