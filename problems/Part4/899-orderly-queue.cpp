class Solution {
public:
    string orderlyQueue(string s, int k) {
        int n = s.length();
        vector<string> strs;
        
        if(n == 0) return s;
        
        if(k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        
        for(int i=0; i<n; i++) {
            char ch = s[0];
            s.erase(s.begin());
            s += ch;
            strs.push_back(s);
        }
        
        sort(strs.begin(), strs.end());
        
        return strs[0];
    }
};