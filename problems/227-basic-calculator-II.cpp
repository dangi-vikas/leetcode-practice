class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        stack<int> st;
        long long num=0;
        char op='+';
        
        for(int i=0;i<n;i++)
        {
            char c=s[i];

            if(isdigit(c))
                num=num*10+c-'0';

            if((!isdigit(c) && c!=' ') || i==n-1){
                if(op=='+' || op=='-'){
                    if(op=='+')
                    st.push(num);
                    else
                        st.push(-num);
                }

                else if(op=='*' || op=='/'){
                    int t=st.top();
                    st.pop();
                    if(op=='*')
                        st.push(t*num);
                    else
                        st.push(t/num);
                }
                op=c;
                num=0;
            }
        }

        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        return ans;
    }
};