class Solution {
public:
    int countSubstrings(string s) {
        if(s.length() == 0) return 0;
        
        int n = s.length(); 
        int ans = 0; 
        
        for(int i=0; i<n; i++) {
            ans += isPalindrome(i, i, s);
            ans += isPalindrome(i, i+1, s);
        }
        
        return ans;
    }
    
    int isPalindrome(int start, int end, string& s) {
        int count = 0;
            
        while(start>=0 && end<s.length() && s[start--] == s[end++])
            count++;
        
        return count;
    }
};