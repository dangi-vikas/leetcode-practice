class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        
        for (int i=0; i<s.length(); i++)
            ans ^= s[i] ^ t[i];

        return ans ^ t[(t.length())-1];
    }
};