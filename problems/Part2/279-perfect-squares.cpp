//Legendre's 3-square theorem approach

class Solution {
public:
    int numSquares(int n) {

        //if n itself is a perfect square
        if(ceil(sqrt(n)) == floor(sqrt(n)))
            return 1;
        
        //check if n is in form of (8b+7)
        while(n%4 == 0) n/=4;
        if(n%8 == 7) 
            return 4;
        
        //if the number can be split in sum of squares of two perfect squares
        for(int i=1; i*i<=n; i++){
            int temp = sqrt(n-i*i);
            if(temp*temp == (n-i*i))
               return 2;
        }
               
        return 3;
    }
};