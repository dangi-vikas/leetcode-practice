class Solution {
public:
    string removeOuterParentheses(string s) {
        int j = 0;
        string ans = "";
        
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 41) j--;
            if(j != 0) ans += s[i];
            if(s[i] == 40) j++;
        }
        
        return ans;
    }
};