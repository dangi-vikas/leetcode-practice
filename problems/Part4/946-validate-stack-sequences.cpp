class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;

        for(; i<pushed.size(); i++) {
            st.push(pushed[i]);
            
            while(!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }  
        }

        return st.empty();
    }
};