class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0, end = 0, maxFruits = 0;
        unordered_map<int, int> lastSeen;
        
        while(end < fruits.size()) {
            lastSeen[fruits[end]]++;
            
            if(lastSeen.size() >= 3) {
                lastSeen[fruits[start]]--;
                
                if(lastSeen[fruits[start]] == 0) 
                    lastSeen.erase(fruits[start]);
                 
                start++;
            }
            
            end++;
        }
         
        return end - start;
    }
};