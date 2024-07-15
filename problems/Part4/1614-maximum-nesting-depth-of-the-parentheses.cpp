class Solution {
public:
    int maxDepth(string s) {
        int count = 0, mx = 0;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') count++;
            mx = max(count, mx);
            if(s[i] == ')') count--;
        }
        
        return mx;
    }
};
