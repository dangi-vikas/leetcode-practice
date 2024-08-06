class Solution {
public:
    int minimumPushes(string word) {
        vector<int> letterFreq(26, 0);
        int totalPresses = 0;

        for(char ch : word) {
            letterFreq[ch - 'a']++;
        }
        
        sort(letterFreq.rbegin(), letterFreq.rend());
        
        for(int i=0; i<26; i++) {
            if(letterFreq[i] == 0) break;
            totalPresses += (i / 8 + 1) * letterFreq[i];
        }
        
        return totalPresses;
    }
};