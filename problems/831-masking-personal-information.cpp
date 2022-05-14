class Solution {
public:
    string maskPII(string s) {
        if(s.find('@') != string::npos) {
            transform(s.begin(), s.end(), s.begin(), :: tolower);
            
            int pos = s.find('@');
            string ans = "";
            
            ans.push_back(s[0]);
            ans += "*****";
            ans += s.substr(pos - 1);
            
            return ans;
        }
        
        string ans = tokenize(s, '-');
        vector<string> codes = { 
            "+*-",
            "+**-",
            "+***-"
        };
        
        if(ans.size() == 10) {
            string res = "***-***-";
            string end = ans.substr(ans.size() - 4);
            
            res += end;
            
            return res;
        }
        
        else {
            string res = codes[ans.size() - 11] +  "***-***-";
            string end = ans.substr(ans.size() - 4);
            
            res+=end;
            
            return res;
        }
    }
    
    string tokenize(string s, char bar) {
        string ans;
        
        for(char ch : s) 
            if(isdigit(ch)) ans.push_back(ch);
            
        
        return ans;
    }
};