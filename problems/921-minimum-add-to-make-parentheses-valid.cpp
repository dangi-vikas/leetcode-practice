class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(')
                st.push('(');
            
            else {
                if(st.empty()) count++;
                else st.pop();
            }
        }
        
        count += st.size();
        
        return count;
    }
};