class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length(), m = b.length();
        int l = m%n == 0 ? m/n : m/n+1;
        string h;
        
        for(int i=0; i<l; i++) h += a;
        
        if(h.find(b) != -1) return l;
        
        h += a;
        
        if(h.find(b) != -1) return l+1;
        
        return -1;
    }
};