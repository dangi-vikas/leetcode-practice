class Solution {
public:
    int appendCharacters(string s, string t) {
        int sSize = s.size(), tSize = t.size();
        int i = 0, j = 0;
        
        for(i=0; i<sSize; i++) {
            if(s[i] == t[j]) {
                j++;
            }
        }
        
        return tSize - j;
    }
};
