class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remainByte = 0;
        
        for(auto val : data){
            if(remainByte == 0){
                if((val>>7) == 0b0) remainByte = 0;
                
                else if((val>>5) == 0b110)
                    remainByte = 1;
                
                else if((val>>4) == 0b1110)
                    remainByte = 2;
                
                else if((val>>3) == 0b11110)
                    remainByte = 3;
                else 
                    return false;
            }
            
            else{
                if((val>>6) == 0b10) remainByte --;
                else return false;
            }
        }
        
        if(remainByte) return false;
        
        return true;
    }
};