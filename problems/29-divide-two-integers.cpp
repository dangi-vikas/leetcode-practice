class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res = 0;

        //taking the unsigned value of the two integers
        long long a = abs(dividend);
        long long b = abs(divisor);
        
        while(a-b>=0){
            long long s=b , temp=1;
            
            //runs till (powers of two) of divisor is less than dividend
            while((s<<1)<a) 
            {   
                //doubling the divisor
                //getting the times the dividend is divisible to the (powers of two) of divisor
                s<<=1; temp<<=1;
            }
            
            //updating the quotient
            res +=temp;

            //decrementing the leftout remainder on division with (powers of two) of divisor
            //and then again checking 
            a -=s;
        }
        
        //if signs of dividend and divisor are different changing the sign of quotient
        if((dividend>0)^(divisor>0)) res = -res;
        
        //in case of overflow from 32-bit signed integer range: [−2^31, (2^31 − 1)]
        return res > 0 ? (res > INT_MAX ? INT_MAX : res) : (res < INT_MIN ? INT_MIN : res);
    }
};