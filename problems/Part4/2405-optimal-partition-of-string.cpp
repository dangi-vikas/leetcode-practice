class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> charFreq;
        int i = 0, j = 0;
        int ans = 1;

        while(j < s.length()) {
            if(charFreq.find(s[j]) != charFreq.end()) {
                i = j;
                charFreq.clear();
                ans++;
            }

            else {
                charFreq[s[j]]++;
                j++;
            }
        }

        return ans;
    }
};