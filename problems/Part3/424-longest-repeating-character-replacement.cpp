class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> counts(26, 0);
        
        int i = 0;
        int maxLength=0, maxCount=0;
        
        for(int j=0; j<n; j++){
            counts[s[j] - 'A']++;
            int currCount = counts[s[j] - 'A'];
            maxCount = max(maxCount, currCount);
            
            while((j - i + 1) - maxCount > k){
                counts[s[i] - 'A']--;
                i++;
            }
            
            maxLength = max(maxLength, (j-i+1));
        }
        
        return maxLength;
    }
};