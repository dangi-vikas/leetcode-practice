class Solution {
public:
    bool judgeSquareSum(int c) {
        long low = 0, high = sqrt(c);
        
        while(low <= high) {
            long total = (high * high) + (low * low);
            
            if(total == c) return true;
            else if(total < c) low++;
            else high--;
        }
        
        return false;
    }
};
