class Solution {
public:
    int countBinarySubstrings(string s) {
        int count=0, i=1, prev=0, curr=1;
        
        while(i<s.length()) {
            if(s[i-1] != s[i]) {
                count += min(prev, curr);
                prev = curr;
                curr = 1;
            }
            
            else curr++;
            
            i++;
        }
        
        return count += min(prev, curr);
    }
};