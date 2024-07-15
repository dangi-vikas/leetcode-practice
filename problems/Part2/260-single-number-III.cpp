class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0, a = 0, b = 0;
        
        for(int x : nums)
            XOR ^= x;
        
        int mask = 1;
        
        for(int i=0; i<32; i++) {
            if(XOR & mask) break;
            mask <<= 1;
        }
        
        for(int x : nums) { 
            if(x & mask) a ^= x;
            else b ^= x;
        }
        
        return {a, b};
    }
};
