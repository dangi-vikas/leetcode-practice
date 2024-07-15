class Solution {
public:
    string reverseStr(string s, int k) {
        int i=0, j=2*k;
        
        while(i<s.length()) {
            if(i+k > s.length())
                reverse(s.begin()+i, s.end());
            else
                reverse(s.begin()+i, s.begin()+(i+k));
                
            i = j;
            j += 2*k;
        }
        
        return s;
    }
};