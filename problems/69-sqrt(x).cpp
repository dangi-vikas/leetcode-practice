class Solution {
public:
    int mySqrt(int x) {
        long long low = 1, high =x;
        int ans;
        
        //if x is 0 or 1
        if(x==0 || x==1) return x;
        
        //binary search
        while(high>=low){
            long long mid = low + ((high-low)>>1);
            
            long long square = mid*mid;
            
            if(square == x) return mid;
            if(square < x){
                ans =mid;
                low = mid+1;  
            } 
            else high = mid-1;
        }
        
        return ans;
    }
};