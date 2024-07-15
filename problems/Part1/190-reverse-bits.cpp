class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0; 

        for(int i=0; i<32; i++){
            
            //the last bit if 1 adding it to the ans
            if(n & 1) ans |= 1;
            
            if(i != 31){
                
                //forming the reverse number
                ans <<= 1;

                //for shifting to the next bit of n
                n >>= 1;
            }
        } 
        
        return ans;
    }
};