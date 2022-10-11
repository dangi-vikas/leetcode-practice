class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> count(26);
        int ans = 0;
        
        for (auto ch : chars) count[ch - 'a']++;
        
        for (auto &word : words) {
            vector<int> tempCount(26);
            bool match = true;
            
            for (auto ch : word) {
                if (++tempCount[ch - 'a'] > count[ch - 'a']) {
                    match = false;
                    break;
                }
            }
            
            if (match) ans += word.size();
        }
        
        return ans;
    }
};