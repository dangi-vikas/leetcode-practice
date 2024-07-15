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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        head = head->next;
        
        int i = 1, mindist = INT_MAX, prevI = INT_MIN, firstI = -1;
        
        while(head->next) {
            if((prev->val < head->val && head->val > head->next->val) || (prev->val > head->val && head->val < head->next->val)) {
                if(prevI != INT_MIN) {
                    mindist = min(mindist, i - prevI);
                }
                
                if(firstI == -1) {
                    firstI = i;
                }
                
                prevI = i;
            }
            
            prev = head;
            head = head->next;
            i++;
        }
        
        if(mindist == INT_MAX) {
            return {-1, -1};
        }
        
        return {mindist, prevI - firstI};
    }
};
