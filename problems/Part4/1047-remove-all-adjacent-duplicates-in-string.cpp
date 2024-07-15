class Solution {
public:
    string removeDuplicates(string s) {
        string st = "";
        int i = 0;
        
        while(i < s.length()) {
            if(!st.empty() && s[i] == st[st.size()-1]) 
                st.pop_back();
                
            else st.push_back(s[i]);
            
            i++;
        }
        
        return st;
    }
};



