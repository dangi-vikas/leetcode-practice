class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int ans = 0;

        for(int pile : piles) pq.push(pile);

        while(k > 0) {
            int top = pq.top();
            pq.pop();
            top -= (top / 2);
            pq.push(top);
            k--;
        }

        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};