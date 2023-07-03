class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;      
        vector<int> alp(26, 0);
        
        for(auto c : goal) alp[c - 97] = 1;
       
        for(auto c : s) 
            if (alp[c - 97] == 0) return false;
        
        if (s == goal) {
            for(auto c : s){
                 if (count(s.begin(), s.end(), c) >= 2)
                    return true;
            }

            return false;
        }
        
        int ptr = -1;
        bool t = false;
        
        for(int i=0; i<s.size(); i++) {
            if (s[i] != goal[i]) {
                if (ptr == -1) {
                    ptr = i;
                    continue;
                }
                
                else {
                    if (s[ptr] == goal[i] && s[i] == goal[ptr]) {
                        if(t) return false;
                        
                        else {
                            swap(s[ptr], s[i]);
                            if (s != goal) return false;
                            else return true;
                        }
                    }
                    
                    else return false;
                }
            }
        }
        
        return true;
    }
};