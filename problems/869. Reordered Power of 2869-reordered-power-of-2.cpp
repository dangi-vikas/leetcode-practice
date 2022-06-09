class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> nDigits = findDigits(n);
        int num = 1;
        
        for(int i=0; i<31; i++) {
            if(nDigits == findDigits(num)) return true;
            num = num << 1;
        }
        
        return false;
    }
    
    vector<int> findDigits(int n) {
        vector<int> digits(10);
        
        while(n) {
            digits[n%10]++;
            n /= 10;
        }
        
        return digits;
    }
};