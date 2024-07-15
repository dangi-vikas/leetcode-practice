class Solution {
public:
    bool hasAlternatingBits(int n) {
        int k = n & 1;
        n >>= 1;
        
        while(n) {           
            if((n&1) == k) return false;
            k = n & 1;
            n >>= 1;
        }
        
        return true;
    }
};