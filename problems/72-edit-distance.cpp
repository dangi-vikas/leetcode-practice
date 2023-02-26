class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        for(int i=0; i<m+1; i++) prev[i] = i;
                                  
        for(int i=1; i<n+1; i++) {
            curr[0] = i; 
            
            for(int j=1; j<m+1; j++){
                if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                
                else curr[j] = 1 + min(prev[j] , min(curr[j-1], prev[j-1]));
            } 
            
            prev = curr;
        }
        
        return prev[m];
    }
};