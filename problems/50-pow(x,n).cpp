class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long N = n;            //for accomodating the negative-positive conversion
        
        //taking only positive powers
        if(N<0) N = -N;
        
        while(N){

            //if the power is odd 
            if(N%2){
                ans *=  x;
                N--;
            }

            //if the power is even
            else{
                x *= x;           //multiplying with the number itself          
                N >>= 1;          //halving the power
            }
        }
        
        //in case of negative powers inverting the ans
        if(n<0) ans = (double)(1.0) /  double(ans);

        return ans;
    }
};