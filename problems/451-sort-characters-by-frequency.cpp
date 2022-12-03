class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char, int> counts;
        priority_queue<pair<int, char>> pq;
        
        for(int i=0; i<s.length(); i++) counts[s[i]]++;
        
        for(auto it=counts.begin(); it!=counts.end(); it++) 
            pq.push({it->second, it->first});
        
        while(!pq.empty()) {
            auto [count, letter] = pq.top();
            pq.pop();
            
            while(count > 0) {
                ans += letter;
                count--;
            }
        }
        
        return ans;
    }
};