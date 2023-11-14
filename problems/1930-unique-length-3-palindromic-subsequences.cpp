class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        unordered_set<char> uniqueChar;

        for(char c : s) 
            uniqueChar.insert(c);
      
        for(char c : uniqueChar) {
            int start = s.find(c);
            int end = s.rfind(c);

            if(start < end) {
                unordered_set<char> charSet;

                for(int i=start+1; i<end; i++) 
                    charSet.insert(s[i]);
                
                ans += charSet.size();
            }
        }

        return ans;        
    }
};