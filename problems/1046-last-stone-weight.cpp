class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int stone : stones) pq.push(stone);

        while(!pq.empty()) {
            int max = pq.top();
            pq.pop();

            if(pq.size() == 0) return max;
            
            int secondMax = pq.top();
            pq.pop();

            cout<<max<<secondMax;

            if(max != secondMax) pq.push(max - secondMax);
        }

        return 0;
    }
};