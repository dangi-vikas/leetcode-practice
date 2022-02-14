class Solution {
public:
    bool checkRecord(string s) {
        if(s.find("LLL") != -1) return false;
        int absent = 0;
        
        for(char c : s)
           if(c == 'A') absent++;     
      
        return absent<2;   
    }
}
