class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        int n=t.length(), m=s.length();
        
        if(m == 0) return true;
        
        while(j < n){
            if(s[i] == t[j]){
                i++;
                if(i == m) return true;
            }
             
            j++;
        }
        
        return false;
    }
};