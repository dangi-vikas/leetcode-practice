class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "", temp = "";
        unordered_map<int, int> decimal;

        //base cases

        if(!numerator) return "0";

        if((numerator>0 && denominator<0) || (numerator<0 && denominator>0)) 
            temp += '-';

        long n = abs(numerator);
        long d = abs(denominator);

        ans += to_string(n/d);
        n %= d;

        //appending the numbers after the decimal
        if(n){
            ans += '.';
            while (n && decimal.find(n) == decimal.end()){
                decimal[n] = ans.size();
                n *= 10;
                ans += to_string(n/d);
                n %=d;
            }

            //for recurring number
            if(n)
                ans = ans.substr(0, decimal[n]) + "(" + ans.substr(decimal[n]) + ")";
        }

        return temp + ans;
    }
};