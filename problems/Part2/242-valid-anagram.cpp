class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
    
        vector<int> count(26, 0);

        for(int i=0; i<s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        /*if the count of a character is equal it second
          in count map will be zero*/
        for(int i=0; i<26; i++) 
            if(count[i] != 0) return false;

        return true; 
    }
};
