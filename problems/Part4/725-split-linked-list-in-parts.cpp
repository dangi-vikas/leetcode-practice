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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        int length = 0;
        ListNode* iter = head;
        
        while(iter) {
            length++;
            iter = iter->next;
        }
        
        int partLength = length / k;
        int distribute = length % k;
        ListNode* node = head;
        ListNode* prev = NULL;
        int i = 0;
        
        while(node && i < k) {
            ans[i] = node;
            
            for(int j=0; j<partLength+((distribute>0)?1:0); j++) {
                prev = node;
                node = node->next;
            }
            
            prev->next = NULL;
            i++;
            distribute--;
        }
        
        return ans;
    }
};
