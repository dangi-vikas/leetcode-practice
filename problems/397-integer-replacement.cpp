class Solution {
public:
    int integerReplacement(int x) {
        int count = 0;
        long long n = x;
        
        while(n > 1){
            if (n%2 == 0) n /= 2;
            
            else {
                if(((n-1) & (n-2)) == 0) n = n-1;
                else if(((n+1) & n) == 0) n = n+1;
                else if(((n-1)/2) % 2 == 0) n = n-1;
                else if(((n+1)/2) % 2 == 0) n = n+1;
                else n = n-1;
            }
            
            count++;
        }
        
        return count;
    }
};