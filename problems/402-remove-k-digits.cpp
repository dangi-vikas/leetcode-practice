class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        
        for(auto c : num){
            while(!st.empty() && k && st.top() > c){
                st.pop(); k--;
            }
            
            if(!st.empty() || c != '0')
                st.push(c);
        }
        
        while(!st.empty() && k--) st.pop();
        
        if(st.empty()) return "0";
        
        while(!st.empty()){
            num[n-1] = st.top();
            st.pop(); n--;
        }
        
        return num.substr(n);
    }
};