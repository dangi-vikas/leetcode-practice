class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        
        string s = "";
        bool isNegative = false;
        
        if(num < 0){
            isNegative = true;
            num = -num;
        }
        
        while(num){
            s += char(num % 7 + '0');
            num /= 7;
        }
        
        s += isNegative ? "-" : ""; 
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};