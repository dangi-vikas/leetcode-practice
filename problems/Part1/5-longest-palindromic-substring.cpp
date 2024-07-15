class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, len = 0, len1 = 0, len2 = 0;
        int left = 0, right = 0;

        for(int i=0; i<s.length(); i++) {
            len1 = palindromeLength(s, i, i);
            len2 = palindromeLength(s, i, i+1);

            len = max(len1, len2);

            if(len > maxLen) {
                maxLen = len;
                left = i - (len-1) / 2;
                right = i + len / 2;
            }
        }
        return s.substr(left, maxLen);
    }
    
    int palindromeLength(string s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;            
        }

        return right - left - 1;
    }
};