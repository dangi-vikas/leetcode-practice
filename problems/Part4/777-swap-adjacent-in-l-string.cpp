class Solution {
public:
    bool canTransform(string start, string end) {
        int len = start.length();
        int i=0, j=0;
      
        while(i<len && j<len){
            while(start[i] == 'X') i++;
            while(end[j] == 'X') j++;
            
            if(start[i] != end[j]) return false;
            if(start[i] == 'R' && j < i) return false;
            if(start[i] == 'L' && j > i) return false;
            
            i++; j++;
        }
        
        while(i < len && start[i] == 'X') i++; 
        while(j < len && end[j] == 'X') j++;
        
        if(i < len || j < len) return false;
        
        return true;
    }
};