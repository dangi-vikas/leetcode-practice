class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int order1, order2;
          
        for (int i=1; i<words.size(); i++) { 
            for (int j=0; j<words[i-1].size() && j<words[i].size(); j++) { 
                order1 = order.find(words[i-1][j]); 
                order2 = order.find(words[i][j]); 
                
                if (order1 < order2) j = words[i-1].size();
                else if (order1 > order2) return false; 
                else if (j == words[i].size() - 1 && words[i].size() < words[i-1].size()) 
                    return false; 
            }
        }
        
        return true; 
    }
};