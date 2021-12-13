class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        
        int ans=10;
        
        for(int i=2; i<=n; i++){
            int x=9, y=9;
            int count = i-1;
            
            while(count){
                x *= y;
                y--; count--;
            }
            
            ans += x;
        }
        
        return ans;
    }
};