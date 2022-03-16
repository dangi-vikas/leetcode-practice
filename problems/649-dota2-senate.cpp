class Solution {
public:
    string predictPartyVictory(string senate) {
        char p;
        int c = 0;

        while(true) {
            string t = ""; 

            for(auto ch: senate) {
                if(c == 0){
                    p = ch;
                    c++;
                    t.push_back(ch);
                } 
            
                else if(ch == p) {
                    c++;
                    t.push_back(ch);
                } 
            
                else c--;
            }

            senate.clear();
          
            int i = 0;
            while(i != t.size() && c) {
                if(t[i++] == p) senate.push_back(p);
                else c--;
            } 
            

            if(c > 0) return p == 'R' ? "Radiant" : "Dire";
            senate += t.substr(i, t.size());
        }   

        return "";
    }
};