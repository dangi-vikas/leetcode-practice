class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        long long val = n ;
        vector<int> digits;
        
        do {
          digits.push_back(val%10);
          val /= 10;
        } while(val); 
         
        reverse(digits.begin(), digits.end());
        
        for(int i=digits.size()-1; i>0; i--) {
            if(digits[i] < digits[i-1]) {
                int j=i ;
                
                while(j < digits.size()) {
                    digits[j] = 9 ;
                    j++;
                }
                
                digits[i-1]-- ;
            }    
        }
        
        for(int i : digits) {
            val += i ;
            val *= 10 ;
        }
         
        return val/10 ;
    }
};