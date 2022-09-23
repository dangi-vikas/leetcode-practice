class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;
        int lastWeight = 0;
        
        for(int stone : stones) pq.push(stone);
        
        while(pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            
            int second = pq.top();
            pq.pop();
            
            if(first == second && pq.size() == 0) return 0;
            
            if(first < second || second < first) 
                pq.push(abs(first-second));
        }
        
        return pq.top();
    }
};