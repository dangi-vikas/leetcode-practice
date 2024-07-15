class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        
        /*the number of multiples of five the factorial 
        expansion will contain will be number of zeroes*/
        
        while(n){
            n/=5;
            ans += n;
        }
        
        return ans;
    }
};