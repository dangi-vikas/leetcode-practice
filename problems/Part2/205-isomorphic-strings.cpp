class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, char> sMap;
        unordered_set<char> tMap;
        
        for(int i=0; i<s.size(); i++){
            char x = s[i];
            char y = t[i];
            
            //if s is being mapped to two characters in t
            if(sMap.find(x) != sMap.end()){
                if(sMap[x] != y) return false;
                else continue;  
            }

            else{

                //if two characters of t are mapped to a single character in s
                if(tMap.find(y) != tMap.end()) return false;

                //inserting the characters in containers
                sMap[x] = y;
                tMap.insert(y);
            }
        }
        
        return true;
    }
};