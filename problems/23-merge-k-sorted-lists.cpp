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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        
        int interval = 1;
        
        while(interval<lists.size()) {
            for(int i=0; i+interval<lists.size(); i+=interval*2)
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
            
            interval *= 2;
        }
        
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(!head1 && !head2) return nullptr;

        if(!head1) return head2;
        if(!head2) return head1;

        ListNode* node = nullptr;

        if(head1->val < head2->val) {
            node = head1;
            node->next = mergeTwoLists(head1->next, head2);
        }

        else {
            node = head2;
            node->next = mergeTwoLists(head1, head2->next);
        }

        return node;
    }
};