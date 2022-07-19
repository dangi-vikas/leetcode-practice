class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        int sign = 1;
        long long ans = 0, curr = 0;
        stack<int> st;
        
        for(int i=0; i<len; i++) {
            if(isdigit(s[i])) {
                curr = s[i] - '0';
                
                while(i+1 < len && isdigit(s[i+1])) {
                    curr = curr * 10 + s[i+1] - '0';
                    i++;
                }
                
                curr = curr * sign;
                ans += curr;
                curr = 0;
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
                int prevSign = st.top();
                st.pop();
                
                ans *= prevSign;
                
                int prevAns = st.top();
                st.pop();
                
                ans += prevAns;
            }
        }
        
        return ans;
    }
};