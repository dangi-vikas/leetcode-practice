class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        
        while(x) {
            int rem = x % 10;                            // getting the last digit
            x /= 10;                                     // moving to penultimate digit
            
            //To keep the answer in signed 32-bit integer range [-2^31, (2^31)-1]
            if (reverse > INT_MAX/10 || (reverse == INT_MAX/10 && rem > 7)) return 0;
            if (reverse < INT_MIN/10 || (reverse == INT_MIN/10 && rem < -8)) return 0;
            
            reverse = reverse * 10 + rem;                //adding the last digit to reverse by multiplying it with 10 to its forward place 
        }
        
        return reverse;
    }
}; 
   