class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        
        for(string s : emails) {
            int pos = s.find('@'); 
            string domainName = s.substr(pos); 
            string localName = "";
            
            for(int i=0; i<pos; i++){
                if(s[i] == '+') break;
                else if(s[i] == '.') continue;
                else localName.push_back(s[i]);
            }
            
            st.insert(localName + domainName);
        }
        
        return st.size();
    }
};