class Solution {
    #define ll long long int

public:
    bool isPerfectSquare(int num) {
        ll low=1, high=num, mid;
        
        if(num==1) return true;
        
        while(high-low > 1){
            mid = low + ((high-low)>>1);
            
            if(mid*mid < num) low = mid;
            else high = mid;
        }
        
        if( low * low == num || high * high == num) return true;
        
        return false;
    }
};