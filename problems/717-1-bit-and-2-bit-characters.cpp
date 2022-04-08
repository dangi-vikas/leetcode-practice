class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        
        while(i < n) {
            if(bits[i] == 0) i++;
            if(i == n) return true;
            if(bits[i] == 1) i+=2;
        }
        
        return false;
    }
};