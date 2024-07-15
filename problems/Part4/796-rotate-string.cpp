class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        
        string temp =  s + s;
        int index =  temp.find(goal);
         
        if(index >= temp.length() - 1) return false;
        
        return true;
    }
};