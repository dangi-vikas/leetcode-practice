/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
https://assets.leetcode.com/uploads/2021/07/22/lc-linkedlistcom2.jpg * };
 */

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> ele;
        
        for(int num : nums) ele[num]++;
        
        while(head) {
            if(ele[head->val]) {
                ans++;
                while(head && ele[head->val]) head = head->next;
                continue;
            }
            
            head = head->next;
        }
        
        return ans;
    }
};