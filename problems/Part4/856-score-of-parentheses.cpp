class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        stack<int> st;
        
        for(char ch : s) {
            int val = 0;
            
            if(ch == '(') st.push(0);
            
            else {
                while(st.top() != 0) {
                    val += st.top();
                    st.pop();
                }
                
                val = max(2*val, 1);
                st.pop();
                st.push(val);
            }
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};