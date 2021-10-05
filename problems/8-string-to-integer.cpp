class Solution {
public:
    int myAtoi(string s) {
        //checking for null string
        if(s.length() == 0){
            return 0;
        }
        
        //removing prior whitespaces
        int i = 0;
        while(s[i] == ' '){
            i++;
        }
        
        //checking whether the given string is positive or negative
        bool isPositive = true;
        if(s[i] == '-' || s[i] == '+'){
            isPositive = (s[i] == '+' ? true : false);
            i++;
        }
        
        //checking if the character in a string is a number
        if(s[i] - '0' < 0 || s[i] - '0' > 9){
            return 0;
        }
        
        int integer = 0;
        
        while(s[i] >= '0' && s[i] <= '9'){
            //If the integer is out of the 32-bit signed integer range [-231, 231-1]
            if(integer > INT_MAX/10 || (integer == INT_MAX/10 && s[i] - '0' > 7)){
                return isPositive ? INT_MAX : INT_MIN;
            }
 
            integer = integer*10 + (s[i] - '0');
            i++;
       }   
        
       return isPositive ? integer : integer*(-1);
    }
};