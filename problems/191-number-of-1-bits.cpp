class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        for(int i=0; i<32; i++) {

            //if the bit is one increment the count
            if(n & 1) count++;

            //shifting left
            n >>= 1;
        }
        
        return count;
    }
};