class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        int ans = 0;
        int sign = 1, n = 0;
        stack<int> st;
        
        for(int i=0; i<len; i++) {
            if(isdigit(s[i])) {
                n = s[i] - '0';
                
                while(i+1 < len && isdigit(s[i+1])) {
                    n = n * 10 + s[i+1] - '0';
                    i++;
                }
                
                n *= sign;
                ans += n;
                n = 0;
            }
            
            else if(s[i] == '+') sign = 1;
            else if(s[i] == '-') sign = -1;
            
            else if(s[i] == '(') {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            
            else if(s[i] == ')') {
                int signBefore = st.top();
                st.pop();
                int prevAns = st.top();
                st.pop();
                
                ans *= signBefore;
                ans += prevAns; 
            }
        }
        
        return ans;
    }
};