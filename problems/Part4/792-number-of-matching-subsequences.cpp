class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charIndex(26, vector<int>(0));
        int ans = 0;
        
        for (int i=0; i<s.length(); i++) 
            charIndex[(s[i]-'a')].push_back(i);
        
        for (auto word : words) {
            int i = 0, prev = -1;
            
            while (i < word.length()) {
                int curr = word[i] - 'a';
                auto itr = upper_bound(charIndex[curr].begin(), charIndex[curr].end(), prev);
                
                if (itr == charIndex[curr].end()) break;
                prev = *itr;
                
                i++;
            }
            
            if (i == word.length()) ans++;
        }
        
        return ans;
    }
};