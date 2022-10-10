class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        
        for(int i : pushed) {
            st.push(i);
            
            while(!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        
        return j == popped.size();
    }
};